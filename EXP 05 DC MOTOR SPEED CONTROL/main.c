#include <inttypes.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>
#include<util/delay.h>
const int lm1=PD0 , lm2=PD1;
void motorPinConfig(){
    DDRD |= (1<<lm1) | (1<<lm2);
}
void lmCw(){
    PORTD |=(1<<lm1); PORTD &=~(1<<lm2);
}
void lmCcw(){
    PORTD &=~(1<<lm1); PORTD |=(1<<lm2);
}
void lmStop(){
   PORTD  &=~((1<<lm1)|(1<<lm2));
}

void timer0PwmInit(){
TCCR0A |=(1<<WGM01)|(1<<WGM00);   //select fast pwm mode
TCCR0A |= (1<<COM0A1) | (1<<COM0B1) ;   //select non-inverting pwm
TCCR0B |= (1<<CS00);   //set prescaller
DDRD  |= ((1<<PD5) | (1<<PD6)) ;   //define OCx pin
}

int main()
 { 
  timer0PwmInit();
       motorPinConfig() ;
   while (1){
              lmCw();
         int i=0;
           for (i=0; i<255; i++){
               OCR0A = i ;
               _delay_ms(30);
          }
            lmCcw();
               for (i=255; i>0; i--){
               OCR0B = i ;
               _delay_ms(30);
           }
}
   return 0;
 }
