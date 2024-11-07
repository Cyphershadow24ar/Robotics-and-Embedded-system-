#include "serial.h"

void usartInit(){
  UBRR0H = 0;//set baud rate  = 9600
  UBRR0L = 103;
  UCSR0B |=(1<<TXEN0)|(1<<RXEN0); //enable Tx and Rx
  UCSR0C |=(1<<UCSZ01)|(1<<UCSZ00); //set frame size = 8-bit
}
void usartDataWrite(char data){
  while(!(UCSR0A&(1<<UDRE0))); //wait until data register empty
  UDR0 = data;
}
void usartStrWrite(char *ch){
  while(*ch){
    usartDataWrite(*ch++);
  }
}
void usartStrWriteLn(char *ch){
  while(*ch){
    usartDataWrite(*ch++);
  }
  usartDataWrite(10);
}
char usartDataRead(){
  while(!(UCSR0A&(1<<RXC0))); //wait till new data arrieved
  return UDR0;
}
bool dataAvailable(){
  return UCSR0A&(1<<RXC0);
}
void uartNumberWrite(int num){
  char str[5];
  snprintf(str, 5, "%d", num);
  usartStrWrite(str);
}