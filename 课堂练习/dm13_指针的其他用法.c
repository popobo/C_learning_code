#define _CRT_SECURE_NO_WARNINGS  
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int getContentLen(const char*filename, char**buf, int *len)
{
	char*temp = NULL;
	temp = (char*)malloc(100 * sizeof(char));
	if (temp == NULL) 
	{
		return -1;
	}
	strcpy(temp, "aaaaaaa");
	*len = 10;
	*buf = temp;
	return 0;
}

int getContentLen2(const char*filename, char**buf, int *len)
{
	if (buf == NULL)
	{
		*len = 10;
		return 0;
	}
	else
	{
		strncpy(*buf, "aaaaaaaaaaaaaa", *len);
		return 0;
	}
}

int main213()
{
	const char*filename = "data.txt";
	char*p = NULL;
	int len = 0;
	//getContentLen(filename, &p, &len);
	getContentLen2(filename, NULL, &len);
	p = (char*)malloc(len);
	if (p == NULL)
	{
		return -1;
	}
	getContentLen2(filename, &p, &len);
	printf("%s\n", p);
	if (p != NULL)
	{
		free(p);
		p = NULL;
	}

	system("pause");
	return EXIT_SUCCESS;
}