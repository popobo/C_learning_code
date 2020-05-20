#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//打印
int PrinArr1(char**arr, int num)
{
	if (arr == NULL)
	{
		printf("PrinArr1 Error");
		return -1;
	}
	char**temp = arr;
	//问题的本质是dm02_二级指针做输入_第2种内存模型 的myArray+1
	//与 dm02_二级指针做输入_第1种内存模型 的myArray+1 不一样
	//指针的步长不一样 指针所指向的内存空间的数据类型不一样
	for (int i = 0; i < num; ++i)
	{
		printf("%s\n", temp[i]);
	}
}

int PrinArr2(char arr[10][30], int num)
{
	if (arr == NULL)
	{
		printf("PrinArr1 Error");
		return -1;
	}
	//char**temp = arr;
	//问题的本质是dm02_二级指针做输入_第2种内存模型 的myArray+1
	//与 dm02_二级指针做输入_第1种内存模型 的myArray+1 不一样
	//指针的步长不一样 指针所指向的内存空间的数据类型不一样
	for (int i = 0; i < num; ++i)
	{
		printf("%s\n", arr[i]);
	}
}

int SortArr1(char arr[10][30], int num)
{
	if (arr == NULL)
	{
		printf("SortArr1 Error");
		return -1;
	}
	//char**temp = NULL;
	char p[30] = { '\0' };
	for (int i = 0; i < num;++i)
	{
		for (int j = i; j < num; ++j)
		{
			if (strcmp(arr[i], arr[j])>0)
			{
				//p = arr[i];
				//arr[i] = arr[j];
				//arr[j] = p;
				strcpy_s(p, 30, arr[i]);//交换的是内存块
				strcpy_s(arr[i], 30, arr[j]);
				strcpy_s(arr[j], 30, p);
			}
		}
	}
	return 0;
}
void maindm02erjizhizhen2()
{
	int num = 4;
	char myBuf[30];
	char myArray[10][30] = { "aaaaaa", "bbbbbbb", "111111111", "ddddddddd" };
	//编译器只会关心 有10行每行30列 为什么？ myArray+1 会往后调30个字节 多维数组名的本质
	{
		int len1 = sizeof(myArray);
		int len2 = sizeof(myArray[0]);
		int size = len1 / len2;
		printf("len1:%d,len2:%d,size:%d\n", len1, len2, size);
	}
	PrinArr2(myArray, num);
	SortArr1(myArray, num);
	PrinArr2(myArray, num);
	return;
}