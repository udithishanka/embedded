#include <avr/io.h>
#include <util/delay.h>

#define LED (1 << PB1)
#define BUTTON (1 << PB0)


int main(){
    DDRB |= LED;
    DDRB &= ~BUTTON;
    PORTB |= BUTTON;

    while(1){
        if(PINB & BUTTON){
            PORTB |= LED;
        }else{
            PORTB &= ~LED;
        }
    }
    return 0;
}