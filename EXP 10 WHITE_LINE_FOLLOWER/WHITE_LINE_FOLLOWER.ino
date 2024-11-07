#include "motor.h"
#include "serial.h"
#include "adc.h"
const int th = 100;

void setup() {
  motor_pin_config();
  timer0_pwm_init();
  usartInit();
  adcInit();
  _delay_ms(1000);
}
void loop() {
  int ls = readAdc(0);
  int ms = readAdc(1);
  int rs = readAdc(2);

  // uartNumberWrite(ls); usartStrWrite("  ");
  // uartNumberWrite(ms); usartStrWrite("  ");
  // uartNumberWrite(rs); usartStrWrite("  ");
  // usartStrWriteLn("");
  // _delay_ms(1000);



  //black,white,black
  if((ls > th)&&(ms < th)&&(rs > th)){
    fwd(100,100);
    }
  }
  //white,black,black
  if((ls < th)&&(ms > th)&&(rs > th)){
    fwd(60,100);
    }
  }
  //black,black,white
  if((ls > th)&&(ms > th)&&(rs < th)){
    fwd(100,60);
    }
  }


  // if (dataAvailable() > 0) {
  //   char cmd = usartDataRead();
  //   if (cmd == 'f') {
  //     fwd(150,150);
  //   }
  //   else if (cmd == 'b') {
  //     back(150, 150);
  //   }
  //   else if (cmd == 'r'){
  //     right(150,150);
  //   }
  //   else if (cmd == 'l'){
  //     left(150,150);
  //   }
  //   else {
  //     stop();
  //   }
  // }
}