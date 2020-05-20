#define _CRT_SECURE_NO_WARNINGS  
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Teacher
{
	char name[64];
	char*alisname;
	int age;
	int id;
}Teacher;

//�ṹ������ 3 ������ʦ���������� 

void printage53(Teacher*array, int num)
{
	for (int i = 0; i < num; ++i)
	{
		printf("age:%d\n", array[i].age);
	}
}
void SortAge53(Teacher*array, int num)
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

void createTeacher53(int num, Teacher**outp)
{
	Teacher*temp = NULL;
	temp = (Teacher*)malloc(sizeof(Teacher)*num);
	if (temp == NULL)
	{
		return;
	}
	memset(temp, 0, sizeof(sizeof(Teacher)*num));
	for (int i = 0; i < num; ++i) 
	{
		temp[i].alisname = (char*)malloc(64);
	}
	*outp = temp;
	return;
}

int freeTeacher53(Teacher**inp, int num) 
{
	if (inp != NULL)
	{
		for (int i = 0; i < num; ++i)
		{
			free((*inp)[i].alisname);
			(*inp)[i].alisname = NULL;
		}
		free(*inp);
		*inp = NULL;
		return 0;
	}
	return -1;
}

int main53()
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
	createTeacher53(num, &myp);
	for (int i = 0; i < 3; ++i)
	{
		printf("����:\n");
		scanf("%s", myp[i].name);//��ָ����ָ����ڴ�ռ俽������
		printf("����:\n");
		scanf("%s", myp[i].alisname);//����ǰ�����ڴ� ���򵱵�
	}
	printage53(myp, num);
	freeTeacher53(&myp, num);
	system("pause");
	return 0;
}