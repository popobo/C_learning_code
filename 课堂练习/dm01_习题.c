#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Ұָ�������ԭ��
//ָ�����������ָ����ڴ�ռ������������ͬ�ĸ���
//�ͷ���ָ����ָ���ڴ�ռ� ����ָ���������û�����ó�NULL

void maindm01()
{
	char*p1 = NULL;
	p1 = (char*)malloc(100);
	if (p1 == NULL)
	{
		return;
	}
	strcpy_s(p1, 100 ,"asdsaasddasd");
	printf("p1:%s\n", p1);
	//if (p1 != NULL)
	//{
	//	free(p1);
	//}//�����������Ұָ��
	
	if (p1 != NULL)
	{
		free(p1);
		p1 = NULL;
	}
	if (p1 != NULL)
	{
		free(p1);
		p1 = NULL;
	}
	return;
}





