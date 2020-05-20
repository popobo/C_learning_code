#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int getMemDm03DuoJiZhiZhen(char***arrout, int num)
{
	if (arrout == NULL)
	{
		printf("getMemDm03DuoJiZhiZhen Error");
		return -1;
	}
	char**arr = NULL;
	arr = (char**)malloc(sizeof(char*)*num);
	if (arr == NULL)
	{
		printf("getMemDm03DuoJiZhiZhen Error");
		return -1;
	}
	for (int i = 0; i < num; i++)
	{
		arr[i] = (char*)malloc(sizeof(char) * 100);//char buf[100]
		sprintf_s(arr[i], 100, "%d%d%d", i + 1, i + 1, i + 1);
	}
	*arrout = arr;
	return 0;
}

int PrintArrDm03DuoJiZhiZhen(char**arr, int num)
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

int FreeMemDm03DuoJiZhiZhen(char***arrin, int num)
{
	if (arrin == NULL)
	{
		printf("FreeMemDm03DuoJiZhiZhen Error");
		return -1;
	}
	char**temp = NULL;
	temp = *arrin;
	for (int i = 0; i < num; ++i)
	{
		free(temp[i]);//找bug要一步步从头找
		temp[i] = NULL;
	}
	free(temp);
	//temp = NULL;temp只是和*arrin的值相同 修改temp并不能修改*arrin 修改*arrin才能真正修改main里的arr 
	*arrin = NULL;
	return 0;
}

void mainDm03DuoJiZhiZhen()
{
	int ret = 0;
	char**arr = NULL;
	int num = 5;
	ret = getMemDm03DuoJiZhiZhen(&arr, num);
	if (ret == -1)
	{
		printf("Error");
		return;
	}
	ret = PrintArrDm03DuoJiZhiZhen(arr, num);
	if (ret == -1)
	{
		printf("Error");
		return;
	}
	ret = FreeMemDm03DuoJiZhiZhen(&arr, num);
	if (ret == -1)
	{
		printf("Error");
		return;
	}
	system("pause");
	return;
}