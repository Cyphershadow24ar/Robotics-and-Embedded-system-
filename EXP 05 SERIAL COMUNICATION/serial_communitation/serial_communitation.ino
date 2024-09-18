void usart0Init();
void usart0DataWrite(char data);
void setup() {
  usart0Init();
}
void loop() {
  usart0DataWrite('H');
  usart0DataWrite('E');
  usart0DataWrite('L');
  usart0DataWrite('L');
  usart0DataWrite('O');
}
void usart0Init(){
  UBRR0H = 0;//set baud rate = 9600
  UBRR0L = 103; 
  UCSR0B |=(1<<TXEN0)|(1<<RXEN0); //enable Tx and Rx
  UCSR0C |=(1<<UCSZ01)|(1<<UCSZ00); //set fram size = 8-bit
}
void usart0DataWrite(char data){
  while(!(UCSR0A&(1<<UDRE0))); //wait until UDR empty
  UDR0 = data;
}