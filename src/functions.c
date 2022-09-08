#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>



void init_GPIO()
{
 DDRD |= (1<<PORTD);
}
void USART_Init( unsigned int ubrr)
{
/* Set baud rate */
UBRRH = (unsigned char)(ubrr>>8);
UBRRL = (unsigned char)ubrr;
UCSRB = (1<<RXEN)|(1<<TXEN);
UCSRC = (1<<URSEL)|(1<<USBS)|(3<<UCSZ0);
}


void init_ADC()
{
ADMUX |= (1<<REFS0);
ADCSRA |= (1<<ADEN)|(1<<ADPS2)|(1<<ADPS1);
}




void USART_Transmit_String(char* data )
{
int i = 0;
while(data[i]!='\0')
{
/* Wait for empty transmit buffer */
while (!( UCSRA & (1<<UDRE)));
/* Put data into buffer, sends the data */
UDR = data[i];
i++;
}
}


void flash_light()
{

PORTD ^= (1<<PD7);
_delay_ms(00);
}

int read_ADC()
{
    ADCSRA |= (1<<ADSC);
    while(ADCSRA &(1<<ADSC));
    if(ADIF)
    {
    int alldata = (ADCL);
    alldata |= (ADCH<<8);
    return alldata;
    
    }
    return 99;
    
}