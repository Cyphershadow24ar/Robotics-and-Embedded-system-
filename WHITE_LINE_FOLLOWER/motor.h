#ifndef motor_h
#define motor_h
#include<Arduino.h>
void motor_pin_config();
void fwd(char ls, char rs);
void back(char ls, char rs);
void left(char ls, char rs);
void right(char ls, char rs);
void stop();
void timer0_pwm_init();
void timer0_dutycycle(char ls, char rs);


#endif