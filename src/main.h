#ifndef SERIALUART_H
#define SERIALUART_H

#include <stdint.h>

//#define tty_port 						"/dev/ttymxc1"
#define tty_port 						"/dev/ttyS0"


int gDevice_Uart_Init(const char* port,uint32_t baudrate,void *rec_callback);
uint32_t post_to_ec20(char *pcFmt, ...);


#endif
