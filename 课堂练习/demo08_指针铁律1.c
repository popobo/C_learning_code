#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void main81()
{
	int a = 10;
	char*p1 = 100;
	char***p2 = 100;
	printf("sizeof(p1)=%d,sizeof(p2)=%d\n",sizeof(p1),sizeof(p2));
	
	int*p3 = NULL;
	p3 = &a;
	*p3 = 5;//����޸�a��ֵ
	//*����һ��Կ�ף�ͨ��һ����ַ(&a)ȥ�޸�a��ʾ���ڴ�ռ�
	{
		int c = 0;
		c = *p3;//���ڴ��ŵ�ֵ
	}

	{
		char*p4 = NULL;
		p4 = (char*)malloc(4);
	}

	return;
}

char*getStr()
{
	char*temp = NULL;
	temp = "dafadsa";
	return temp;
}

/*
int getABC1(char*p1);
int getABC2(char**p2);
int getABC3(char***p3);
int getABC4(char(*p4)[30]);
int getABC5(char p5[10][30]);

//ָ������������ �β��ж༶ָ���ʱ��
//վ�ڱ������ĽǶ� ֻ��Ҫ�����ĸ��ֽڵ��ڴ棨32λƽ̨��
//������ʹ���ڴ��ʱ�� ���ǲŹ�����ָ����ڴ� ��һά�Ļ��Ƕ�ά��
*/

void main082()
{
	char*p = getStr();
	printf("p:%s\n",p);
	//*(p + 2) = 'r';//�������ֵĴ���Ҫ�޸�ʱ��֤��ָ����ڴ��ܱ��޸ģ��������������޷����޸�
	printf("p:%s\n", p);
	return;
}