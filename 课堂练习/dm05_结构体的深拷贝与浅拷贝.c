#define _CRT_SECURE_NO_WARNINGS  
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Teacher
{
	char name[64];
	int age;
	char*pname;
}Teacher;

//编译器的=操作 只会把指针变量的值 从from 拷贝到 to
//不会把指针变量所指的内存空间给copy过去 //浅拷贝

//如果想执行深拷贝
void copyTeacher55(Teacher*to, Teacher*from) 
{
	*to = *from;
	to->pname = (char*)malloc(100);
	strcpy(to->pname, from->pname);
}
int main55()
{
	Teacher t1;
	Teacher t2;
	strcpy(t1.name, "name1");
	t1.pname = (char*)malloc(100);
	strcpy(t1.pname, "name2");
	copyTeacher55(&t2, &t1);
	if (t1.pname != NULL) 
	{
		free(t1.pname);
		t1.pname = NULL;
	}
	if (t2.pname != NULL)
	{
		free(t2.pname);
		t2.pname = NULL;
	}


	system("pause");
	return 0;
}