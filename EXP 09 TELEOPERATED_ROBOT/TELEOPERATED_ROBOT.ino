#include "motor.h"
#include "serial.h"

void setup() {
  motor_pin_config();
  timer0_pwm_init();
  usartInit();
  _delay_ms(1000);
}
void loop() {
  if (dataAvailable() > 0) {
    char cmd = usartDataRead();
    if (cmd == 'f') {
      fwd(150,150);
    }
    else if (cmd == 'b') {
      back(150, 150);
    }
    else if (cmd == 'r'){
      right(150,150);
    }
    else if (cmd == 'l'){
      left(150,150);
    }
    else {
      stop();
    }
  }
}