#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void printArrayduoweishuzuming(int a[3][5])
{
	int i = 0, j = 0;
	for (i = 0; i < 3; ++i)
	{
		for (j = 0; j < 5; ++j)
		{
			printf("%d ", a[i][j]);
		}
	}
}
//�˻�Ϊһ������ָ��
void printArrayduoweishuzuming1(int(*a)[5])
{
	int i = 0, j = 0;
	for (i = 0; i < 3; ++i)
	{
		for (j = 0; j < 5; ++j)
		{
			printf("%d ", a[i][j]);
		}
	}
}

//��ά�������������� �˻�����....��ʵ����
//Ϊʲô�˻�
int mainduoweishuzuming1()
{
	int a[3][5];
	int i = 0, j = 0, temp = 1;
	for (i = 0; i < 3; ++i) 
	{
		for (j=0;j<5;++j)
		{
			a[i][j] = temp++;
		}
	}
	printArrayduoweishuzuming(a);
	printf("\n-------------\n");
	printArrayduoweishuzuming1(a);
	printf("\n-------------\n");
	for (i = 0; i < 3; ++i)
	{
		for (j = 0; j < 5; ++j)
		{
			printf("%d ", a[i][j]);
		}
	}

	//��ά������ ����?
	printf("a %d a+1 %d\n", a, a + 1); //a+1�Ĳ�����20���ֽ� 5*4
	printf("&a %d &a+1 %d\n", &a, &a + 1);

	//����һ��ָ�������ָ�����
	int(*pArray)[5];

	pArray = a;
	for (i = 0; i < 3; ++i)
	{
		for (j = 0; j < 5; ++j)
		{
			printf("%d ", pArray[i][j]);
		}
	}
	//��ά�������ı��� ����ָ�� ���� һά�ĳ���
	//(a+i)������������i�е��׵�ַ ����ָ��
	//*(a+i)�����i����Ԫ�صĵ�ַ һ��ָ��
	//*(a+i)+j ==> &a[i][j]
	//ֻ������i�еĵ�ַ�͵�i����Ԫ�صĵ�ַ���ص���
	
	//a[i][j] ==>a[0+i][j] ==> *(a+i)[0+j] ==> *(*(a+i)+j)

	system("pause");
	return 0;
}