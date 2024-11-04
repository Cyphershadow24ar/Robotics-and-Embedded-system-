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
