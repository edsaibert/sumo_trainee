#include <Arduino.h>

#define SEN_DIST_ESQ A0
#define SEN_DIST_DIR A1
#define valor_detec 400

void sen_dist_setup() {
    pinMode(SEN_DIST_ESQ, INPUT);
    pinMode(SEN_DIST_DIR, INPUT);
}

bool inimigo() {
    if (analogRead(SEN_DIST_ESQ) < valor_detec|| analogRead(SEN_DIST_DIR) < valor_detec) {
        return true;
    } else return false;
}

