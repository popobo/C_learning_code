#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//������һ���������� �̶���С�ڴ��ı��� ��û�з����ڴ�
typedef struct Teacher
{
	char name[64];
	int age;
	int id;
}Teacher;

//�����Ͷ�������ķ���
struct Student
{
	char name[64];
	int age;
}s1, s2 = { "aaaa",11 };//�������͵�ͬʱ�������

struct 
{
	char name[64];
	int age;
}s3 = { "aaaa",11 };//�������� �������

void copyTeacher(Teacher*to, Teacher from)
{
	*to = from;
}

int main51()
{
	//struct Teacher t1;//���߱����������ڴ�
	Teacher t2;
	//��ʼ���ṹ������ַ��� ���滹������
	Teacher t1 = { "aaaa",11,11 };
	Teacher t3;
	memset(&t3, 0, sizeof(t3));
	copyTeacher(&t3, t1);
	printf("after copyTeacher()\n");
	printf("t3.name:%s\n", t3.name);

	t2 = t1;//=�Ų����� ����������Ϊ
	//�������������ṩ�˼򵥵�=�Ÿ�ֵ���� ����Ҫ˳��
	
	printf("t2.name:%s\n", t2.name);

	t1.age = 31;//.������ �Ǹ�ɶ�� ��û�в����ڴ� 
				//��Ѱַ���� ����age ����� t1������� ƫ���� ==>���� cpu�н���
				//û�в����ڴ�

	strcpy_s(t1.name, 64, "bbbbb");
	printf("t1.name:%s\n", t1.name);

	//ͨ��ָ��ķ�ʽ�����ڴ�ռ�
	Teacher*p = NULL;
	p = &t1;
	printf("p->name:%s\n", p->name);//ͬ�� ��Ѱַ����



	system("pause");
	return 0;
}