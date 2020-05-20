#pragma once
#define _CRT_SECURE_NO_WARNINGS  
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//目的是为了在C++中能够调用C写的函数

typedef struct ConfigInfo 
{
	char key[64];
	char val[128];
}ConfigInfo;
#ifdef __cplusplus
extern "C" {
#endif
	//获取文件有效行数
	int getLinesnum(FILE*file);
	//加载配置文件
	void LoadFile(const char*filepath, char***filedate, int*linesnum);
	//解析配置文件 
	void parseFile(const char**filedata, int linesnum, ConfigInfo**info);
	//获得制定配置信息
	char*getInfo(const char*key, ConfigInfo*info, int linesnum);
	//判断当前行是否有效
	int isValid(const char*buf);
#ifdef __cplusplus
}
#endif