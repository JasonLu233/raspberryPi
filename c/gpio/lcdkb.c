#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <iconv.h>
#include <string.h>
#include <wiringPi.h> 
#include <time.h>

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

uchar u2g_out[255];
char *wday[]={"Sun","Mon","Tue","Wed","Thu","Fri","Sat"};
char *dispchar[]={"A","B","C","D","E","F","G","A","B","C","D","E","F","G","A","B","C","D","E","F","G","A","B","C","D","E","F","G","A","B","C","D","E","F","G","A","B","C","D","E","F","G"};
/*===================================================================
功能：编码转换
输入：UTF8
输出：GB2312
====================================================================*/
int code_convert(char *from_charset, char *to_charset, char *inbuf, int inlen, char *outbuf, int outlen)
{
	iconv_t cd;
	int rc;
	char **pin = &inbuf;
	char **pout = &outbuf;

	cd = iconv_open(to_charset, from_charset);

	if (cd == 0) 
	return 1;

	memset(outbuf,0,outlen);

	if (iconv(cd, pin, &inlen, pout, &outlen) == -1) 
	return 1;

	iconv_close(cd);
	return 0;
}

int u2g(char *inbuf,int inlen,char *outbuf,int outlen){
	return code_convert("utf-8","gb2312",inbuf,inlen,outbuf,outlen);
}

/*=================================================================*/
void sendbyte(uchar data)
{
	uint i;
	for(i=0;i<8;i++)
	{
		digitalWrite(sclk,1);
		delayMicroseconds(1);
		if((data<<i)&0x80)
		{
			digitalWrite(sid,1);
		}else
		{
			digitalWrite(sid,0);
		}
		digitalWrite(sclk,0);
		delayMicroseconds(1);
		
	}
	
}

void write_com(uchar cmd)
{
	digitalWrite(cs,1);
	sendbyte(0xf8);
	sendbyte(cmd&0xf0);
	sendbyte((cmd << 4)&0xf0);
//	delay(2);
	
}

void write_data(uchar disp)
{
	digitalWrite(cs,1);
	sendbyte(0xfa);
	sendbyte(disp&0xf0);
	sendbyte((disp << 4)&0xf0);
//	delay(2);
	
}

void init()
{
	digitalWrite(rst,0);
	delay(15);
	digitalWrite(rst,1);
	
	write_com(0x30);
	delay(2);
	write_com(0x0c);
	delay(2);
	write_com(0x01);
	delay(5);
	write_com(0x02);
	delay(2);
	write_com(0x0c);
	delay(2);
	printf("init_done\n");
}

void display(unsigned char *s)
{
	uchar *a;
	u2g(s,strlen(s)+1,u2g_out,255);
	a=u2g_out;
//	printf("display tmp a = %s\n",a);
//	printf("display str = %s\n",s);
	while(*a > 0)
	{
		write_data(*a);
		a++;
	}
}

void Test()
{
//	uchar x = 'c';
	write_com(0x80);
	display("Raspberry PI");
//	write_data("测试");
	write_com(0x91);
	
	display("树莓派测试");
//	write_com(0x89);
//	display("ABCDEFG");
//	write_com(0x99);
//	display("优信电子 ");
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

	
	write_com(0x80);
	int i ;
	for (i=0;i<sizeof(dispchar);i++){
		display(dispchar[i]);
		delay(1000);
	}
	return 0;
}
