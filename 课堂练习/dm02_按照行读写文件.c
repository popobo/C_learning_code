#define _CRT_SECURE_NO_WARNINGS  
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main621()
{
	FILE*fp = NULL;
	char*filename = "b.txt";
	fp = fopen(filename, "r+"); //读写(r+)模式 如果文件不存在报错
	//fp = fopen(filename, "w+"); //写读(w+)模式 如果文件不存在建立文件
	char a[27] = "asddsadasdffas123";
	if (fp == NULL)
	{
		printf("fopen() error");
		system("pause");
		return -1;
	}
	printf("打开成功");
	fputs(a, fp);

	if (fp != NULL)
	{
		fclose(fp);
	}

	system("pause");
	return 0;
}

//1.C函数库会一行一行地copy数据到buf指针所指的内存空间中 并且变成C风格的字符串
//2.把\n也拷贝到我们的buf中(如果超过MaxCount,只会拷贝MaxCount-1,MaxCount位置使用/n代替)
//3.内存打包(把内存首地址+内存长度 buf 1024)
int main622()
{
	FILE*fp = NULL;
	char*filename = "a.txt";
	fp = fopen(filename, "r+"); //读写(r+)模式 如果文件不存在报错
	//fp = fopen(filename, "w+"); //写读(w+)模式 如果文件不存在建立文件
	char a[27] = "asddsadasdffas123";
	char buf[1024];
	if (fp == NULL)
	{
		printf("fopen() error");
		system("pause");
		return -1;
	}
	printf("打开成功");
	char*tempp = NULL;
	while (!feof(fp)) 
	{
		tempp = fgets(buf, 1024, fp); //C函数库会 一行一行的copy数据到buf所指向的内存空间 形成C风格的字符串
		if (tempp == NULL)
		{
			goto End;
		}
		printf("%s", buf);
	
	}
End:
	if (fp != NULL)
	{
		fclose(fp);
	}

	system("pause");
	return 0;
}