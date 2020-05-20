#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int trimSpacedm11(char*str, char*buf)
{
	if (str == NULL || buf == NULL)
	{
		return -1;
	}
	char*tempstr = str;
	int mycount = 0;
	int i = 0, j = 0;
	j = strlen(str) - 1;
	while (isspace(tempstr[i]) && tempstr[i] != '\0')
	{
		i++;
	}
	while (isspace(tempstr[j]) && tempstr[j] != '\0')
	{
		j--;
	}
	mycount = j - i + 1;
	strcpy_s(buf, 50, str + i, mycount);
	buf[mycount] = '\0';
	return 0;
}

int getValueByKey(char*KeyValueBuf, char*KeyBuf, char*ValueBuf)
{
	//����Key�ǲ�����ĸ����
	int ret = 0;
	char*temp = NULL;
	temp = KeyValueBuf;//��ʼ������ָ�����
	temp = strstr(temp,KeyBuf);
	if (temp == NULL)
	{
		return -1;
	}
	temp += strlen(KeyBuf);

	//����û�� =
	temp = strstr(temp, "=");
	if (temp == NULL)
	{
		return -1;
	}
	temp += strlen("=");
	//�ڵȺź���ȥ���ո�
	ret = trimSpacedm11(temp, ValueBuf);
	if (ret != 0)
	{
		printf("getValueByKey Error");
		return -1;
	}
	return 0;
}
void maindm11()
{
	int ret = 0;
	char buf[1024];
	int buflen = 0;
	char*KeyAndValue = "key2=   value2   ";
	char*key = "key2";
	ret = getValueByKey(KeyAndValue, key, buf);
	if (ret != 0)
	{
		printf("getValueByKey Error!");
	}
	printf("buf:%s\n", buf);
	return;
}