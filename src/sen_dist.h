#include <Arduino.h>

#define SEN_DIST_ESQ A0
#define SEN_DIST_DIR A1

#define valor_detec 1

void sen_dist_setup() {
    pinMode(SEN_DIST_ESQ, INPUT);
    pinMode(SEN_DIST_DIR, INPUT);
}

bool inimigo() {
    Serial.write(analogRead(SEN_DIST_DIR));
    Serial.write(analogRead(SEN_DIST_ESQ));
    if (analogRead(SEN_DIST_ESQ) < valor_detec|| analogRead(SEN_DIST_DIR) < valor_detec) {
        // Serial.write("distancia detectada");
        return true;
    } else return false;
}

