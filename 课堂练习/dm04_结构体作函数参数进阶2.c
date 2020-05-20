#define _CRT_SECURE_NO_WARNINGS  
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Teacher
{
	char name[64];
	char*alisname;
	char**pname; //{"name1","name2","name3"}三个学生姓名
	//char studentname[10][30];
	int age;
	int id;
}Teacher;

//结构体数组 3 输入老师的年龄排序 

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
		//malloc一级指针
		temp[i].alisname = (char*)malloc(64);
		//二级指针的第三种内存模型
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
		//释放一级指针
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
	Teacher Array[3];//在stack分配内存
	int num = 3;
	//for (int i = 0; i < 3; ++i)
	//{
	//	printf("年龄:\n");
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
		printf("名字:\n");
		scanf("%s", myp[i].name);//向指针所指向的内存空间拷贝数据
		printf("别名:\n");
		scanf("%s", myp[i].alisname);//不提前分配内存 程序当掉
		for (int j = 0; j < 3; ++j) 
		{
			printf("学生姓名:\n");
			scanf("%s", myp[i].pname[j]);
		}
	}
	printage(myp, num);
	freeTeacher(&myp, num);
	system("pause");
	return 0;
}