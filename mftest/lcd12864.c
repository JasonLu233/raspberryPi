#include<stdio.h>
#include<wiringPi.h>

#define uchar unsigned char
#define uint unsigned int

#define cs 21
#define sid 22
#define sclk 23
#define rst 24
#define ch 25

/*
void chkstatus()
{
	
}
*/

void sendbyte(uchar data)
{
	uint i;
	for(i=0;i<8;i++)
	{
		digitalWrite(sclk,1);
		
		if((data<<i)&0x80)
		{
			digitalWrite(sid,1);
		}else
		{
			digitalWrite(sid,0);
		}
		digitalWrite(sclk,0);
		
		
	}
	
}

void write_com(uchar cmd)
{
	digitalWrite(cs,1);
	sendbyte(0xf8);
	sendbyte(cmd&0xf0);
	sendbyte((cmd << 4)&0xf0);
	delay(2);
	
}

void write_data(uchar disp)
{
	digitalWrite(cs,1);
	sendbyte(0xfa);
	sendbyte(disp&0xf0);
	sendbyte((disp << 4)&0xf0);
	delay(2);
	
}

void init()
{
	digitalWrite(rst,0);
	delay(150);
	digitalWrite(rst,1);
	
	write_com(0x30);
	delay(2);
	write_com(0x0c);
	delay(2);
	write_com(0x01);
	delay(5);
	write_com(0x02);
	delay(1);
	write_com(0x0f);
	delay(1);
	printf("init_done\n");
}

void display(unsigned char *s)
{
	while(*s > 0)
	{
		write_data(*s);
		s++;
	}
}

void Test()
{
	uchar x = 'c';
	write_com(0x90);
	write_data(x);
//	write_com(0x91);
//	display("单片机开发板");
//	write_com(0x89);
//	display("          ");
//	write_com(0x98);
//	display("    东流电子");
}

int main(void){
	
	wiringPiSetup();
	pinMode(cs,OUTPUT);
	pinMode(sid,OUTPUT);
	pinMode(sclk,OUTPUT);
	pinMode(rst,OUTPUT);
	pinMode(ch,OUTPUT);
	digitalWrite(ch,0);
	
	init();
	
	Test();
		
		
	
	return 0;
}
