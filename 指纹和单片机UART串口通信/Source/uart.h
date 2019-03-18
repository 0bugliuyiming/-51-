#ifndef _UART_H_
#define _UART_H_

void ConfigUART();
void SendByte(unsigned char d);
unsigned char ReceiveByte();

#endif