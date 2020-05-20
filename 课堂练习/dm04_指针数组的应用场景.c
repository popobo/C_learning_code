#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int searchKeyTable(const char*table[], const int size, const char*key, int *pos)
{
	int rv = 0;
	int i = 0;
	int inum = 0;
	if (table == NULL || key == NULL || pos == NULL)
	{
		rv = -1;
		printf("func searchKeyTable:%d\n", rv);
		return rv;
	}
	//所谓退化是指在调用的函数中sizeof(table)==4 而在主函数中 sizeof(table)==16 
	//因为在主函数中table是指向一个有四个指针变量的指针(即指针数组) 而在调用函数中 只是一个普通二维指针
	inum = (sizeof(table)) / sizeof(*table);
	for (i = 0; i < size; ++i)
	{
		if (strcmp(key, table[i]) == 0)
		{
			*pos = i;
			return rv;
		}
	}
	if (i == size)
	{
		*pos = -1;
	}
	return rv;

}

#define DIM(a) (sizeof(a))/sizeof(*a)

int mainzhizhenshuzuyingyong()
{
	int inum = 0;
	int pos = 0;
	int a[10];
	int i = 0;
	char*c = "aaaaa";
	printf("sizeof(c):%d\n",sizeof(c));
	char d[] = "aaaaa";
	printf("sizeof(d):%d\n", sizeof(d));
	char*c_keyword[] = {
		"while",
		"case",
		"static",
		"do"
	};
	//带参数的宏
	searchKeyTable(c_keyword, DIM(c_keyword), "do", &pos);
	printf("%d\n", sizeof(c_keyword[0]));

	system("pause");
	return 0;
}

//操作系统分配内存
//argv[] 命令行参数
int mainzhizhenshuzuyingyong1(int argc, char*argv[], char**env)
{
	int i = 0;
	//环境变量信息
	printf("\nbegin\n");
	for (i = 0; i < argc; ++i)
	{
		printf("%s\n",argv[i]);
	}
	printf("\end\n");
	printf("\begin1\n");
	for (i = 0; env[i] != NULL; ++i)//env是以NULL结尾的指针数组
	{
		printf("%s\n", env[i]);
	}
	printf("\end1\n");
	getchar();
}

int mainzhizhenshuzuyingyong2()
{
	char*c_keyword[] = {
		"while",
		"case",
		"static",
		"do",
		//"\0" 和 '\0'是不一样的
		//'\0' 0 NULL 可以作为指针自我介绍标识 "\0"不行 
		//0
		NULL
	};
	printf("sizeof(\"\\0\"):%d\n", sizeof("\0"));
	char c = '\0';
	printf("sizeof(c):%d\n", sizeof(c));
	printf("sizeof('\\0'):%d\n", sizeof('\0'));//sizeof('0')相当于sizeof一个立即数(int)
	for (int i = 0; c_keyword[i] != NULL; ++i)
	{
		printf("%s\n",c_keyword[i]);
	}
	system("pause");
	return 0;
}
