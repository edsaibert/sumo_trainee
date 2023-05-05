#include <Arduino.h>

#define MOTOR_ESQ_PWN 3
#define MOTOR_DIR_PWN 5
#define MOTOR_ESQ_1 2
#define MOTOR_ESQ_2 4
#define MOTOR_DIR_1 6
#define MOTOR_DIR_2 7


void motor_setup(){
    pinMode(MOTOR_ESQ_PWN, OUTPUT);
    pinMode(MOTOR_DIR_PWN, OUTPUT);
    pinMode(MOTOR_ESQ_1, OUTPUT);
    pinMode(MOTOR_ESQ_2, OUTPUT);
    pinMode(MOTOR_DIR_1, OUTPUT);
    pinMode(MOTOR_DIR_2, OUTPUT);
}

