#include <stdio.h>

char *dispchar[]={"A","B","C","D","E","F","G","A","B","C","D","E","F","G","A","B","C","D","E","F","G","A","B","C","D","E","F","G","A","B","C","D","E","F","G","A","B","C","D","E","F","G"};

int main()
{
	
	
	
	printf("sizeof char[] = %d\n",sizeof(dispchar));

	/*
    char c;
    c = getchar();                      //��Ϊ�±�Ҫʹ�ü򵥵�whileѭ������c���������г�ʼֵ
	
    while (c != EOF) {                //���c������EOF���ı���������shell���ctrl+d �˴��ġ���=�����ǲ��������˼�����ǡ�==������һֱѭ����ȥ
        putchar(c);                        //ѭ���彫c��ֵ��putchar�����������Ļ 
        c = getchar();                    //������ȡc��ֵ��Ȼ�������һ�ε�ѭ��
    }
	*/
	return 0;
	
}