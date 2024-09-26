void externalInterruptInit();
void ledPinConfig();
ISR(INT1_vect){
  PORTB ^=(1<<PB5);
}
void setup() {
  externalInterruptInit();
  ledPinConfig();
}
void loop() {
  PORTB |=(1<<PB1); _delay_ms(500);
  PORTB &=~(1<<PB1); _delay_ms(500);
}
void externalInterruptInit(){
  cli(); //disable global interrupt
  EICRA |=(1<<ISC01); //falling edge triggering
  EIMSK |=(1<<INT1); //enable INT0
  DDRD &=~(1<<PD3); //define INT0(PD2) as i/p
  PORTD |=(1<<PD3); //enable pullup resistor
  sei(); //enable global interrupt
}
void ledPinConfig(){
  DDRB |=(1<<PB1)|(1<<PB5);
}


void externalInterruptInit();
void ledPinConfig();
ISR(INT0_vect){
  PORTB ^=(1<<PB5);
}
void setup() {
  externalInterruptInit();
  ledPinConfig();
}
void loop() {
  PORTB |=(1<<PB1); _delay_ms(500);
  PORTB &=~(1<<PB1); _delay_ms(500);
}
void externalInterruptInit(){
  cli(); //disable global interrupt
  EICRA |=(1<<ISC01); //falling edge triggering
  EIMSK |=(1<<INT0); //enable INT0
  DDRD &=~(1<<PD2); //define INT0(PD2) as i/p
  PORTD |=(1<<PD2); //enable pullup resistor
  sei(); //enable global interrupt
}
void ledPinConfig(){
  DDRB |=(1<<PB1)|(1<<PB5);
}