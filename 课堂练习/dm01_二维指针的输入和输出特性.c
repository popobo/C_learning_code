#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int getMemdm131(char**myp1/*out*/, int*mylen1/*out*/, char**myp2/*out*/, int*mylen2/*out*/)
{
	int ret = 0;

	char*temp1 = (char*)malloc(100);
	if (temp1 == NULL)
	{
		return -1;
	}
	strcpy_s(temp1, 30, "asdadasd");
	//间接赋值
	*mylen1 = strlen(temp1);//一级指针
	*myp1 = temp1;//二级指针

	char*temp2 = (char*)malloc(200);
	if (temp2 == NULL)
	{
		return -1;
	}
	strcpy_s(temp2, 30, "fafaffafs");
	*mylen2 = strlen(temp2);
	*myp2 = temp2;

	return 0;
}

int FreeMem(char**p)
{
	char**temp = p;
	if (temp == NULL)
	{
		return -1;
	}
	free(*temp);
	*temp = NULL;
	return 0;
}

char*getMemdm132(int len)
{
	char*p = (char*)malloc(len);
	strcpy_s(p, len, "dafsafafafsad");
	return p;
}

void maindm132()
{
	char*p1 = NULL;
	int len1 = 0;
	char*p2 = NULL;
	int len = 0;
	getMemdm131(&p1, &len, &p2, &len);

	printf("p1:%s\n", p1);
	printf("p2:%s\n", p2);

	p1 = getMemdm132(50);
	printf("p1:%s\n", p1);
	FreeMem(&p1);
	FreeMem(&p2);
}
void maindm131()
{
	char*p1 = NULL;
	int len1 = 0;
	char*p2 = NULL;
	int len = 0;
	getMemdm131(&p1, &len, &p2, &len);

	printf("p1:%s\n", p1);
	printf("p2:%s\n", p2);

	p1 = getMemdm132(50);
	printf("p1:%s\n", p1);
	if (p1 != NULL)
	{
		free(p1);
		p1 = NULL;
	}
	if (p2 != NULL)
	{
		free(p2);
		p2 = NULL;
	}

	return;
}
