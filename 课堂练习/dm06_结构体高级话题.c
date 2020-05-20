#define _CRT_SECURE_NO_WARNINGS  
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//一旦结构体定义下来 则结构体中的成员 内存布局就 定下来了
//可以通过 age地址 去求大的结构体的内存地址
typedef struct AdvTeacher
{
	char name[64];
	int age;
	char*pname;
}AdvTeacher;

int main561()
{
	AdvTeacher t1;
	AdvTeacher*p = NULL;
	p - 1;//编译通过 运行通过 这句话 在CPU中计算
	p - 2;
	
	int offsize = (int)&(p->age);
	printf("%d\n", offsize);

	system("pause");
	return 0;
}

void main562()
{
	AdvTeacher t1;
	AdvTeacher*p = NULL;
	p = &t1;


	int offsize = (int)&(((AdvTeacher*)0)->age);//命令编译器按AdvTeacher的方式解释从零开始的内存 按照结构体中定义顺序
	int offsize1 = (int)&(p->age) - (int)p;
	printf("%d\n", offsize);
	printf("%d\n", offsize1);
	printf("p:%d", (int)p);

	system("pause");
	return 0;
}
