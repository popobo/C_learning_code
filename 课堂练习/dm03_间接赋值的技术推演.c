#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int  getFileLen(int*p)
{
	*p = 40;//p的值是a的地址 *a的地址简介修改a的值 
	return 0;
}

int  getFileLen2()
{
	int a = 40;//p的值是a的地址 *a的地址简介修改a的值 
	return a;
}

int  getFileLen3(int b)
{
	b = 40;//p的值是a的地址 *a的地址简介修改a的值 
	return b;
}

void maindm031()
{
	int a = 0;//条件一：定义了两个变量(实参a,另一个变量是形参p)
	int*p = NULL;
	a = 20;
	p = &a;//条件二：建立关联
	*p = 30;//p的值是a的地址//条件三：*p
	printf("a:%d\n", a);
	getFileLen(&a);//把实参取地址传送给形参
	printf("a:%d\n", a);
	getFileLen3(a);
	printf("a:%d\n", a);


	return;
}
void getMemdm03(char**p2)
{
	*p2 = 400;
}

void maindm032()
{
	char*p1 = NULL;
	char**p2 = NULL;
	
	p1 = 0x11;
	p2 = 0x22;

	//直接修改p1的值

	p1 = 0x111;

	//间接修改p1的值

	p2 = &p1;

	*p2 = 100;//间接赋值 p2是p1的地址

	getMemdm03(&p1);

	printf("p1:%d\n", p1);
	
}

int getMem3(char**myp1, int*mylen1, char**myp2, int*mylen2)
{
	int ret = 0;
	
	char*temp1 = (char*)malloc(100);
	strcpy_s(temp1, 30, "asdadasd");
	//间接赋值
	*mylen1 = strlen(temp1);//一级指针
	*myp1 = temp1;//二级指针

	char*temp2 = (char*)malloc(200);
	strcpy_s(temp2, 30, "fafaffafs");
	*mylen2 = strlen(temp2);
	*myp2 = temp2;

	return ret;
}

void maindm033()
{
	char*p1 = NULL;
	int len1 = 0;
	char*p2 = NULL;
	int len = 0;
	getMem3(&p1, &len, &p2, &len);

	printf("p1:%s\n", p1);
	printf("p2:%s\n", p2);

	if (p1 != NULL)
	{
		free(p1);
		p1 = NULL;
	}
	if (p2 != NULL)
	{
		free(p2);
		p2 = NULL;	
	}	
}

void maindm034()
{
	//1 2 3 这三个条件写在同一个函数

	//12写在一块 3单独写在另一个函数==》函数调用

	//1单独写，23写在一块 ==》抛砖==》C++会有
	
	char to[128];
	char from[128];
	printf("%d\n",to);
	printf("%d\n", from);
	char*p1 = from;
	char*p2 = to;
	strcpy_s(from, 50, "dasdasdsada");

	while (*p1!='\0')
	{
		*p2 = *p1;
		p1++;
		p2++;
	}
	*p2 = '\0';
	printf("%s\n",to);

	return;
}
