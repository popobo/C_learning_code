#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//��ӡ
int PrinArr1(char**arr, int num)
{
	if (arr == NULL)
	{
		printf("PrinArr1 Error");
		return -1;
	}
	char**temp = arr;
	//����ı�����dm02_����ָ��������_��2���ڴ�ģ�� ��myArray+1
	//�� dm02_����ָ��������_��1���ڴ�ģ�� ��myArray+1 ��һ��
	//ָ��Ĳ�����һ�� ָ����ָ����ڴ�ռ���������Ͳ�һ��
	for (int i = 0; i < num; ++i)
	{
		printf("%s\n", temp[i]);
	}
}

int PrinArr2(char arr[10][30], int num)
{
	if (arr == NULL)
	{
		printf("PrinArr1 Error");
		return -1;
	}
	//char**temp = arr;
	//����ı�����dm02_����ָ��������_��2���ڴ�ģ�� ��myArray+1
	//�� dm02_����ָ��������_��1���ڴ�ģ�� ��myArray+1 ��һ��
	//ָ��Ĳ�����һ�� ָ����ָ����ڴ�ռ���������Ͳ�һ��
	for (int i = 0; i < num; ++i)
	{
		printf("%s\n", arr[i]);
	}
}

int SortArr1(char arr[10][30], int num)
{
	if (arr == NULL)
	{
		printf("SortArr1 Error");
		return -1;
	}
	//char**temp = NULL;
	char p[30] = { '\0' };
	for (int i = 0; i < num;++i)
	{
		for (int j = i; j < num; ++j)
		{
			if (strcmp(arr[i], arr[j])>0)
			{
				//p = arr[i];
				//arr[i] = arr[j];
				//arr[j] = p;
				strcpy_s(p, 30, arr[i]);//���������ڴ��
				strcpy_s(arr[i], 30, arr[j]);
				strcpy_s(arr[j], 30, p);
			}
		}
	}
	return 0;
}
void maindm02erjizhizhen2()
{
	int num = 4;
	char myBuf[30];
	char myArray[10][30] = { "aaaaaa", "bbbbbbb", "111111111", "ddddddddd" };
	//������ֻ����� ��10��ÿ��30�� Ϊʲô�� myArray+1 �������30���ֽ� ��ά�������ı���
	{
		int len1 = sizeof(myArray);
		int len2 = sizeof(myArray[0]);
		int size = len1 / len2;
		printf("len1:%d,len2:%d,size:%d\n", len1, len2, size);
	}
	PrinArr2(myArray, num);
	SortArr1(myArray, num);
	PrinArr2(myArray, num);
	return;
}