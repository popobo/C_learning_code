#include<stdio.h>

void PrintArr(int arr[], int len)
{
	printf("�����е�sizeof(arr)=%d\n", sizeof(arr));
}


//�����������������˻����⣬�˻�Ϊһ��ָ��
//���ۣ���������ڴ��׵�ַ���������Ч���ȴ��������ú���
//ʵ�ε�a���βε�a���������ͱ��ʲ�һ��
//�β��е����飬���������������ָ�봦������C���Ե���ɫ
//�β�д�ں����Ϻ�д�ں�������һ���ģ�ֻ�����Ǿ��ж�������Զ���
int main01()
{
	int arr[] = { 1, 5, 6, 3, 4 };
	printf("main�е�sizeof(arr)=%d\n",sizeof(arr));
	PrintArr(arr, 5);
	return 0;
}