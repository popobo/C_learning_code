#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int getNoSpaceCount(char*str, int*ncount)
{
	if (str == NULL || ncount == NULL)
	{
		return -1;
	}
	char*tempstr = str;
	int mycount = 0;
	int i = 0, j = 0;
	j = strlen(str) - 1;
	while (isspace(tempstr[i]) && tempstr[i] != '\0')
	{
		i++;
	}
	while (isspace(tempstr[j]) && tempstr[j] != '\0')
	{
		j--;
	}
	mycount = j - i + 1;
	*ncount = mycount;
	return 0;
}

//去除字符串前后的空格
int trimSpace(char*str, char*buf)
{
	if (str == NULL || buf == NULL)
	{
		return -1;
	}
	char*tempstr = str;
	int mycount = 0;
	int i = 0, j = 0;
	j = strlen(str) - 1;
	while (isspace(tempstr[i]) && tempstr[i] != '\0')
	{
		i++;
	}
	while (isspace(tempstr[j]) && tempstr[j] != '\0')
	{
		j--;
	}
	mycount = j - i + 1;
	strcpy_s(buf, 50, str + i, mycount);
	buf[mycount] = '\0';
	return 0;
}

void maindm090()
{
	//求非空格字符串长度
	char*p = "    aaaaffgf    ";
	char*buf = (char*)malloc(50);
	int i = 0, j = 0;
	j = strlen(p) - 1;
	int ncount = 0;

	while (isspace(p[i]) && p[i] != '\0')
	{
		i++;
	}
	while (isspace(p[j]) && p[j] != '\0')
	{
		j--;
	}
	//ncount = j - i + 1;
	getNoSpaceCount(p, &ncount);
	printf("%d\n", ncount);
	trimSpace(p, buf);
	printf("%s\n", buf);
	return;
}
//str所指向的内存空间能够被修改才行
int trimSpace02(char*str)
{
	if (str == NULL)
	{
		return -1;
	}
	char*tempstr = str;
	int mycount = 0;
	int i = 0, j = 0;
	j = strlen(str) - 1;
	while (isspace(tempstr[i]) && tempstr[i] != '\0')
	{
		i++;
	}
	while (isspace(tempstr[j]) && tempstr[j] != '\0')
	{
		j--;
	}
	mycount = j - i + 1;
	strcpy_s(str, 50, str + i, mycount);
	str[mycount] = '\0';
	return 0;
}

void maindm091()
{	
	char str[100] = "    aaaaffgf    ";
	trimSpace02(str);
	printf("%s\n", str);
	return;
}


