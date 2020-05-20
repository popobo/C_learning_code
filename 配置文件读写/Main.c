#define _CRT_SECURE_NO_WARNINGS  
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "ConfigFile.h"

#define FILEPATH "config.ini"
void Test()
{
	char**filedata = NULL;
	int linesnum = 0;
	ConfigInfo*myinfo = NULL;
	LoadFile(FILEPATH, &filedata, &linesnum);
	//printf("%d\n", linesnum);
	//for (int i = 0; i < linesnum; i++) 
	//{
	//	printf("%s\n", filedata[i]);
	//}
	parseFile(filedata, linesnum, &myinfo);
	printf("%s\n", getInfo("IP", myinfo, linesnum));
}

int main()
{
	Test();

	system("pause");
	return 0;
}