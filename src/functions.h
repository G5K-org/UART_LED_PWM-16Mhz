
#ifndef __FUNCTIONS
#define __FUNCTIONS

void init_GPIO();
void flash_light();
void USART_Init( unsigned int ubrr); 
void USART_Transmit_String(char* data);
void init_ADC();

int read_ADC();

#endif