#include <inttypes.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>
#include<util/delay.h>

const int lm1 = PB0, lm2 = PB1;
void motorPinConfig(){
   DDRB |=(1<<lm1) | (1<<lm2);
 }
 
 void lmCw(){
    PORTB  |= (1<<lm1); PORTB &=~(1<<lm2);
 }
 
 void lmCcw(){
    PORTB &=~(1<<lm1); PORTD |=(1<<lm2);
 }
 
 void lmStop(){
    PORTB  &=~(1<<lm1) | (1<<lm2);
 }
 
int main()
 { 
   // Write your code here
    motorPinConfig();
   while (1){
       lmCw(); _delay_ms(5000); lmStop(); _delay_ms(2000);
      lmCcw(); _delay_ms(5000); lmStop(); _delay_ms(2000);
   }
   return 0;
 }
