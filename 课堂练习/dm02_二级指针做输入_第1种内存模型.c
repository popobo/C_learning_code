#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int PrintMyarr(char*arr[], int num)
{
	if (arr == NULL)
	{
		printf("PrintMyarr Error");
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

int SortArr(char*arr[], int num)
{
	if (arr == NULL)
	{
		printf("SortArr Error");
		return -1;
	}
	char**temp1 = arr;
	char*temp2;
	for (int i = 0; i < num; ++i)
	{
		for (int j = i; j < num; ++j)
		{
			//if (temp1[i] > temp1[j])//�����Ƚ��Ƕ�ָ��ֵ���бȽ�
			if (strcmp(temp1[i], temp1[j]) > 0)//�������Ƕ�ָ����ָ����ַ������бȽ�
			{
				temp2 = temp1[i];//ע�� ������������Ԫ�� ��������ָ���ֵ
				temp1[i] = temp1[j];
				temp1[j] = temp2;
			}
		}
	}
	return 0;
}
void maindm02erjizhizhen1()
{
	int i = 0, j = 0;
	int num = 0;
	//���� ������ÿһ��Ԫ����ָ�� ָ������
	char*myarr[] = { "ccccccc", "bbbbb", "111111" };
	char**p = myarr;
	char*temp = NULL;
	//��ӡ
	num = sizeof(myarr) / sizeof(myarr[0]);
	PrintMyarr(myarr, num);
	SortArr(myarr, num);
	printf("����֮��:\n");
	PrintMyarr(myarr, num);
	return;
}

//void maindm141()
//{
//	int i = 0, j = 0;
//	int num = 0;
//	//���� ������ÿһ��Ԫ����ָ�� ָ������
//	char*myarr[] = { "aaaaa", "bbbbb", "111111" };
//	char**p = myarr;
//	char*temp = NULL;
//	//��ӡ
//	num = sizeof(myarr) / sizeof(myarr[0]);
//	for (i = 0; i < num; ++i)
//	{
//		printf("%s\n", p[i]);
//		printf("%s\n", *(p + i));
//	}
//	for (i = 0; i < num; ++i)
//	{
//		for (j = i; j < num; ++j)
//		{
//			if (strcmp(myarr[i], myarr[j])>0)
//			{
//				temp = myarr[i];//ע�� ������������Ԫ�� ��������ָ���ֵ
//				myarr[i] = myarr[j];
//				myarr[j] = temp;
//			}
//		}
//	}
//	printf("����֮��:\n");
//	for (i = 0; i < num; ++i)
//	{
//		printf("%s\n", p[i]);
//		printf("%s\n", *(p + i));
//	}
//	return;
//}