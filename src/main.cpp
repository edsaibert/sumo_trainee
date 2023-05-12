#include <Arduino.h>
#include <funcoes.h>
#include <infra.h>

void setup() {
  infra_setup();
  motor_setup();
  sen_dist_setup();
  sen_linha_setup();

  Serial.begin(9600);
}

void loop() {
  digitalWrite(STBY, HIGH);
  frente();
  parar();

  delay(500);

  Serial.print("Sensor distância esquerdo: ");
  Serial.println(analogRead(SEN_DIST_ESQ));

  delay(500);

  Serial.print("Sensor distância direito: ");
  Serial.println(analogRead(SEN_DIST_DIR));

  delay(500);

  Serial.print("Sensor de linha esquerdo: ");
  Serial.println(digitalRead(SEN_LINHA_ESQ));

  delay(500);

  Serial.print("Sensor de linha direito: ");
  Serial.println(digitalRead(SEN_LINHA_DIR));

  delay(500);
  // if (sen_infra() == 1) {
  //  digitalWrite(STBY, HIGH);
  //}
  // else if (sen_infra() == 2) {
  //   // ler sensores de distância
  //   if (inimigo() == true) {
  //     rotina_ataque();
  //     while (inimigo() == true) {
  //       frente();
  //     }
  //   } else {
  //     while (inimigo() == false) {
  //       // ler sensores de linha
  //       if (detec_linha() == true) {
  //         while (detec_linha() == true) {
  //           desviar_linha();
  //         }
  //       }
  //       frente();
  //     }
  //   }
  // } else if (sen_infra() == 3) {
  //   parar();
  //   digitalWrite(STBY, LOW);
  // }
}
