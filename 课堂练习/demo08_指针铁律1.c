#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void main81()
{
	int a = 10;
	char*p1 = 100;
	char***p2 = 100;
	printf("sizeof(p1)=%d,sizeof(p2)=%d\n",sizeof(p1),sizeof(p2));
	
	int*p3 = NULL;
	p3 = &a;
	*p3 = 5;//间接修改a的值
	//*就像一把钥匙，通过一个地址(&a)去修改a表示的内存空间
	{
		int c = 0;
		c = *p3;//读内存存放的值
	}

	{
		char*p4 = NULL;
		p4 = (char*)malloc(4);
	}

	return;
}

char*getStr()
{
	char*temp = NULL;
	temp = "dafadsa";
	return temp;
}

/*
int getABC1(char*p1);
int getABC2(char**p2);
int getABC3(char***p3);
int getABC4(char(*p4)[30]);
int getABC5(char p5[10][30]);

//指针做函数参数 形参有多级指针的时候
//站在编译器的角度 只需要分配四个字节的内存（32位平台）
//当我们使用内存的时候 我们才关心所指向的内存 是一维的还是二维的
*/

void main082()
{
	char*p = getStr();
	printf("p:%s\n",p);
	//*(p + 2) = 'r';//经常出现的错误，要修改时保证所指向的内存能被修改，常量区的内容无法被修改
	printf("p:%s\n", p);
	return;
}