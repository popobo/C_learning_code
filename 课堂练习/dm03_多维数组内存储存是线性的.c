#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void printArrayduoweishuzuxianxing(int*Array,int size)
{
	for (int i = 0; i < size; ++i)
	{
		printf("%d", *(Array + i));
	}
}

int mainduoweishuzuxianxing()
{
	int a[3][5];
	int temp = 1;
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 5; ++j) 
		{
			a[i][j] = temp++;
		}
	}
	printArrayduoweishuzuxianxing((int*)a, 15);
	//把二维数组 当成 一维数组打印 证明线性存储
	system("pause");
	return 0;
}