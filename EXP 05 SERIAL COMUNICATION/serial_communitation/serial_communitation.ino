const int light1 = PB5;
void uartInit();
void uartDataWrite(char data);
void uartWrite(char *str);
void uartWriteLn(char *str);
char uartRead();
bool dataAvailable();
void lightPinConfig();
void setup() {
  uartInit();
  lightPinConfig();
}
void loop() {
  if(dataAvailable()){
    char received = uartRead();
    uartWrite("You have sent = ");
    uartDataWrite(received);
    uartWriteLn("");
    if((received == 'a') || (received == 'A')){
      PORTB ^=(1<<light1);
    }
  }  
}
void uartInit(){
  UBRR0H = 0;//set baud rate = 9600
  UBRR0L = 103; 
  UCSR0B |=(1<<TXEN0)|(1<<RXEN0); //enable Tx and Rx
  UCSR0C |=(1<<UCSZ01)|(1<<UCSZ00); //set frame size = 8-bit
}
void uartDataWrite(char data){
  while(!(UCSR0A&(1<<UDRE0))); //wait until UDR empty
  UDR0 = data;
}
void uartWrite(char *str){
  while(*str){
    uartDataWrite(*str++);
  }
}
void uartWriteLn(char *str){
  while(*str){
    uartDataWrite(*str++);
  }
  uartDataWrite(13);
}
char uartRead(){
  while(!(UCSR0A&(1<<RXC0))); //wait unitl data has received
  return UDR0;
}
bool dataAvailable(){
  return UCSR0A&(1<<RXC0);
}
void lightPinConfig(){
  DDRB |=(1<<light1);
}