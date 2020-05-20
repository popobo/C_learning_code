#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int maindm01ShuZuJiChu()
{
	int a[] = { 1,2 };
	int b[100] = { 1,2 };
	int c[200] = { 0 };//编译的时候 就已经确定所有的值为 0

	memset(c, 0, sizeof(c));//显示地重置内存块
	//对一维数组 C规定:
	//c 是数组首元素的地址 c+1 步长 4个字节
	//&c 是整个数组的地址  &c+1 步长 200*4
	

	system("pause");
	return 0;
}

//怎样表达int a[10]这种数据类型呢?int[]
//类型本质 固定大小内存块的别名
//定义数组类型
//int main()
void maindm01ShuZuJiChu1()
{
	typedef int(MyArrayType)[5];
	MyArrayType myArray;//相当于int myArray[5];
	
	for (int i = 0; i < 5; ++i) 
	{
		myArray[i] = i + 1;
		printf("%d\n", myArray[i]);
	}

	printf("maArray代表数组首元素的地址 myArray:%d myArray+1:%d\n", myArray, myArray + 1);
	printf("&maArray代表数组首元素的地址 &myArray:%d &myArray+1:%d\n", &myArray, &myArray + 1);
	system("pause");
}

//定义数组指针变量的方法1:
//用数组类型加*定义
int maindm01ShuZuJiChu2()
{
	char*myArray[] = { "aaaa","bbbb","cccc" };//指针数组

	typedef int(MyArrayType)[5];
	MyArrayType myArray0;//相当于int myArray[5]; //用类型定义变量

	MyArrayType*pArray;//定义一个指针变量 这个指针变量 指向一个数组

	{
		int a;
		int*p = NULL;
		p = &a;
	}
	{
		
		MyArrayType myArray1;
		pArray = &myArray1;
		for (int i = 0; i < 5; i++) 
		{
			//myArray1[i] = i + 1;
			(*pArray)[i] = i + 1;
		}
		for (int i = 0; i < 5; ++i)
		{
			printf("%d\n", (*pArray)[i]);
		}

	}

	system("pause");
	return 0;
}
//定义数组指针变量的方法2

int maindm01ShuZuJiChu3()
{
	//定义一个数组指针类型
	typedef int(*PMyArray)[5];
	PMyArray pArray;//告诉编译器给我分配一个指针变量
	int c[5];
	pArray = &c;
	for (int i = 0; i < 5; ++i) 
	{
		(*pArray)[i] = i + 1;
		printf("%d\n", (*pArray)[i]);
	}
	system("pause");
	return 0;
}

//定义数组指针变量的方法3
//前两种方法 通过类型定义变量 比较麻烦
void maindm01ShuZuJiChu4()
{
	int(*pArray)[5];//直接定义的一个指向数组 的指针变量

	int c[5];
	pArray = &c;
	for (int i = 0; i < 5; ++i)
	{
		(*pArray)[i] = i + 1;
		printf("%d\n", (*pArray)[i]);
	}
	system("pause");
	return;
}