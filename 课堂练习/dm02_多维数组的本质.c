#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void printArrayduoweishuzuming(int a[3][5])
{
	int i = 0, j = 0;
	for (i = 0; i < 3; ++i)
	{
		for (j = 0; j < 5; ++j)
		{
			printf("%d ", a[i][j]);
		}
	}
}
//退化为一个数组指针
void printArrayduoweishuzuming1(int(*a)[5])
{
	int i = 0, j = 0;
	for (i = 0; i < 3; ++i)
	{
		for (j = 0; j < 5; ++j)
		{
			printf("%d ", a[i][j]);
		}
	}
}

//多维数组做函数参数 退化过程....事实存在
//为什么退化
int mainduoweishuzuming1()
{
	int a[3][5];
	int i = 0, j = 0, temp = 1;
	for (i = 0; i < 3; ++i) 
	{
		for (j=0;j<5;++j)
		{
			a[i][j] = temp++;
		}
	}
	printArrayduoweishuzuming(a);
	printf("\n-------------\n");
	printArrayduoweishuzuming1(a);
	printf("\n-------------\n");
	for (i = 0; i < 3; ++i)
	{
		for (j = 0; j < 5; ++j)
		{
			printf("%d ", a[i][j]);
		}
	}

	//多维数组名 代表?
	printf("a %d a+1 %d\n", a, a + 1); //a+1的步长是20个字节 5*4
	printf("&a %d &a+1 %d\n", &a, &a + 1);

	//定义一个指向数组的指针变量
	int(*pArray)[5];

	pArray = a;
	for (i = 0; i < 3; ++i)
	{
		for (j = 0; j < 5; ++j)
		{
			printf("%d ", pArray[i][j]);
		}
	}
	//多维数组名的本质 数组指针 步长 一维的长度
	//(a+i)代表是整个第i行的首地址 二级指针
	//*(a+i)代表第i行首元素的地址 一级指针
	//*(a+i)+j ==> &a[i][j]
	//只不过第i行的地址和第i行首元素的地址是重叠的
	
	//a[i][j] ==>a[0+i][j] ==> *(a+i)[0+j] ==> *(*(a+i)+j)

	system("pause");
	return 0;
}