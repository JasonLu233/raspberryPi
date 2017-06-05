#include <stdio.h>
#include <time.h>
#include <string.h> 

int main()  
{  

	char *wday[]={"Sun","Mon","Tue","Wed","Thu","Fri","Sat"};
    time_t timep;  
    struct tm *p;  
    time(&timep);
    p=localtime(&timep);
    printf("Year:  %d\n", 1900+p->tm_year);  
    printf("Month:  %d\n", 1+p->tm_mon);  
    printf("Day:  %d\n", p->tm_mday);  
    printf("Hour:  %d\n", p->tm_hour);  
    printf("Minute:  %d\n", p->tm_min);  
    printf("Second:  %d\n",  p->tm_sec);  
    printf("Weekday:  %s\n", wday[p->tm_wday]);  
    printf("Days:  %d\n", p->tm_yday);  
    printf("Isdst:  %d\n", p->tm_isdst);  
	/*
    time_t timep;  
    char s[30];  
      
    time(&timep);  
  
    strcpy(s,ctime(&timep));  
  
    printf("%s\n", s);  
	*/
 
} 