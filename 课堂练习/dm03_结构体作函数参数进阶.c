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

//结构体数组 3 输入老师的年龄排序 

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
	createTeacher53(num, &myp);
	for (int i = 0; i < 3; ++i)
	{
		printf("名字:\n");
		scanf("%s", myp[i].name);//向指针所指向的内存空间拷贝数据
		printf("别名:\n");
		scanf("%s", myp[i].alisname);//不提前分配内存 程序当掉
	}
	printage53(myp, num);
	freeTeacher53(&myp, num);
	system("pause");
	return 0;
}