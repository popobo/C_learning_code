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
	//��ν�˻���ָ�ڵ��õĺ�����sizeof(table)==4 ������������ sizeof(table)==16 
	//��Ϊ����������table��ָ��һ�����ĸ�ָ�������ָ��(��ָ������) ���ڵ��ú����� ֻ��һ����ͨ��άָ��
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
	//�������ĺ�
	searchKeyTable(c_keyword, DIM(c_keyword), "do", &pos);
	printf("%d\n", sizeof(c_keyword[0]));

	system("pause");
	return 0;
}

//����ϵͳ�����ڴ�
//argv[] �����в���
int mainzhizhenshuzuyingyong1(int argc, char*argv[], char**env)
{
	int i = 0;
	//����������Ϣ
	printf("\nbegin\n");
	for (i = 0; i < argc; ++i)
	{
		printf("%s\n",argv[i]);
	}
	printf("\end\n");
	printf("\begin1\n");
	for (i = 0; env[i] != NULL; ++i)//env����NULL��β��ָ������
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
		//"\0" �� '\0'�ǲ�һ����
		//'\0' 0 NULL ������Ϊָ�����ҽ��ܱ�ʶ "\0"���� 
		//0
		NULL
	};
	printf("sizeof(\"\\0\"):%d\n", sizeof("\0"));
	char c = '\0';
	printf("sizeof(c):%d\n", sizeof(c));
	printf("sizeof('\\0'):%d\n", sizeof('\0'));//sizeof('0')�൱��sizeofһ��������(int)
	for (int i = 0; c_keyword[i] != NULL; ++i)
	{
		printf("%s\n",c_keyword[i]);
	}
	system("pause");
	return 0;
}
