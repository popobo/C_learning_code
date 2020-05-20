#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//定义了一个数据类型 固定大小内存块的别名 还没有分配内存
typedef struct Teacher
{
	char name[64];
	int age;
	int id;
}Teacher;

//用类型定义变量的方法
struct Student
{
	char name[64];
	int age;
}s1, s2 = { "aaaa",11 };//定义类型的同时定义变量

struct 
{
	char name[64];
	int age;
}s3 = { "aaaa",11 };//匿名类型 定义变量

void copyTeacher(Teacher*to, Teacher from)
{
	*to = from;
}

int main51()
{
	//struct Teacher t1;//告诉编译器分配内存
	Teacher t2;
	//初始化结构体的三种方法 上面还有两种
	Teacher t1 = { "aaaa",11,11 };
	Teacher t3;
	memset(&t3, 0, sizeof(t3));
	copyTeacher(&t3, t1);
	printf("after copyTeacher()\n");
	printf("t3.name:%s\n", t3.name);

	t2 = t1;//=号操作下 编译器的行为
	//编译器给我们提供了简单的=号赋值操作 我们要顺从
	
	printf("t2.name:%s\n", t2.name);

	t1.age = 31;//.操作符 是干啥的 有没有操作内存 
				//是寻址操作 计算age 相对于 t1大变量的 偏移量 ==>计算 cpu中进行
				//没有操作内存

	strcpy_s(t1.name, 64, "bbbbb");
	printf("t1.name:%s\n", t1.name);

	//通过指针的方式操作内存空间
	Teacher*p = NULL;
	p = &t1;
	printf("p->name:%s\n", p->name);//同上 是寻址操作



	system("pause");
	return 0;
}