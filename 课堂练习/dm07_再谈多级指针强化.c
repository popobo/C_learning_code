#define _CRT_SECURE_NO_WARNINGS  
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main37()
{
	int a = 10;
	int *p = NULL;

	a = 11;
	p = &a;
	*p = 30;

	char*p1 = NULL;
	char**p2 = NULL;
	char c = 'a';
	p2 = &p1;
	*p2 = &c;
	**p2 = 't';
	printf("%c", *p1);


	system("pause");
	return EXIT_SUCCESS;
}