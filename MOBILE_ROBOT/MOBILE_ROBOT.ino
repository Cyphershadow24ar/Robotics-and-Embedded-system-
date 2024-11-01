const int lm1=PB5, lm2=PB4,lms=PD6, rm1=PD7, rm2=PB0, rms=PD5;
void motor_pin_config();
void fwd();
void timer0_pwm_init();
void timer0_dutycycle(char ls, char rs);
void setup() {
  motor_pin_config();
  timer0_pwm_init();
}
void loop() {
  fwd(100,100); 
  //timer0_dutycycle(70, 250); right fast left slow
  
}
void motor_pin_config(){
  DDRB |=(1<<lm1)|(1<<lm2)|(1<<rm2); 
  DDRD |=(1<<lms)|(1<<rm1)|(1<<rms);
  //PORTD |=(1<<lms)|(1<<rms);  //to enable the motor driver's channels
}
void fwd(char ls, char rs){
  PORTB |=(1<<lm1); PORTB &=~(1<<lm2);
  PORTD |=(1<<rm1); PORTB &=~(1<<rm2);
  timer0_dutycycle(ls, rs); //left fast right slow
}

void timer0_pwm_init(){
  TCCR0A |=(1<<WGM01)|(1<<WGM00);  //select fast pwm mode
  TCCR0A |=(1<<COM0A1)|(1<<COM0B1);         //select non-inverting pwm
  TCCR0B |=(1<<CS00);           //select precaller = 1
  DDRD |=(1<<PD6)|(1<<PD5);              //define OC0A pin as o/p
}
void timer0_dutycycle(char ls, char rs){
  OCR0A = rs;  
  OCR0B = ls;             //set duty cycle
}