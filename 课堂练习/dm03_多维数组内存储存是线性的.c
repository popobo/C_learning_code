#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void printArrayduoweishuzuxianxing(int*Array,int size)
{
	for (int i = 0; i < size; ++i)
	{
		printf("%d", *(Array + i));
	}
}

int mainduoweishuzuxianxing()
{
	int a[3][5];
	int temp = 1;
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 5; ++j) 
		{
			a[i][j] = temp++;
		}
	}
	printArrayduoweishuzuxianxing((int*)a, 15);
	//�Ѷ�ά���� ���� һά�����ӡ ֤�����Դ洢
	system("pause");
	return 0;
}