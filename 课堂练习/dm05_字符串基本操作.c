#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//一级指针的典型用法
//数组int a[10]
//字符串
//1.C语言的字符串 以0结尾的字符串
//2.在C语言种没有字符串类型 通过字符数组 来模拟字符串
//3.字符串的内存分配 堆上 栈上 全局区（很重要）

//字符数组 初始化
void maindm051()
{
	//1.指定长度
	char buf2[100] = { 's', 'a', 'b', 'c' };
	//1-1.char buf3[3]={ 's', 'a', 'b', 'c' }; 如果初始化个数大于内存个数 编译错误
	//1-2.buf2[4]—buf2[99] 值为0即'\0'

	//2.不指定长度
	char buf1[] = { 's', 'a', 'b' ,'c'};//buf1是一个数组 不是一个以0结尾的字符串
	
	printf("buf2:%s\n", buf2);
	printf("buf2[88]:%d\n",buf2[88]);

	return;
}

//用字符串初始化字符数组
//strlen()长度不包括0
//sizeof()内存块的大小
void maindm052()
{
	char buf3[] = "abcd";//buf3 作为字符数组 应该是5个字节 作为字符串 应该是4个字节
	int len = strlen(buf3);
	printf("字符长度：%d\n",len);
	//buf3 作为数组 数组是一种数据类型 本质（固定内存大小的别名）
	int size = sizeof(buf3);
	printf("内存长度：%d\n", size);

	{
		char buf4[128] = "abcd";
		printf("buf4[100]:%d\n",buf4[100]);
	}
	
}

//通过数组下标和指针
void maindm053()
{
	char buf5[128] = "abcdefg";
	char*p = NULL;
	for (int i = 0; i < strlen(buf5); ++i)
	{
		printf("%c",buf5[i]);
	}
	p = buf5;//buf5代表数组首元素地址
	for (int i = 0; i < strlen(buf5);++i)
	{
		printf("%c", *(p + i));
	}
	for (int i = 0; i < strlen(buf5); ++i)
	{
		printf("%c", *(buf5 + i));
	}
	{
		//buf5=0x123;
		//buf5 = buf5 + 1;
	}
	//[] * 的推导过程
	//buf5[i]==>buf5[0+i]==>*(buf5+i)
	return;
}

//[]的本质和*是一样的
//buf5是一个指针 只读的常量 buf5是一个常量指针
//为什么这么做
//析构内存时 保证buf5所指向的内存空间安全释放