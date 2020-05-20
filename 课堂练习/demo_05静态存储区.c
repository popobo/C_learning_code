#include<stdio.h>
#include<malloc.h>


char* getStr1()
{	//1、指针指向谁就把谁的地址赋给指针
	char*p1 = "adsdda";//字符串常量在全局区，由系统释放
	return p1;
}
char* getStr2()
{
	char*p2 = "adsdda";
	return p2;
}

void main()
{
	char* p1 = getStr1();//2、指针变量和它所指向的内存空间变量是两个不同的概念
	char* p2 = getStr2();

	//打印p1,p2所指向内存的数据
	printf("p1:%s,p2:%s\n", p1, p2);
	//打印p1,p2的值
	//即使整个程序中存在多个相同常量，编译器也只会在静态存储区保留一份
	printf("p1:%d,p2:%d\n", p1, p2);
	system("pause");
}