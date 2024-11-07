// #include "motor.h"
// #include "serial.h"
// #include "adc.h"

// const int th = 100;  // Threshold for black/white detection
// int junctionCounter = 0;  // Tracks the current junction number

// void setup() {
//   motor_pin_config();
//   timer0_pwm_init();
//   usartInit();
//   adcInit();
//   _delay_ms(1000);
// }

// void loop() {
//   int ls = readAdc(0);  // Left sensor reading
//   int ms = readAdc(1);  // Middle sensor reading
//   int rs = readAdc(2);  // Right sensor reading

//   // Check if at a junction (all sensors detect black)
//   if ((ls > th) && (ms > th) && (rs > th)) {
//     junctionCounter++;  // Increment junction counter to identify the current junction

//     // Perform action based on the current junction
//     switch (junctionCounter) {
//       case 1:
//         // Junction 1 - turn left
//         left(100, 100);
//         _delay_ms(800);  // Longer delay for accurate turn
//         break;

//       case 2:
//         // Junction 2 - turn right
//         right(100, 100);
//         _delay_ms(800);
//         break;

//       case 3:
//       case 4:
//         // Junction 3 & 4 - move forward
//         fwd(100, 100);
//         _delay_ms(500);
//         break;

//       case 5:
//         // Junction 5 - turn right
//         right(100, 100);
//         _delay_ms(800);
//         break;

//       case 6:
//       case 7:
//         // Junction 6 & 7 - move forward
//         fwd(100, 100);
//         _delay_ms(500);
//         break;

//       case 8:
//         // Junction 8 - turn right
//         right(100, 100);
//         _delay_ms(800);
//         break;

//       case 9:
//       case 10:
//         // Junction 9 & 10 - move forward
//         fwd(100, 100);
//         _delay_ms(500);
//         break;

//       case 11:
//         // Junction 11 - turn left
//         left(100, 100);
//         _delay_ms(800);
//         break;

//       default:
//         // Stop the robot after the last junction, or reset if desired
//         stop();
//         break;
//     }
//   }
//   else {
//     // Normal line-following behavior when not at a junction
//     if ((ls < th) && (ms > th) && (rs < th)) {
//       // Go forward when middle sensor is on black
//       fwd(90, 90);
//     } 
//     else if ((ls > th) && (ms < th) && (rs < th)) {
//       // Slight right if left sensor detects black
//       fwd(45, 90);
//     } 
//     else if ((ls < th) && (ms < th) && (rs > th)) {
//       // Slight left if right sensor detects black
//       fwd(90, 45);
//     } 
//   }
  
//   _delay_ms(100);  // Delay for stability in sensor readings
// }

#include "motor.h"
#include "serial.h"
#include "adc.h"

const int th = 100;  // Threshold for black/white detection
int junctionCounter = 0;  // Tracks the current junction number

void setup() {
  motor_pin_config();
  timer0_pwm_init();
  usartInit();
  adcInit();
  _delay_ms(1000);
}

void loop() {
  int ls = readAdc(0);  // Left sensor reading
  int ms = readAdc(1);  // Middle sensor reading
  int rs = readAdc(2);  // Right sensor reading

  // Check if at a junction (all sensors detect black)
  if ((ls > th) && (ms > th) && (rs > th)) {
    junctionCounter++;  // Increment junction counter to identify the current junction

    // Perform action based on the current junction
    switch (junctionCounter) {
      case 1:
        // Junction 1 - turn left
        fwd(0, 90);  // Turn left based on code 1
        _delay_ms(800);  // Longer delay for accurate turn
        break;

      case 2:
        // Junction 2 - turn right
        fwd(90, 0);  // Turn right based on code 1
        _delay_ms(800);
        break;

      case 3:
      case 4:
        // Junction 3 & 4 - move forward
        fwd(100, 100);
        _delay_ms(500);
        break;

      case 5:
        // Junction 5 - turn right
        fwd(90, 0);  // Turn right based on code 1
        _delay_ms(800);
        break;

      case 6:
      case 7:
        // Junction 6 & 7 - move forward
        fwd(100, 100);
        _delay_ms(500);
        break;

      case 8:
        // Junction 8 - turn right
        fwd(90, 0);  // Turn right based on code 1
        _delay_ms(800);
        break;

      case 9:
      case 10:
        // Junction 9 & 10 - move forward
        fwd(100, 100);
        _delay_ms(500);
        break;

      case 11:
        // Junction 11 - turn left
        fwd(0, 90);  // Turn left based on code 1
        _delay_ms(800);
        break;

      default:
        // Stop the robot after the last junction, or reset if desired
        stop();
        break;
    }
  }
  else {
    // Normal line-following behavior when not at a junction
    if ((ls < th) && (ms > th) && (rs < th)) {
      // Go forward when middle sensor is on black
      fwd(90, 90);
    } 
    else if ((ls > th) && (ms < th) && (rs < th)) {
      // Slight right if left sensor detects black
      fwd(45, 90);
    } 
    else if ((ls < th) && (ms < th) && (rs > th)) {
      // Slight left if right sensor detects black
      fwd(90, 45);
    } 
  }
  
  _delay_ms(100);  // Delay for stability in sensor readings
}

