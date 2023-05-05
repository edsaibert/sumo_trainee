#include <Arduino.h>

#define SEN_LINHA_ESQ 9
#define SEN_LINHA_DIR 10

void sen_linha_setup() {
    pinMode(SEN_LINHA_ESQ, INPUT);
    pinMode(SEN_LINHA_DIR, INPUT);
}

bool detec_linha() {
    if (digitalRead(SEN_LINHA_ESQ) == LOW || digitalRead(SEN_LINHA_DIR) == LOW) {
        return true;
    } else return false;
}

