#define _CRT_SECURE_NO_WARNINGS  
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int sort61(char**myp1, int num1, char(*myp2)[30], int num2, char***myp3, int*num3)
{
	int len3 = num1 + num2;
	char temp[30] = { '\0' };
	char**p3 = (char**)malloc(sizeof(char*)*len3);
	if (p3 == NULL) 
	{
		printf("sort61 error");
		return -1;
	}
	for (int i = 0; i < len3; ++i) 
	{
		p3[i] = (char*)malloc(30);
		if (p3 == NULL)
		{
			printf("sort61 error");
			return -1;
		}
	}
	for (int i = 0; i < num1; ++i)
	{
		strcpy(p3[i], myp1[i]);
	}
	for (int i = 0; i < num2; ++i) 
	{
		strcpy(p3[i + num1], myp2[i]);
	}
	for (int i = 0; i < len3; ++i) 
	{
		for (int j = i + 1; j < len3; ++j) 
		{
			if (strcmp(p3[i], p3[j]) > 0) 
			{
				strcpy(temp, p3[i]);
				strcpy(p3[i], p3[j]);
				strcpy(p3[j], temp);
			}
		}
	}
	*myp3 = p3;
	*num3 = len3;
	return 0;
}

int freemem61(char***myp,int num)
{
	char**temp = *myp;
	for (int i = 0; i < num; ++i) 
	{
		free(temp[i]);
	}
	free(temp);
	*myp = NULL;
}
int main61()
{
	int ret = 0;
	char*p1[] = { "aaaaa","bbbbb","cccccc" };
	char p2[10][30] = {"dddddd","222222","1111111"};
	char**p3 = NULL;
	int len1 = 0, len2 = 0, len3 = 0;

	ret = sort61(p1, 3, p2, 3, &p3, &len3);
	if (ret != 0)
	{
		printf("Error");
	}
	else
	{
		for (int i = 0; i < len3; ++i) 
		{
			printf("%s\n", p3[i]);
		}
	}
	freemem61(&p3, len3);
	system("pause");
	return 0;
}