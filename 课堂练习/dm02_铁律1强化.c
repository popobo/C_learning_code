#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void maindm02()
{
	char*p1 = NULL;

	strcpy_s(p1,50,"adsadsad");

	return;
}

void maindm021()
{
	char*p1 = NULL;
	p1 = 0x0077;
	strcpy_s(p1,50,"asdasdsa");
	return;
}

void maindm022()
{
	int i;
	int j = 0;
	char buf[128];
	
	char*p1 = NULL;
	char*p2 = NULL;

	for (i = 0; i < 10; ++i)
	{
		p1 = &buf[i];
	}
	p2 = (char*)malloc(100);
	strcpy_s(p2,100,"dasdsdsad");

	for (i = 0; i < 10; ++i)
	{
		p1 = p2 + i;
		printf("%c",*p1);
	}
}