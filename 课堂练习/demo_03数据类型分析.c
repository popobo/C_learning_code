#include<stdio.h>
#include<malloc.h>

//�������͵���;
//�������͵ı��ʣ��̶���С�ڴ�ı���
//b &b �����������ͣ�����һ����1 �������ͣ�2 ��������ָ�룻3 �������ͺ�����ָ�����͵Ĺ�ϵ��


int main02()
{
	int a;//���߱���������4���ֽڵ��ڴ�
	int b[10];//���߱���������40���ֽ�

	printf("b:%d,b+1:%d,&b:%d,&b+1:%d\n", b, b + 1, &b, &b + 1);
	//b+1 &b+1 �����һ��  //b,&b��������������Ͳ�һ��
	//b����������Ԫ�صĵ�ַ
	//&b���������������ĵ�ַ
	printf("sizeof(b):%d\n",sizeof(b));
	printf("sizeof(a):%d\n", sizeof(a));
	system("pause");
	return 0;
}

typedef struct Teacher
{
	char name[64];
	int age;
}Teacher;
struct Teacher2
{
	char name[64];
	int age;
}Teacher2;


int main03()
{
	int a;//���߱���������4���ֽڵ��ڴ�
	int b[10];//���߱���������40���ֽ�

	struct Teacher t1;//C�����������������Ǽ�typedef
	//Teacher2 t2;
	printf("sizeof(t1)=%d\n", sizeof(t1));
	{
		char* p = NULL;
		void* p1 = NULL;
		p = (char*)malloc(100);
		p1 = &p;
		//void a ��������֪����η����ڴ�
	}
	return 0;
}