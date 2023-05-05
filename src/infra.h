#include <Arduino.h>

#define INFRA_PIN A2

void infra_setup() {
    pinMode(INFRA_PIN, INPUT);
}

int sen_infra() {
    return analogRead(INFRA_PIN);
    // tratar resultado
}