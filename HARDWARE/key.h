#ifndef __KEY__H
#define __KEY__H
#include <reg52.h>
#include <intrins.h>
#include "delay.h"
#include "MYHEAD.h"

#define KEY_PORT P1 //���õ��󰴼�����

sbit KEY_READ 	= P1^0; //���õ�������

uchar Keys_Scan();//���󰴼�
uchar Key_Scan(uchar mode);//��������

#endif