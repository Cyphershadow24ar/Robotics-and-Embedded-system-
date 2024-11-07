#include "adc.h"

void adcInit(){
  /*enable ADC,enable conversion conversion complete interrupt, prescaller=128 */
  ADCSRA |=(1<<ADEN)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);
}
int readAdc(char ch){
  uint16_t adcResult = 0;
  uint8_t temp = 0;
  ch = ch & 0b00000111; //keept only the channel number
  ADMUX =(1<<REFS0) | ch;
  ADCSRA |=(1<<ADSC); //start conversion
  while(!(ADCSRA & (1<<ADIF))); //wait until conversion complete
  temp = ADCL;
  adcResult = ADCH; 
  ADCSRA |=(1<<ADIF); //clear flag
  adcResult = (adcResult <<8) | temp;
  return adcResult;
}