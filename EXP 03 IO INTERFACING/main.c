
#include <avr/io.h>
#include <util/delay.h>

int main()
{
    // Configure PB1 and PC2 as output for LEDs
    DDRB |= (1 << PB1);
    DDRC |= (1 << PC2);

    // Configure PB4 and PC0 as input for buttons
    DDRB &= ~(1 << PB4);
    DDRC &= ~(1 << PC0);

    // Enable pull-up resistors for buttons
    PORTB |= (1 << PB4);
    PORTC |= (1 << PC0);

    while (1)
    {
        // Read button states
        uint8_t btn1 = PINB & (1 << PB4);
        uint8_t btn2 = PINC & (1 << PC0);

        if (btn1 && btn2) // Both buttons are off
        {
            PORTB &= ~(1 << PB1); // LED 1 off
            PORTC &= ~(1 << PC2); // LED 2 off
        }
        else if (!btn1 && btn2) // PB1 on, PB4 off
        {
            PORTB |= (1 << PB1);  // LED 1 on
            PORTC |= (1 << PC2);  // LED 2 on
        }
        else if (btn1 && !btn2) // PB1 off, PB4 on
        {
            PORTB |= (1 << PB1);  // LED 1 on
            PORTC &= ~(1 << PC2); // LED 2 off
        }
        else // Both buttons are on
        {
            PORTB &= ~(1 << PB1); // LED 1 off
            PORTC |= (1 << PC2);  // LED 2 on
        }
    }
    return 0;
}
