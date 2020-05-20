#define _CRT_SECURE_NO_WARNINGS  
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main611()
{
	FILE*fp = NULL;
	char*filename = "a.txt";
	fp = fopen(filename, "r+");
	char a[27] = "aaassddccz";
	if (fp == NULL)
	{
		printf("fopen() error");
		system("pause");
		return -1;
	}
	printf("打开成功");
	for (int i = 0; i < strlen(a); ++i) 
	{
		fputc(a[i],fp); //fputs和fputc不一样
	}
	fclose(fp);
	printf("写成功");
	system("pause");
	return 0;
}

int main612()
{
	FILE*fp = NULL;
	char*filename = "a.txt";
	fp = fopen(filename, "r+");
	if (fp == NULL)
	{
		printf("fopen() error");
		system("pause");
		return -1;
	}
	printf("打开成功");
	char tempc = '\0';
	while (!feof(fp)) 
	{
		tempc = fgetc(fp);
		printf("%c", tempc);
	}

	if (fp != NULL)
	{
		fclose(fp);
	}
	
	printf("写成功");
	system("pause");
	return 0;
}