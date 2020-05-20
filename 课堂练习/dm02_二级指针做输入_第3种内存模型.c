#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char**getMemErJiZhiZhenMoXing3(int num)
{
	char**arr = NULL;
	arr = (char**)malloc(sizeof(char*)*num);
	if (arr == NULL)
	{
		return NULL;
	}
	for (int i = 0; i < num; i++)
	{
		arr[i] = (char*)malloc(sizeof(char) * 100);//char buf[100]
		sprintf_s(arr[i], 100, "%d%d%d", i + 1, i + 1, i + 1);
	}
	return arr;
}


int FreeMemErJiZhiZhenMoXing3(char**arr, int num)
{
	if (arr == NULL)
	{
		printf("FreeMemErJiZhiZhenMoXing3 Error");
		return -1;
	}
	for (int i = 0; i < num; i++)
	{
		if (arr[i] != NULL)
		{
			free(arr[i]);
			arr[i] = NULL;
		}
	}
	if (arr != NULL)
	{
		free(arr);
		arr = NULL;
	}
	return 0;
}
int PrintArrErJiZhiZhenMoXing3(char**arr, int num)
{
	if (arr == NULL)
	{
		printf("PrintArr Error");
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

int SortArrErJiZhiZhenMoXing3(char**arr, int num)
{
	if (arr == NULL)
	{
		printf("SortArr Error");
		return -1;
	}
	char**temp = NULL;
	char*etemp = NULL;
	char buf[100] = { '\0' };
	temp = arr;
	for (int i = 0; i < num; ++i)
	{
		for (int j = i + 1; j < num; ++j)
		{
			if (strcmp(temp[i], temp[j]) < 0)
			{
				/*etemp = temp[i];//交换指针的值即交换指针的指向
				temp[i] = temp[j];
				temp[j] = etemp;*/
				strcpy_s(buf, 100, temp[i]);//交换内存的值
				strcpy_s(temp[i], 100, temp[j]);
				strcpy_s(temp[j], 100, buf);
			}
		}
	}
	return 0;
}

void mainErJiZhiZhenMoXing3()
{
	int ret = 0;
	char**p2 = NULL;
	int num = 5;
	p2 = getMemErJiZhiZhenMoXing3(num);
	//p2 = (char**)malloc(sizeof(char*)*num);
	//char*temp;
	//for (int i = 0; i < num; i++)
	//{
	//	p2[i] = (char*)malloc(sizeof(char) * 100);//char buf[100]
	//	sprintf_s(p2[i], 100, "%d%d%d", i + 1, i + 1, i + 1);
	//}
	//排序之前
	//for (int i = 0; i < num; i++)
	//{
	//	printf("%s\n", p2[i]);
	//}
	printf("排序前:\n");
	ret = PrintArrErJiZhiZhenMoXing3(p2, num);
	if (ret == -1)
	{
		printf("Error");
		return;
	}
	//for (int i = 0; i < num;++i)
	//{
	//	for (int j = i + 1; j < num;++j)
	//	{
	//		if (strcmp(p2[i], p2[j])>0)
	//		{
	//			temp = p2[i];
	//			p2[i] = p2[j];
	//			p2[j] = temp;
	//		}
	//	}
	//}
	ret = SortArrErJiZhiZhenMoXing3(p2, num);
	if (ret == -1)
	{
		printf("Error");
		return;
	}
	//for (int i = 0; i < num; i++)
	//{
	//	printf("%s\n", p2[i]);
	//}
	printf("排序后:\n");
	ret = PrintArrErJiZhiZhenMoXing3(p2, num);
	if (ret == -1)
	{
		printf("Error");
		return;
	}
	//for (int i = 0; i < num; i++)
	//{
	//	if (p2[i] != NULL)
	//	{
	//		free(p2[i]);
	//		p2[i] = NULL;
	//	}
	//}
	//if (p2 != NULL)
	//{
	//	free(p2);
	//	p2 = NULL;
	//}
	ret = FreeMemErJiZhiZhenMoXing3(p2, num);//p2是一个野指针
	if (ret == -1)
	{
		printf("Error");
		return;
	}
	return;
}