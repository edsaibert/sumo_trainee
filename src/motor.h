#include <Arduino.h>

#define MOTOR_ESQ_PWN 3
#define MOTOR_DIR_PWN 6
#define MOTOR_ESQ_1 2
#define MOTOR_ESQ_2 4
#define MOTOR_DIR_1 5
#define MOTOR_DIR_2 7
#define STBY 8

void motor_setup(){
    pinMode(STBY, OUTPUT);
    pinMode(MOTOR_ESQ_PWN, OUTPUT);
    pinMode(MOTOR_DIR_PWN, OUTPUT);
    pinMode(MOTOR_ESQ_1, OUTPUT);
    pinMode(MOTOR_ESQ_2, OUTPUT);
    pinMode(MOTOR_DIR_1, OUTPUT);
    pinMode(MOTOR_DIR_2, OUTPUT);
}

