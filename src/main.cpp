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
  if (sen_infra() == 1) {
    digitalWrite(STBY, HIGH);
  } else if (sen_infra() == 2) {
    // ler sensores de distância
    if (inimigo() == true) {
      rotina_ataque();
      while (inimigo() == true) {
        frente();
      }
    } else {
      while (inimigo() == false) {
        // ler sensores de linha
        if (detec_linha() == true) {
          while (detec_linha() == true) {
            desviar_linha();
          }
        }
        frente();
      }
    }
  } else if (sen_infra() == 3) {
    parar();
    digitalWrite(STBY, LOW);
  }
}
