#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void maindm06()
{
	char buf1[20] = "aaaa";//定义并且初始化
	char buf2[] = "bbbb";//在栈上大小为5
	char*p1 = "1111111";
	char*p2 = malloc(100);
	strcpy_s(p2, 100, "222222222");
	return;
}