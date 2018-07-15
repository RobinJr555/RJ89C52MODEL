#include "key.h"

uchar Keys_Scan()
{
	uchar Tmp;
	uchar KeyNO; //定义按键值
	KEY_PORT = 0x0f; // 0000 1111 列判断
	DelayMS(1);
	Tmp = KEY_PORT ^ 0x0f; //按位异或 0000 
	switch(Tmp)
	{
	 	case 1: KeyNO = 0; break;
		case 2: KeyNO = 1; break;
		case 4: KeyNO = 2; break;
		case 8: KeyNO = 3; break;
		default: KeyNO = 16;
	}
	KEY_PORT = 0xf0;
	DelayMS(1);
	Tmp = KEY_PORT >> 4 ^ 0x0f;
	switch(Tmp)
	{
	 	case 1: KeyNO += 0; break;
		case 2: KeyNO += 4; break;
		case 4: KeyNO += 8; break;
		case 8: KeyNO += 12;
	}
	return KeyNO;
}

uchar Key_Scan(uchar mode)
{
	static uchar key_up=1;//按键按松开标志
	if(mode)key_up=1;  //支持连按		  
	if(key_up&&(KEY_READ==0))
	{
		DelayMS(1);//去抖动
		key_up=0;
		if(KEY_READ==0) return 1;//按键按下
		//按键未按下
	}
	return 0;
}