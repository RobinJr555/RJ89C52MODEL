#include "delay.h"

void DelayMS(uint ms)
{
 	uchar t;
	while(ms--)
	{
	 	for(t=0;t<120;t++);
	}
}

void Delayus(uint us)
{
	while(us--);
}