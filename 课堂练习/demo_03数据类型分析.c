#include<stdio.h>
#include<malloc.h>

//数据类型的用途
//数据类型的本质：固定大小内存的别名
//b &b 数组数据类型（定义一个：1 数组类型；2 数组类型指针；3 数组类型和数组指针类型的关系）


int main02()
{
	int a;//告诉编译器分配4个字节的内存
	int b[10];//告诉编译器分配40个字节

	printf("b:%d,b+1:%d,&b:%d,&b+1:%d\n", b, b + 1, &b, &b + 1);
	//b+1 &b+1 结果不一样  //b,&b所代表的数据类型不一样
	//b代表数据首元素的地址
	//&b代表的是整个数组的地址
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
	int a;//告诉编译器分配4个字节的内存
	int b[10];//告诉编译器分配40个字节

	struct Teacher t1;//C编译器必须这样除非加typedef
	//Teacher2 t2;
	printf("sizeof(t1)=%d\n", sizeof(t1));
	{
		char* p = NULL;
		void* p1 = NULL;
		p = (char*)malloc(100);
		p1 = &p;
		//void a 编译器不知道如何分配内存
	}
	return 0;
}