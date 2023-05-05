#include <Arduino.h>
#include <infra.h>
#include <funcoes.h>

#define INTERRUPTOR 8


void setup() {
  infra_setup();
  motor_setup();
  sen_dist_setup();
  sen_linha_setup();

  pinMode(INTERRUPTOR, INPUT);
}

void loop() {
  if (digitalRead(INTERRUPTOR) == HIGH) {
    if (sen_infra() == 2) {
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
    }
  }
  delay(500); // testar
}

