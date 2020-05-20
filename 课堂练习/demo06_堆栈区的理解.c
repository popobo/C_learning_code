#include<stdio.h>
#include<malloc.h>

//堆
char* getMem(int num)
{
	char*p = NULL;
	p = (char*)malloc(sizeof(num));
	if (p == NULL)
	{
		return NULL;
	}
	return p;
}

//栈
//return不是把内存块64个字节return出来 而是把内存块的的首地址（内存标号）返回出来
//理解指针的关键是内存，没有内存哪来的指针
//
char*getMem2()
{
	char buf[64];//临时变量，栈区存放
	strcpy(buf,"dasdads");
	printf("buf:%s\n", buf);
	return buf;
	//为什么不能返回局部指针变量，却可以返回局部变量
	//函数的局部变量用作返回值时，会生成一个局部变量的拷贝用作返回值，之后局部变量会被系统回收，函数不能返回局部变量的地址，因为如果返回局部变量的地址，系统回收后，指针指向的内容就无意义了，但是对于静态变量也可以返回其指针
}


void main06()
{
	char*temp = getMem(10);
	printf("temp:%s.\n", temp);
	strcpy(temp,"dasdsda");//向temp所指向的内存空间中copy数据
	temp = getMem2();
	printf("temp:%s.\n",temp);

}
