#define _CRT_SECURE_NO_WARNINGS  
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//ֱ�Ӱ��ڴ�����д�뵽�ļ���
typedef struct Teacher 
{
	char name[64];
	int age;
}Teacher;
int main631()
{
	FILE*fp = NULL;
	char*filename = "c.data";
	fp = fopen(filename, "wb"); 
	if (fp == NULL)
	{
		printf("fopen() error");
		system("pause");
		return -1;
	}
	Teacher TArray[3];
	memset(TArray, 0, sizeof(TArray));
	for (int i = 0; i < 3; ++i)
	{
		sprintf(TArray[i].name,"%d%d%d",i+i,i+1,i+1);
		TArray[i].age = i + 31;
	}
	int myN = 0;
	for (int i = 0; i < 3; ++i) 
	{
		//�ڴ��Ŀ�ʼ �ڴ������� д���ٴ� �ļ�ָ��
		//��������ֵ myN�жϴ�����û��д��
		myN = fwrite(&TArray[i], sizeof(Teacher), 1, fp);
	}
	if (fp != NULL) 
	{
		fclose(fp);
	}
	printf("�򿪳ɹ�");
	system("pause");
	return 0;
}
int main632()
{
	FILE*fp = NULL;
	char*filename = "c.data";
	fp = fopen(filename, "rb");
	if (fp == NULL)
	{
		printf("fopen() error");
		system("pause");
		return -1;
	}
	Teacher TArray[3];
	memset(TArray, 0, sizeof(TArray));
	int myN = 0;
	for (int i = 0; i < 3; ++i)
	{
		myN = fread(&TArray[i],sizeof(Teacher), 1, fp);
	}
	for (int i = 0; i < 3; ++i) 
	{
		printf("%s\n%d\n", TArray[i].name, TArray[i].age);
	}
	if (fp != NULL)
	{
		fclose(fp);
	}
	printf("�򿪳ɹ�");
	system("pause");
	return 0;
}