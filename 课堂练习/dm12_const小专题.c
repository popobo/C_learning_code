#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void getMemdm12(const char*p)
{
	p = 1;
	//*p = 'a';
	return;
}

void getMemdm121(char*const p)
{
	//p = 1;
	*p = 'a';
}

void getMemdm122(const char*const p)
{
	//p = 1;
	//*p = 'a';
}


void maindm13()
{
	char*p = NULL;
	const char*p2 = NULL;
	p2 = 1;
	const int a = 10;//结论：C语言中的const修饰的变量 是假的 C语言中的const是一个冒牌货
	//a = 11;
	int*p1 = NULL;
	p1 = &a;
	*p1 = 100;
	printf("a:%d\n", a);
	return;
}