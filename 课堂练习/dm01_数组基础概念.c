#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int maindm01ShuZuJiChu()
{
	int a[] = { 1,2 };
	int b[100] = { 1,2 };
	int c[200] = { 0 };//�����ʱ�� ���Ѿ�ȷ�����е�ֵΪ 0

	memset(c, 0, sizeof(c));//��ʾ�������ڴ��
	//��һά���� C�涨:
	//c ��������Ԫ�صĵ�ַ c+1 ���� 4���ֽ�
	//&c ����������ĵ�ַ  &c+1 ���� 200*4
	

	system("pause");
	return 0;
}

//�������int a[10]��������������?int[]
//���ͱ��� �̶���С�ڴ��ı���
//������������
//int main()
void maindm01ShuZuJiChu1()
{
	typedef int(MyArrayType)[5];
	MyArrayType myArray;//�൱��int myArray[5];
	
	for (int i = 0; i < 5; ++i) 
	{
		myArray[i] = i + 1;
		printf("%d\n", myArray[i]);
	}

	printf("maArray����������Ԫ�صĵ�ַ myArray:%d myArray+1:%d\n", myArray, myArray + 1);
	printf("&maArray����������Ԫ�صĵ�ַ &myArray:%d &myArray+1:%d\n", &myArray, &myArray + 1);
	system("pause");
}

//��������ָ������ķ���1:
//���������ͼ�*����
int maindm01ShuZuJiChu2()
{
	char*myArray[] = { "aaaa","bbbb","cccc" };//ָ������

	typedef int(MyArrayType)[5];
	MyArrayType myArray0;//�൱��int myArray[5]; //�����Ͷ������

	MyArrayType*pArray;//����һ��ָ����� ���ָ����� ָ��һ������

	{
		int a;
		int*p = NULL;
		p = &a;
	}
	{
		
		MyArrayType myArray1;
		pArray = &myArray1;
		for (int i = 0; i < 5; i++) 
		{
			//myArray1[i] = i + 1;
			(*pArray)[i] = i + 1;
		}
		for (int i = 0; i < 5; ++i)
		{
			printf("%d\n", (*pArray)[i]);
		}

	}

	system("pause");
	return 0;
}
//��������ָ������ķ���2

int maindm01ShuZuJiChu3()
{
	//����һ������ָ������
	typedef int(*PMyArray)[5];
	PMyArray pArray;//���߱��������ҷ���һ��ָ�����
	int c[5];
	pArray = &c;
	for (int i = 0; i < 5; ++i) 
	{
		(*pArray)[i] = i + 1;
		printf("%d\n", (*pArray)[i]);
	}
	system("pause");
	return 0;
}

//��������ָ������ķ���3
//ǰ���ַ��� ͨ�����Ͷ������ �Ƚ��鷳
void maindm01ShuZuJiChu4()
{
	int(*pArray)[5];//ֱ�Ӷ����һ��ָ������ ��ָ�����

	int c[5];
	pArray = &c;
	for (int i = 0; i < 5; ++i)
	{
		(*pArray)[i] = i + 1;
		printf("%d\n", (*pArray)[i]);
	}
	system("pause");
	return;
}