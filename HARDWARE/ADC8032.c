#include "ADC8032.h"

uchar Get_AD_Result(unsigned char CH)
{
 	uchar i,dat=0,dat1=0,dat2=0;
	CLK = 0;
	DIO = 1; 
	_nop_();
	CS  = 0;
	_nop_();
	CLK = 1; 
	_nop_();
	if (CH == 0x00)//Í¨µÀÑ¡Ôñ
	{
		CLK = 0;
		DIO = 1;
		_nop_();
		CLK = 1;
		_nop_();
		CLK = 0;
		DIO = 0;
		_nop_();
		CLK = 1;
		_nop_();
	}
	else
	{
		CLK = 0;
		DIO = 1;
		_nop_();
		CLK = 1;
		_nop_();
		CLK = 0;
		DIO = 1;
		_nop_();
		CLK = 1;
		_nop_();
	}
		CLK = 0;
		DIO = 1;

	for(i=0;i<8;i++)
	{
	 	_nop_();
		dat1 <<= 1;
		CLK = 1;
		_nop_();
		CLK = 0;
		if(DIO)
			dat1 |= 0x01;
		else
			dat1 |= 0x00;
	}
	
	for(i=0;i<8;i++)
	{
		dat2 >>= 1;
		if(DIO)
			dat2 |= 0x80;
		else
			dat2 |= 0x00;
		_nop_();
		CLK = 1;
		_nop_();
		CLK = 0;
	}
	if(dat1 == dat2)
		dat = dat1;
	_nop_();
	CS  = 1;
	DIO = 0;
	CLK = 1;
	return dat;
}