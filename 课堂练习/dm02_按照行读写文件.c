#define _CRT_SECURE_NO_WARNINGS  
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main621()
{
	FILE*fp = NULL;
	char*filename = "b.txt";
	fp = fopen(filename, "r+"); //��д(r+)ģʽ ����ļ������ڱ���
	//fp = fopen(filename, "w+"); //д��(w+)ģʽ ����ļ������ڽ����ļ�
	char a[27] = "asddsadasdffas123";
	if (fp == NULL)
	{
		printf("fopen() error");
		system("pause");
		return -1;
	}
	printf("�򿪳ɹ�");
	fputs(a, fp);

	if (fp != NULL)
	{
		fclose(fp);
	}

	system("pause");
	return 0;
}

//1.C�������һ��һ�е�copy���ݵ�bufָ����ָ���ڴ�ռ��� ���ұ��C�����ַ���
//2.��\nҲ���������ǵ�buf��(�������MaxCount,ֻ�´��MaxCount-1,MaxCountλ��ʹ��/n����)
//3.�ڴ���(���ڴ��׵�ַ+�ڴ泤�� buf 1024)
int main622()
{
	FILE*fp = NULL;
	char*filename = "a.txt";
	fp = fopen(filename, "r+"); //��д(r+)ģʽ ����ļ������ڱ���
	//fp = fopen(filename, "w+"); //д��(w+)ģʽ ����ļ������ڽ����ļ�
	char a[27] = "asddsadasdffas123";
	char buf[1024];
	if (fp == NULL)
	{
		printf("fopen() error");
		system("pause");
		return -1;
	}
	printf("�򿪳ɹ�");
	char*tempp = NULL;
	while (!feof(fp)) 
	{
		tempp = fgets(buf, 1024, fp); //C������� һ��һ�е�copy���ݵ�buf��ָ����ڴ�ռ� �γ�C�����ַ���
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