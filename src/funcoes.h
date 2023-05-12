#include <Arduino.h>
#include <DC-Motor-Arduino.h>

#include <motor.h>
#include <sen_dist.h>
#include <sen_linha.h>

void frente();
void tras();
void parar();
void esq_frente_dir_tras();
void esq_tras_dir_frente();
void desviar_linha();
void rotina_ataque();

void desviar_linha() {
  Serial.write(digitalRead(SEN_DIST_DIR));
  Serial.write("     ");
  Serial.write(digitalRead(SEN_DIST_ESQ));
  if ((digitalRead(SEN_LINHA_ESQ) == LOW) &&
      (digitalRead(SEN_LINHA_DIR) == HIGH)) {
    esq_frente_dir_tras();
  } else if ((digitalRead(SEN_LINHA_DIR) == LOW) &&
             (digitalRead(SEN_LINHA_ESQ) == HIGH)) {
    esq_tras_dir_frente();
  } else if ((digitalRead(SEN_LINHA_ESQ) == LOW) &&
             (digitalRead(SEN_LINHA_DIR) == LOW)) {
    tras();
    esq_frente_dir_tras();
    // talvez aleatorizar?
  }
}

void rotina_ataque() {
  if (analogRead(SEN_DIST_ESQ) < analogRead(SEN_DIST_DIR)) {
    esq_frente_dir_tras();
  } else if (analogRead(SEN_DIST_ESQ) > analogRead(SEN_DIST_DIR)) {
    esq_tras_dir_frente();
  } else if (analogRead(SEN_DIST_ESQ) == analogRead(SEN_DIST_DIR)) {
    esq_tras_dir_frente();
    // ataque direita ou esquerda (?)
  }
}

void frente() {
  digitalWrite(MOTOR_ESQ_1, HIGH);
  digitalWrite(MOTOR_ESQ_2, LOW);
  analogWrite(MOTOR_ESQ_PWN, 255);

  digitalWrite(MOTOR_DIR_1, HIGH);
  digitalWrite(MOTOR_DIR_2, LOW);
  analogWrite(MOTOR_DIR_PWN, 255);

  delay(2000);

  Serial.write("frente");
}

void tras() {
  digitalWrite(MOTOR_ESQ_1, LOW);
  digitalWrite(MOTOR_ESQ_2, HIGH);
  analogWrite(MOTOR_ESQ_PWN, 255);

  digitalWrite(MOTOR_DIR_1, LOW);
  digitalWrite(MOTOR_DIR_2, HIGH);
  analogWrite(MOTOR_DIR_PWN, 255);

  delay(2000);

  Serial.write("\ntras");
}

void parar() {
  digitalWrite(MOTOR_ESQ_1, LOW);
  digitalWrite(MOTOR_ESQ_2, LOW);
  analogWrite(MOTOR_ESQ_PWN, 0);

  digitalWrite(MOTOR_DIR_1, HIGH);
  digitalWrite(MOTOR_DIR_2, HIGH);
  analogWrite(MOTOR_DIR_PWN, 0);
}

void esq_frente_dir_tras() {
  digitalWrite(MOTOR_ESQ_1, HIGH);
  digitalWrite(MOTOR_ESQ_2, LOW);
  analogWrite(MOTOR_ESQ_PWN, 255);

  digitalWrite(MOTOR_DIR_1, LOW);
  digitalWrite(MOTOR_DIR_2, HIGH);
  analogWrite(MOTOR_DIR_PWN, 255);
  delay(2000);

  Serial.write("\nesq_frente_dir_tras");
}

void esq_tras_dir_frente() {
  digitalWrite(MOTOR_ESQ_1, LOW);
  digitalWrite(MOTOR_ESQ_2, HIGH);
  analogWrite(MOTOR_ESQ_PWN, 255);

  digitalWrite(MOTOR_DIR_1, HIGH);
  digitalWrite(MOTOR_DIR_2, LOW);
  analogWrite(MOTOR_DIR_PWN, 255);
  delay(2000);

  Serial.write("\nesq_tras_dir_frente");
}