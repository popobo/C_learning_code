#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void maindm06()
{
	char buf1[20] = "aaaa";//���岢�ҳ�ʼ��
	char buf2[] = "bbbb";//��ջ�ϴ�СΪ5
	char*p1 = "1111111";
	char*p2 = malloc(100);
	strcpy_s(p2, 100, "222222222");
	return;
}