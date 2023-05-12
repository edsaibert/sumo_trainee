#include <Arduino.h>

#define SEN_LINHA_ESQ 9
#define SEN_LINHA_DIR 11

void sen_linha_setup() {
    pinMode(SEN_LINHA_ESQ, INPUT);
    pinMode(SEN_LINHA_DIR, INPUT);
}

bool detec_linha() {
    Serial.write(digitalRead(SEN_LINHA_ESQ));
    if (digitalRead(SEN_LINHA_ESQ) == LOW || digitalRead(SEN_LINHA_DIR) == LOW) {
        Serial.write("linha detectada");
        return true;
    } else return false;
}

