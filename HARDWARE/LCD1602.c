#include "LCD1602.h"

uchar Busy_Check()
{
 	uchar LCD_Status;
	RS = 0;
	RW = 1;
	EN = 1;
	DelayMS(1);
   	LCD_Status = P0;
	EN = 0;
	return LCD_Status;
}

void Write_LCD_Command(uchar cmd)
{
 	while((Busy_Check()&0x80)==0x80);
	RS = 0;
	RW = 0;
	EN = 0;
	P0 = cmd;
	EN = 1;
	DelayMS(1);
	EN = 0;
}

void Write_LCD_Data(uchar dat)
{
 	while((Busy_Check()&0x80)==0x80);
	RS = 1;
	RW = 0;
	EN = 0;
	P0 = dat;
	EN = 1;
	DelayMS(1);
	EN = 0;
}

void Initialize_LCD()
{
 	Write_LCD_Command(0x38);
	DelayMS(1);	
	Write_LCD_Command(0x01);
	DelayMS(1);	
	Write_LCD_Command(0x06);
	DelayMS(1);	
	Write_LCD_Command(0x0c);
	DelayMS(1);	
}

void ShowString(uchar x,uchar y,uchar *str)
{
 	uchar i = 0;
	if(y == 0)
		Write_LCD_Command(0x80 | x);
	if(y == 1)
		Write_LCD_Command(0xc0 | x);
	for(i=0;i<16;i++)
	{
	 	Write_LCD_Data(str[i]);	
	}
}

void Set_Disp_Pos(uchar pos)
{
 	Write_LCD_Command(pos | 0x80);
}