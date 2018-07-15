#include "key.h"

uchar Keys_Scan()
{
	uchar Tmp;
	uchar KeyNO; //���尴��ֵ
	KEY_PORT = 0x0f; // 0000 1111 ���ж�
	DelayMS(1);
	Tmp = KEY_PORT ^ 0x0f; //��λ��� 0000 
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
	static uchar key_up=1;//�������ɿ���־
	if(mode)key_up=1;  //֧������		  
	if(key_up&&(KEY_READ==0))
	{
		DelayMS(1);//ȥ����
		key_up=0;
		if(KEY_READ==0) return 1;//��������
		//����δ����
	}
	return 0;
}