#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//野指针产生的原因
//指针变量和它所指向的内存空间变量是两个不同的概念
//释放了指针所指的内存空间 但是指针变量本身没有重置成NULL

void maindm01()
{
	char*p1 = NULL;
	p1 = (char*)malloc(100);
	if (p1 == NULL)
	{
		return;
	}
	strcpy_s(p1, 100 ,"asdsaasddasd");
	printf("p1:%s\n", p1);
	//if (p1 != NULL)
	//{
	//	free(p1);
	//}//这样就造成了野指针
	
	if (p1 != NULL)
	{
		free(p1);
		p1 = NULL;
	}
	if (p1 != NULL)
	{
		free(p1);
		p1 = NULL;
	}
	return;
}





