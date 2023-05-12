#include <Arduino.h>

#define INFRA_PIN A2

void infra_setup() { pinMode(INFRA_PIN, INPUT); }

int sen_infra() {
  // Serial.write(analogRead(INFRA_PIN));
  // return analogRead(INFRA_PIN);
  return 2;
  // tratar resultado
}