#define _CRT_SECURE_NO_WARNINGS  
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Teacher
{
	char name[64];
	char*alisname;
	char**pname; //{"name1","name2","name3"}����ѧ������
	//char studentname[10][30];
	int age;
	int id;
}Teacher;

//�ṹ������ 3 ������ʦ���������� 

void printage(Teacher*array, int num)
{
	for (int i = 0; i < num; ++i)
	{
		printf("age:%d\n", array[i].age);
	}
}
void SortAge(Teacher*array, int num)
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

void createTeacher(int num, Teacher**outp)
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
		//mallocһ��ָ��
		temp[i].alisname = (char*)malloc(64);
		//����ָ��ĵ������ڴ�ģ��
		char**p = (char**)malloc(3 * sizeof(char*));
		for (int j = 0; j < 3; ++j) 
		{
			p[j] = (char*)malloc(120);
		}
		temp[i].pname = p;
	}
	*outp = temp;
	return;
}

int freeTeacher(Teacher**inp, int num)
{
	if (inp != NULL)
	{
		//�ͷ�һ��ָ��
		for (int i = 0; i < num; ++i)
		{
			if ((*inp)[i].alisname != NULL)
			{
				free((*inp)[i].alisname);
				(*inp)[i].alisname = NULL;
			}
			if ((*inp)[i].pname != NULL) 
			{
				for (int j = 0; j < 3; ++j) 
				{
					if ((*inp)[i].pname[j] != NULL) 
					{
						free((*inp)[i].pname[j]);
						(*inp)[i].pname[j] = NULL;
					}
				}
				free((*inp)[i].pname);
				(*inp)[i].pname = NULL;
			}
		}
		free(*inp);
		*inp = NULL;
		return 0;
	}
	return -1;
}

int main54()
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
		scanf("%s", myp[i].name);//��ָ����ָ����ڴ�ռ俽������
		printf("����:\n");
		scanf("%s", myp[i].alisname);//����ǰ�����ڴ� ���򵱵�
		for (int j = 0; j < 3; ++j) 
		{
			printf("ѧ������:\n");
			scanf("%s", myp[i].pname[j]);
		}
	}
	printage(myp, num);
	freeTeacher(&myp, num);
	system("pause");
	return 0;
}