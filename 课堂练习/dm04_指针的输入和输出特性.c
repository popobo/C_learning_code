
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int getMem41(char**myp1/*out*/, int*mylen1/*out*/, char**myp2/*out*/, int*mylen2/*out*/)
{
	int ret = 0;

	char*temp1 = (char*)malloc(100);
	strcpy_s(temp1, 30, "asdadasd");
	//间接赋值
	*mylen1 = strlen(temp1);//一级指针
	*myp1 = temp1;//二级指针

	char*temp2 = (char*)malloc(200);
	strcpy_s(temp2, 30, "fafaffafs");
	*mylen2 = strlen(temp2);
	*myp2 = temp2;

	return ret;
}

char*getMem42(int len)
{
	char*p = (char*)malloc(len);
	strcpy_s(p, len, "dafsafafafsad");
	return p;
}

void maindm04()
{
	char*p1 = NULL;
	int len1 = 0;
	char*p2 = NULL;
	int len = 0;
	getMem41(&p1, &len, &p2, &len);

	printf("p1:%s\n", p1);
	printf("p2:%s\n", p2);

	p1 = getMem42(50);
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