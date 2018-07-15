#include "DS18B20.h"

uchar Init_DS18B20()
{
 	uchar status;
	DQ = 1;
	Delayus(8);
	DQ = 0;
	Delayus(90);
	DQ = 1;
	Delayus(8);
	DQ = 1;
	return status;
}

uchar ReadOneByte()
{
 	uchar i,dat=0;
	DQ = 1;
	_nop_();
	for(i=0;i<8;i++)
	{
	 	DQ = 0;
		dat >>= 1;
		DQ = 1;
		_nop_();
		_nop_();
		if(DQ)
			dat |= 0X80;
		Delayus(30);
		DQ = 1;
	}
	return dat;
}

void WriteOneByte(uchar dat)
{
 	uchar i;
	for(i=0;i<8;i++)
	{
	 	DQ = 0;
		DQ = dat& 0x01;
		Delayus(5);
		DQ = 1;
		dat >>= 1;
	}
}

void Read_Temperature(uchar* Temp_Value)
{
 	if(Init_DS18B20()==1)
		DS18B20_IS_OK=0;
	else
	{
		WriteOneByte(0xcc);
		WriteOneByte(0x44);
		Init_DS18B20();
		WriteOneByte(0xcc);
		WriteOneByte(0xbe);
		Temp_Value[0] = ReadOneByte(); 
		Temp_Value[1] = ReadOneByte();
		DS18B20_IS_OK=1;	
	}	
}