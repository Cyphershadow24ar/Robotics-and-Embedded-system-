#include <inttypes.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>
#include<util/delay.h>

int main()
 { 
      DDRB |=0b00000010;  //define PB1 pin as o/p
      DDRC |=0b0010000;  //define PC4pin as o/p
      PORTB &=0b11111101;     //drive PB1 to low
      PORTC &=0b11101111;  //drive PC4 to low
      _delay_ms(1000); 
    
   while (1){
    PORTB  |=0b00000010;  // PB1 ON
    PORTC &=0b11101111; // PC4 OFF
    _delay_ms(500);

     PORTB &=0b11111101; // PB1 OFF
     PORTC  |=0b0010000; // PC4 ON
    _delay_ms(500);
}
   return 0;
}
