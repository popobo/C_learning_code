#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int  getFileLen(int*p)
{
	*p = 40;//p��ֵ��a�ĵ�ַ *a�ĵ�ַ����޸�a��ֵ 
	return 0;
}

int  getFileLen2()
{
	int a = 40;//p��ֵ��a�ĵ�ַ *a�ĵ�ַ����޸�a��ֵ 
	return a;
}

int  getFileLen3(int b)
{
	b = 40;//p��ֵ��a�ĵ�ַ *a�ĵ�ַ����޸�a��ֵ 
	return b;
}

void maindm031()
{
	int a = 0;//����һ����������������(ʵ��a,��һ���������β�p)
	int*p = NULL;
	a = 20;
	p = &a;//����������������
	*p = 30;//p��ֵ��a�ĵ�ַ//��������*p
	printf("a:%d\n", a);
	getFileLen(&a);//��ʵ��ȡ��ַ���͸��β�
	printf("a:%d\n", a);
	getFileLen3(a);
	printf("a:%d\n", a);


	return;
}
void getMemdm03(char**p2)
{
	*p2 = 400;
}

void maindm032()
{
	char*p1 = NULL;
	char**p2 = NULL;
	
	p1 = 0x11;
	p2 = 0x22;

	//ֱ���޸�p1��ֵ

	p1 = 0x111;

	//����޸�p1��ֵ

	p2 = &p1;

	*p2 = 100;//��Ӹ�ֵ p2��p1�ĵ�ַ

	getMemdm03(&p1);

	printf("p1:%d\n", p1);
	
}

int getMem3(char**myp1, int*mylen1, char**myp2, int*mylen2)
{
	int ret = 0;
	
	char*temp1 = (char*)malloc(100);
	strcpy_s(temp1, 30, "asdadasd");
	//��Ӹ�ֵ
	*mylen1 = strlen(temp1);//һ��ָ��
	*myp1 = temp1;//����ָ��

	char*temp2 = (char*)malloc(200);
	strcpy_s(temp2, 30, "fafaffafs");
	*mylen2 = strlen(temp2);
	*myp2 = temp2;

	return ret;
}

void maindm033()
{
	char*p1 = NULL;
	int len1 = 0;
	char*p2 = NULL;
	int len = 0;
	getMem3(&p1, &len, &p2, &len);

	printf("p1:%s\n", p1);
	printf("p2:%s\n", p2);

	if (p1 != NULL)
	{
		free(p1);
		p1 = NULL;
	}
	if (p2 != NULL)
	{
		free(p2);
		p2 = NULL;	
	}	
}

void maindm034()
{
	//1 2 3 ����������д��ͬһ������

	//12д��һ�� 3����д����һ������==����������

	//1����д��23д��һ�� ==����ש==��C++����
	
	char to[128];
	char from[128];
	printf("%d\n",to);
	printf("%d\n", from);
	char*p1 = from;
	char*p2 = to;
	strcpy_s(from, 50, "dasdasdsada");

	while (*p1!='\0')
	{
		*p2 = *p1;
		p1++;
		p2++;
	}
	*p2 = '\0';
	printf("%s\n",to);

	return;
}
