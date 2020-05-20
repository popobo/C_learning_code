#pragma once
#define _CRT_SECURE_NO_WARNINGS  
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//Ŀ����Ϊ����C++���ܹ�����Cд�ĺ���

typedef struct ConfigInfo 
{
	char key[64];
	char val[128];
}ConfigInfo;
#ifdef __cplusplus
extern "C" {
#endif
	//��ȡ�ļ���Ч����
	int getLinesnum(FILE*file);
	//���������ļ�
	void LoadFile(const char*filepath, char***filedate, int*linesnum);
	//���������ļ� 
	void parseFile(const char**filedata, int linesnum, ConfigInfo**info);
	//����ƶ�������Ϣ
	char*getInfo(const char*key, ConfigInfo*info, int linesnum);
	//�жϵ�ǰ���Ƿ���Ч
	int isValid(const char*buf);
#ifdef __cplusplus
}
#endif