#include "ConfigFile.h"

//获取文件有效行数
int getLinesnum(FILE*file)
{
	char buf[1024] = { '\0' };
	int templinesnum = 0;
	while (fgets(buf, 1024, file) != NULL)
	{
		if (!isValid(buf)) 
		{
			continue;
		}
		++templinesnum;
		memset(buf, 0, 1024);
	}
	//把文件指针充值到文件开头
	fseek(file, 0, SEEK_SET);
	return templinesnum;
}
//加载配置文件
void LoadFile(const char*filepath, char***filedata, int*linesnum)
{
	FILE*file = fopen(filepath, "r");
	if (file == NULL)
	{
		return;
	}
	int templinesnum = getLinesnum(file);
	char**temp = (char**)malloc(sizeof(char*)*templinesnum);
	char buf[1024] = { '\0' };
	int index = 0;
	while (fgets(buf, 1024, file) != NULL)
	{
		if (!isValid(buf))
		{
			continue;
		}
		temp[index] = (char*)malloc(strlen(buf) + 1);
		strcpy(temp[index++], buf);
		memset(buf, 0, 1024);
	}
	*filedata = temp;
	*linesnum = templinesnum;
	fclose(file);
}
//解析配置文件 
void parseFile(const char**filedata, int linesnum, ConfigInfo**info)
{
	ConfigInfo*myinfo = malloc(sizeof(ConfigInfo));
	memset(myinfo, 0, sizeof(ConfigInfo));
	for (int i = 0; i < linesnum; ++i) 
	{
		char*pos = strchr(filedata[i], ':');
		strncpy(myinfo[i].key, filedata[i], pos - filedata[i]);
		strncpy(myinfo[i].val, pos + 1, strlen(pos + 1) - 1);
		printf("%s : %s\n", myinfo[i].key, myinfo[i].val);
	}
	*info = myinfo;
	return;
}
//获得制定配置信息
char*getInfo(const char*key, ConfigInfo*info, int linesnum)
{
	for (int i = 0; i < linesnum; ++i) 
	{
		if (strcmp(info[i].key, key) == 0)
		{
			return info[i].val;
		}
	}
	return NULL;
}
//判断当前行是否有效
int isValid(const char*buf)
{
	if (buf[0] == '#' || buf[0] == '\n' || strchr(buf, ':') == NULL)
	{
		return 0;
	}
	return 1;
}