
#ifndef __FUNCTIONS
#define __FUNCTIONS

void init_GPIO();
void flash_light();
void USART_Init( unsigned int ubrr); 
void USART_Transmit_String(char* data);
void init_ADC();
void init_PWM();
int read_ADC();
void set_LED_Brightnes(int value);

#endif