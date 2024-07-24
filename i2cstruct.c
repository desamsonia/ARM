#include <LPC21xx.h>
#include "types.h"
#include "i2c.h"
#include "i2c_eeprom.h"
#include "delay_1.h"
#include <string.h>

#define I2C_EEPROM_SA 0x50 //7Bit Slave Addr
#define gLED 1<<16 //P1.16
#define rLED 1<<17 //P1.17

typedef struct {
 char uname[10];
	char ID[9];
	char time[9];
} user_data;

user_data arr1[3] __attribute__((at(0x40000080)));

/* Function to write user id into eeprom */

void write_to_eeprom(user_data *arr)
{
	int i;
	for(i=0;i<3;i++)
	{
	  i2c_eeprom_page_write(I2C_EEPROM_SA,0x00,arr[i].uname,8);
		i2c_eeprom_page_write(I2C_EEPROM_SA,0x00,arr[i].ID,8);
		i2c_eeprom_page_write(I2C_EEPROM_SA,0x00,arr[i].time,8);
	}
}

/*
/* Function to read user id from eeprom */

void read_from_eeprom(user_data *arr)
{
  int i;
	for(i=0;i<3;i++)
	{
	  i2c_eeprom_seq_read(I2C_EEPROM_SA,0x00,arr1[i].uname,8);
		i2c_eeprom_seq_read(I2C_EEPROM_SA,0x00,arr1[i].ID,8);
		i2c_eeprom_seq_read(I2C_EEPROM_SA,0x00,arr1[i].time,8);
	}
}
/*-----------------------------------------*/


int main()
{
	int i;
	user_data arr[3];	
	 //user 1
	strcpy(arr[0].uname,"kohli");
	strcpy(arr[0].ID,"00032829");
	strcpy(arr[0].time,"08:24:43");
	//user 2
	strcpy(arr[1].uname,"Dhoni");
	strcpy(arr[1].ID,"12345678");
	strcpy(arr[1].time,"10:22:12");
	//user 3
	strcpy(arr[2].uname,"Peri");
	strcpy(arr[2].ID,"23119000");
	strcpy(arr[2].time,"11:09:33");
	
	write_to_eeprom(arr);
	read_from_eeprom(arr);
	delay_ms(100);	
}
	