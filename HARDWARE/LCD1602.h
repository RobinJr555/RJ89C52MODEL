#ifndef __LCD1602__H
#define __LCD1602__H
#include <reg52.h>
#include <intrins.h>
#include "MYHEAD.h"
#include "delay.h"

sbit RS = P2^0;
sbit RW = P2^1;
sbit EN = P2^2;

void Delayms(uint ms);
uchar Busy_Check();
void Write_LCD_Command(uchar cmd);
void Write_LCD_Data(uchar dat);
void Initialize_LCD();
void ShowString(uchar x,uchar y,uchar *str);
void Set_Disp_Pos(uchar pos);
#endif