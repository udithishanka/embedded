#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

// #define LED_G (1<<PB0)
// #define BUTTON (1<<PB1)
// #define LED_R (1<<PD6)

// int main(){
//   DDRD |= LED_R;
//   DDRB |= LED_G;

//   DDRB &= ~BUTTON;
//   PORTB |= BUTTON;

//   while(1){
//     PORTD ^= LED_R;
//     _delay_ms(500);

//     if(!(PINB & BUTTON)){
//       while (!(PINB & BUTTON)){
//         _delay_ms(25);  
//       }
//       PORTB ^= LED_G;
//     }
//   }
//   return 0;
// }

#define BUTTON (1<<PC4)
#define LED_R (1<<PD7)
#define LED_G (1<<PD6)

int main(){
  DDRD |= LED_R | LED_G;
  PORTD &= ~(LED_R | LED_G);

  DDRC &= ~BUTTON;
  PORTC |= BUTTON;

  TCCR1B = (1<<WGM12)|(1<<CS12)|(1<<CS10);
  OCR1A = 8000;
  TIMSK1 = (1<<OCIE1A);
  sei();

  while(1){

    if(!(PINC & BUTTON)){
      while (!(PINC & BUTTON));
      PORTD ^= LED_R;
    }
  }
  return 0;
}

ISR(TIMER1_COMPA_vect){
  PORTD ^= LED_G;
}