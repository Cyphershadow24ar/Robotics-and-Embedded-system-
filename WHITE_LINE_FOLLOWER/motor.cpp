#include "motor.h"
const int lm1=PD7, lm2=PB0, lms=PD5, rm1=PB5, rm2=PB4, rms=PD6;
void motor_pin_config(){
  DDRD |=(1<<lm1)|(1<<lms)|(1<<rms);
  DDRB |=(1<<lm2)|(1<<rm1)|(1<<rm2);
  //PORTD |=(1<<lms)|(1<<rms); //motor driver's channels are enabled
}
void fwd(char ls, char rs){
  PORTD |=(1<<lm1); PORTB &=~(1<<lm2);
  PORTB |=(1<<rm1); PORTB &=~(1<<rm2);
  timer0_dutycycle(ls, rs);
}
void back(char ls, char rs){
  PORTD &=~(1<<lm1); PORTB |=(1<<lm2);
  PORTB &=~(1<<rm1); PORTB |=(1<<rm2);
  timer0_dutycycle(ls, rs);
}
void left(char ls, char rs){
  PORTD &=~(1<<lm1); PORTB |=(1<<lm2);
  PORTB |=(1<<rm1); PORTB &=~(1<<rm2);
  timer0_dutycycle(ls, rs);
}
void right(char ls, char rs){
  PORTD |=(1<<lm1); PORTB &=~(1<<lm2);
  PORTB &=~(1<<rm1); PORTB |=(1<<rm2);
  timer0_dutycycle(ls, rs);
}
void stop(){
  PORTD &=~(1<<lm1); 
  PORTB &=~((1<<lm2)|(1<<rm1)|(1<<rm2));
  timer0_dutycycle(0, 0);
}
void timer0_pwm_init(){
  TCCR0A |=(1<<WGM01)|(1<<WGM00);  //select fast pwm mode
  TCCR0A |=(1<<COM0A1)|(1<<COM0B1);         //select non-inverting pwm
  TCCR0B |=(1<<CS00);           //select precaller = 1
  DDRD |=(1<<PD6)|(1<<PD5);              //define OC0A pin as o/p
}
void timer0_dutycycle(char ls, char rs){
  OCR0A = rs;  
  OCR0B = ls;             //set duty cycle
}