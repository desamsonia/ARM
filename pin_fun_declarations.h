//#include "pin_fun_defines.c"
#include <LPC21xx.h>
#include "types.h"
#define FUNC1 0
#define FUNC2 1
#define FUNC3 2
#define FUNC4 3

#define GPIO_OUT 0xFFFFFFFF
#define GPIO_IN  0x00000000

#define CFGPIN(WORD,PIN,FUNC)  (WORD = ((PIN < 16 ) ? ((WORD & ~(PIN*2)) | (FUNC << (PIN*2))): \
                                  ((WORD & ~(3<<(PIN-16)*2)) | (FUNC<<(PIN-16)*2))))
																	
void cfgPortPin(unsigned int portNO, unsigned int pinNo,int pinFunc);		
void CfgPortPin(u32 portNo,u32 pinNo, u32 pinFunc);
void SetPortPin(u32 portNo,u32 pinNo);
void ClrPortPin(u32 portNo,u32 pinNo);
void TogglePortPin(u32 portNo,u32 pinNo);
void Wr2PortPin(u32 portNo,u32 pinNo);
u32 RdPortPin(u32 portNo,u32 pinNo);
void CfgPortByte(u32 portNo,u32 startpinNo,u32 pinFunc);
void Wr2PortByte(u32 portNo,u32 startpinNo,u32 byte);
