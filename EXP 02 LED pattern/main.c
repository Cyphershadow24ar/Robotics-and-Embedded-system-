#include <inttypes.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>
#include<util/delay.h>

//LED PATTERN

int main()
 { 
   int i=0;
   DDRD  |= 0b11111111;
   PORTD &= 0b00000000; 
   while (1)
   {
      PORTD &= 0b00000000; 
      _delay_ms(100); 
      for(i=0;i<8;i++){
      PORTD |= 0b10000000 >> i;
      _delay_ms(100);
      }
     for(i=0;i<8;i++){
      PORTD |= 0b00000001 >> i;   //adding | returns past value or past pattern.
      _delay_ms(100);
      }
     for(i=0;i<8;i++){
      PORTD = 0b10000000 >> i;
      _delay_ms(100);
      }
   for(i=0;i<8;i++){
      PORTD = 0b00000001 << i;
      _delay_ms(100);
      }
    for(i=0;i<4;i++){
      PORTD = 0b00010000 << i |  0b00001000 >> i;
 
      _delay_ms(100);
      }
   for(i=0;i<4;i++){
     PORTD |= 0b00010000 << i |  0b00001000 >> i;
 
      _delay_ms(100);
      }
    for(i=0;i<4;i++){
      PORTD |= 0b10000000 >> i |  0b0000001 << i;
      _delay_ms(100);
      }
   }
   return 0;
 }
