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
	printf("�򿪳ɹ�");
	for (int i = 0; i < strlen(a); ++i) 
	{
		fputc(a[i],fp); //fputs��fputc��һ��
	}
	fclose(fp);
	printf("д�ɹ�");
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
	printf("�򿪳ɹ�");
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
	
	printf("д�ɹ�");
	system("pause");
	return 0;
}