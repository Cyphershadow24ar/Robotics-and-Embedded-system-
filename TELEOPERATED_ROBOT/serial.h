#ifndef serial_h
#define serial_h
#include<Arduino.h>

void usartInit();
void usartDataWrite(char data);
void usartStrWrite(char *ch);
void usartStrWriteLn(char *ch);
char usartDataRead();
bool dataAvailable();
void uartNumberWrite(int num);

#endif