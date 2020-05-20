#include<stdio.h>
#include<malloc.h>

//变量本质：一段连续空间的门牌号
void main04()
{
	int a; 
	int b;
	char* p;
	p = 0xAA11;
	a = 10;//1、直接赋值//cpu里面执行

	//*((int*)7731568) = 200;//2、间接赋值==直接通过内存
	{
		int* p = &a;//间接赋值==通过指针
		*p = 300;
	}
	printf("&a:%d\n",&a);
	printf("a:%d\n", a);
	
	//对内存空间能不能再取别名.... C++引用

}

void sub1()
{

}