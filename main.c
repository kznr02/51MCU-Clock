#include "timefunc.h"
/*外部中断0*/
void InitInt0()
{
	IT0=1;
	EX0=1;
	EA=1;
}
/*定时器0中断*/
void InitTimer0()
{
    TMOD = 0x01;
    TH0 = 0x0DC;
    TL0 = 0x0D8;
    EA = 1;
    ET0 = 1;
    TR0 = 1;
}
/*主函数*/
int main()
{
	InitInt0();
	InitTimer0();
	while(1)
	{
		datapros();
		smgsend(Display);
		key=KeyScan();
		if(key==1)
		{
			delay(20000);
			flag[1] = 0;
			msTimer();
		}
		if(key==2)
		{
			delay(20000);
			EX0=0;
			flag[2] = 2;
			AlarmSet();
		}
		if(clock[0]==alarm[0] && clock[1]==alarm[1] && clock[2]==alarm[2] && flag[3]==1)/*闹钟触发条件*/
		{
			while(1)
			{
				int i=100;
				smgsend(DisplayAlarm);
				while(i)
				{
					i--;
					beep=~beep;
					delay(100);
				}
				key=KeyScan();
				if(key==1)
				{delay(20000);break;}
			}
		}
	}
}
/*外部中断0*/
void Int0() interrupt 0
{
	delay(1000);
	if(BT3==0)
	{	
	delay(20000);
	flag[4]=2;
	TimeSet();
	}
	else 	ET0=1;
}
/*定时器0*/
void Timer0() interrupt 1
{
  TH0 = 0x0D8;
  TL0 = 0x0F0;
	clock[3]++;
	if(clock[3]>=100)
	{
		clock[3]=0;
		clock[2]++;
		TimeCalc(1,clock);
	}
if(flag[1]==1)
		{
			ms2++;
			if(ms2>=100)
			{
				ms2=0;
				sec++;
			}
		}
}
