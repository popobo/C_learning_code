#define _CRT_SECURE_NO_WARNINGS  
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Teacher
{
	char name[64];
	int age;
	int id;
}Teacher;

//�ṹ������ 3 ������ʦ���������� 

void printage42(Teacher*array, int num)
{
	for (int i = 0; i < num; ++i) 
	{
		printf("age:%d\n", array[i].age);
	}
}
void SortAge42(Teacher*array,int num)
{
	int temp = 0;
	for (int i = 0; i < num; ++i) 
	{
		for (int j = i + 1; j < num; ++j) 
		{
			if (array[i].age > array[j].age)
			{
				temp = array[i].age;
				array[i].age = array[j].age;
				array[j].age = temp;
			}
		}
	}
}

void createTeacher42(int num, Teacher**outp)
{
	Teacher*temp = NULL;
	temp = (Teacher*)malloc(sizeof(Teacher)*num);
	if (temp == NULL)
	{
		return;
	}
	*outp = temp;
	return;
}

int freeTeacher42(Teacher**inp)
{
	if (inp != NULL)
	{
		free(*inp);
		*inp = NULL;
		return 0;
	}
	return -1;
}

int main42()
{
	Teacher Array[3];//��stack�����ڴ�
	int num = 3;
	//for (int i = 0; i < 3; ++i)
	//{
	//	printf("����:\n");
	//	scanf("%d", &(Array[i].age));
	//}
	//for (int i = 0; i < 3; ++i)
	//{
	//	printf("%d\n", Array[i].age);
	//}
	//SortAge(Array, num);
	//printage(Array, num);
	Teacher*myp = NULL;
	createTeacher(num, &myp);
	for (int i = 0; i < 3; ++i)
	{
		printf("����:\n");
		scanf("%d", &(myp[i].age));
	}
	printage(myp, num);
	freeTeacher(&myp);
	system("pause");
	return 0;
}