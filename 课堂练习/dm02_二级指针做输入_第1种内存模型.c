#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int PrintMyarr(char*arr[], int num)
{
	if (arr == NULL)
	{
		printf("PrintMyarr Error");
		return -1;
	}
	char**temp = NULL;
	temp = arr;
	for (int i = 0; i < num; ++i)
	{
		printf("%s\n", temp[i]);
	}
	return 0;
}

int SortArr(char*arr[], int num)
{
	if (arr == NULL)
	{
		printf("SortArr Error");
		return -1;
	}
	char**temp1 = arr;
	char*temp2;
	for (int i = 0; i < num; ++i)
	{
		for (int j = i; j < num; ++j)
		{
			//if (temp1[i] > temp1[j])//这样比较是对指针值进行比较
			if (strcmp(temp1[i], temp1[j]) > 0)//这样才是对指针所指向的字符串进行比较
			{
				temp2 = temp1[i];//注意 交换的是数组元素 交换的是指针的值
				temp1[i] = temp1[j];
				temp1[j] = temp2;
			}
		}
	}
	return 0;
}
void maindm02erjizhizhen1()
{
	int i = 0, j = 0;
	int num = 0;
	//数组 数组中每一个元素是指针 指针数组
	char*myarr[] = { "ccccccc", "bbbbb", "111111" };
	char**p = myarr;
	char*temp = NULL;
	//打印
	num = sizeof(myarr) / sizeof(myarr[0]);
	PrintMyarr(myarr, num);
	SortArr(myarr, num);
	printf("排序之后:\n");
	PrintMyarr(myarr, num);
	return;
}

//void maindm141()
//{
//	int i = 0, j = 0;
//	int num = 0;
//	//数组 数组中每一个元素是指针 指针数组
//	char*myarr[] = { "aaaaa", "bbbbb", "111111" };
//	char**p = myarr;
//	char*temp = NULL;
//	//打印
//	num = sizeof(myarr) / sizeof(myarr[0]);
//	for (i = 0; i < num; ++i)
//	{
//		printf("%s\n", p[i]);
//		printf("%s\n", *(p + i));
//	}
//	for (i = 0; i < num; ++i)
//	{
//		for (j = i; j < num; ++j)
//		{
//			if (strcmp(myarr[i], myarr[j])>0)
//			{
//				temp = myarr[i];//注意 交换的是数组元素 交换的是指针的值
//				myarr[i] = myarr[j];
//				myarr[j] = temp;
//			}
//		}
//	}
//	printf("排序之后:\n");
//	for (i = 0; i < num; ++i)
//	{
//		printf("%s\n", p[i]);
//		printf("%s\n", *(p + i));
//	}
//	return;
//}