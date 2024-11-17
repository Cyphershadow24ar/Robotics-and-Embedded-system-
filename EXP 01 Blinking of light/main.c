#include <inttypes.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>
#include <util/delay.h>

int main()
 { 
      DDRB |=0b0001000;  
     PORTB &=0b11110111;      


      DDRC |=0b00000100;  
     PORTC &=0b11111011; 
   while (1){
    PORTB  |=0b00001000;
    _delay_ms(500);  
     PORTC &=0b11111011;
    _delay_ms(500);

   PORTC  |=0b00000100;
    _delay_ms(500);  
     PORTB &=0b11110111;
    _delay_ms(500);
}
   return 0;
 }
