#define _CRT_SECURE_NO_WARNINGS  
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//һ���ṹ�嶨������ ��ṹ���еĳ�Ա �ڴ沼�־� ��������
//����ͨ�� age��ַ ȥ���Ľṹ����ڴ��ַ
typedef struct AdvTeacher
{
	char name[64];
	int age;
	char*pname;
}AdvTeacher;

int main561()
{
	AdvTeacher t1;
	AdvTeacher*p = NULL;
	p - 1;//����ͨ�� ����ͨ�� ��仰 ��CPU�м���
	p - 2;
	
	int offsize = (int)&(p->age);
	printf("%d\n", offsize);

	system("pause");
	return 0;
}

void main562()
{
	AdvTeacher t1;
	AdvTeacher*p = NULL;
	p = &t1;


	int offsize = (int)&(((AdvTeacher*)0)->age);//�����������AdvTeacher�ķ�ʽ���ʹ��㿪ʼ���ڴ� ���սṹ���ж���˳��
	int offsize1 = (int)&(p->age) - (int)p;
	printf("%d\n", offsize);
	printf("%d\n", offsize1);
	printf("p:%d", (int)p);

	system("pause");
	return 0;
}
