#include "types.h"
void initUART(void);
void sendUART(unsigned char mydata);
unsigned char receiveUART(void);
void printUART(char mydata[]);
char* readStr(void);
void octUART_tx(u32 n);
void hexUART_tx(u32 n);
void f32UART_tx(f32 f,u32 ndp);
void s32UART_tx(s32 n);
