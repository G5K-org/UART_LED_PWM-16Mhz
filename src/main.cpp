#include <avr/io.h>
#include <util/delay.h>
#include "functions.h"
#include "functions.c"

#define BAUD 9600
#define UBRRx F_CPU/16/BAUD-1


int main(void)
{
init_GPIO();
USART_Init(UBRRx);
init_ADC();
init_PWM();

while(1)
{
set_LED_Brightnes((read_ADC()/4));
char buffer[8];
USART_Transmit_String(itoa(read_ADC(),buffer,10));
USART_Transmit_String("\n");
}
  return 0;
}