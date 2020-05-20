#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//栈的开口向上向下（向上即内存地址递增），测试release（向上）1debug（向下）
//一般认为:栈开口向下

//不管栈开口向上向下，buf的内存地址buf+1仍然是向上的
void main07()
{
	int a;
	int b;
	
	
	char buf[128];//编译的时候，buf所代表的内存空间的标号 就已经定义下来了
	printf("&a:%d,&b:%d\n", &a, &b);

	return;
}