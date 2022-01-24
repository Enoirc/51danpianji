#include<reg52.h>

sbit L2_IN1=P1^2;
sbit L2_IN2=P1^3;
sbit L2_IN3=P1^4;
sbit L2_IN4=P1^5;
sbit L2_EN1=P1^6;
sbit L2_EN2=P1^7;
sbit RED_L=P3^3;      //左边红外传感器
sbit RED_R=P3^4;      //右边外红传感器

unsigned char pwm_l =0;
unsigned char push_l =0;   //左电极占空比N/20
unsigned char pwm_r =0;
unsigned char push_r =0; 
unsigned char pwm_t;

void Left()
{
			push_l=12;
			push_r=12;
			L2_IN1 =1;    //左电机负极 
			L2_IN2 =0;		//左电极正极 
			L2_IN3 =1;		//右电机正极 
			L2_IN4 =0;
}
void Right()
{
			push_l=12;
			push_r=12;
			L2_IN1 =0;    //左电机负极 
			L2_IN2 =1;		//左电极正极 
			L2_IN3 =0;		//右电机正极 
			L2_IN4 =1;
}
void Run()
{
			push_l=12;
			push_r=12;
			L2_IN1 =0;    //左电机负极 
			L2_IN2 =1;		//左电极正极 
			L2_IN3 =1;		//右电机正极 
			L2_IN4 =0;
}
void Stop()
{
			push_l=0;
			push_r=0;
			L2_IN1 =0;    //左电机负极 
			L2_IN2 =0;		//左电极正极 
			L2_IN3 =0;		//右电机正极 
			L2_IN4 =0;
}

int main()
{
		TMOD |=0x02;
		TH0=0XFc;   //1ms定时
		TL0=0X18;
		TR0=1;
		ET0=1;
		EA=1; 
		while(1)
		{
			if(RED_R==0 && RED_L==0)	Run();
			else if(RED_R==1 && RED_L==0)	Right();
			else if(RED_R==0 && RED_L==1)	Left();
			else if(RED_R==1 && RED_L==1) Stop();
		}
}