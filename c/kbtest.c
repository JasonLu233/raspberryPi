#include <stdio.h>

char *dispchar[]={"A","B","C","D","E","F","G","A","B","C","D","E","F","G","A","B","C","D","E","F","G","A","B","C","D","E","F","G","A","B","C","D","E","F","G","A","B","C","D","E","F","G"};

int main()
{
	
	
	
	printf("sizeof char[] = %d\n",sizeof(dispchar));

	/*
    char c;
    c = getchar();                      //因为下边要使用简单的while循环所以c变量必须有初始值
	
    while (c != EOF) {                //如果c不等与EOF（文本结束符，shell里的ctrl+d 此处的“！=”就是不等与的意思等于是“==”）就一直循环下去
        putchar(c);                        //循环体将c的值用putchar函数输出到屏幕 
        c = getchar();                    //继续获取c的值，然后进行下一次的循环
    }
	*/
	return 0;
	
}