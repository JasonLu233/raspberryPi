#include<stdio.h>
#include<wiringPi.h>

#define pin 5
int main(void){
	wiringPiSetup();
	pinMode(pin,OUTPUT);

	while(1){
		digitalWrite(pin,1);
		delay(500);
		digitalWrite(pin,0);
		delay(500);
		printf("TEST!\n");	
		
	}
	return 0;
}
