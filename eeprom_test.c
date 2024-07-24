#include "i2c_eeprom.h"
#include "delay_1.h"
#include "i2c_defines.h"
#include <lpc21xx.h>
#include "defines_gpio.h"

#define I2C_EEPROM_SA 0x50
u8 rDat __attribute__((at(0x40000000)));
u8 rDat2[10] __attribute__((at(0x40000000))); 
main()
{
   i2c_eeprom_bytewrite(I2C_EEPROM_SA,0,'A');
	 rDat = i2c_eeprom_randomread(0x50,0);
	 delay_ms(2000);
	i2c_eeprom_pagewrite(0x50,0,8,"12345678");
	 i2c_eeprom_seqread(0x50,0,8,rDat2);
	while(1);
}

