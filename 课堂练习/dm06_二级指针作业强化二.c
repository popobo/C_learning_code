#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char**splitStringErJiZhiZhenZuoYe2(const char*buf1, char c, int*count)
{
	char*p1 = NULL, *p2 = NULL;
	char**ptemp = NULL;
	int tempcount = 0;
	p1 = buf1;
	p2 = buf1;
	int len = 0;
	do 
	{
		p2 = strchr(p1, c);
		if (p2 != NULL)
		{
			if (p2 - p1 > 0) 
			{
				tempcount++;
				p1 = p2 + 1;
			}
		}
		else
		{
			break;
		}
	} while (*p1 != '\0');
	*count = tempcount;
	//根据多少行精确分配内存
	ptemp = (char**)malloc(sizeof(char*)*tempcount);
	if (ptemp == NULL)
	{
		return NULL;
	}
	tempcount = 0;
	p1 = buf1;
	p2 = buf1;
	do
	{
		p2 = strchr(p1, c);
		if (p2 != NULL)
		{
			len = p2 - p1;
			if (len > 0)
			{
				ptemp[tempcount] = (char*)malloc(sizeof(char)*(len));
				if (ptemp == NULL)
				{
					return NULL;
				}
				strncpy_s(ptemp[tempcount], len * 2 , p1, len); 
				tempcount++;
				p1 = p2 + 1;
			}
		}
		else
		{
			break;
		}
	} while (*p1 != '\0');
	*count = tempcount;
	return ptemp;
}

int splitStringErJiZhiZhenZuoYe201(const char*buf1, char c, int*count, char***outp) 
{
	char*p1 = NULL, *p2 = NULL;
	char**ptemp = NULL;
	int tempcount = 0;
	int ret = 0;
	p1 = buf1;
	p2 = buf1;
	int len = 0;
	do
	{
		p2 = strchr(p1, c);
		if (p2 != NULL)
		{
			if (p2 - p1 > 0)
			{
				tempcount++;
				p1 = p2 + 1;
			}
		}
		else
		{
			break;
		}
	} while (*p1 != '\0');
	*count = tempcount;
	//根据多少行精确分配内存
	ptemp = (char**)malloc(sizeof(char*)*tempcount);
	memset(ptemp, 0, sizeof(char*)*tempcount);//申请的内存要初始化
	if (ptemp == NULL)
	{
		ret = -1;
		printf("func splitStringErJiZhiZhenZuoYe201 err:%d sizeof(char*)*tempcount", ret);
		goto END;
		//return -1;
	}
	tempcount = 0;
	p1 = buf1;
	p2 = buf1;
	do
	{
		p2 = strchr(p1, c);
		if (p2 != NULL)
		{
			len = p2 - p1;
			if (len > 0)
			{
				ptemp[tempcount] = (char*)malloc(sizeof(char)*(len + 1));
				memset(ptemp[tempcount], 0, sizeof(char)*(len + 1));
				if (ptemp[tempcount] == NULL)
				{
					ret = -1;
					printf("func splitStringErJiZhiZhenZuoYe201 err:%d sizeof(char)*(len + 1)", ret);
					goto END;
					//return -1;
				}
				strncpy_s(ptemp[tempcount], len + 1, p1, len);
				tempcount++;
				p1 = p2 + 1;
			}
		}
		else
		{
			break;
		}
	} while (*p1 != '\0');
END://多级指针 避免野指针
	if (ret != 0)//失败
	{
		for (int i = 0; i < tempcount; ++i) 
		{
			if (ptemp == NULL)
			{
				return ret;
			}
			if (ptemp[i] != NULL)
			{
				free(ptemp[i]);
				//ptemp[i] = NULL;
			}
		}
		if (ptemp != NULL)
		{
			free(ptemp);
			ptemp = NULL;
		}
	}
	else
	{
		*count = tempcount;
		*outp = ptemp;
	}
	return ret;
}

int mainErJiZhiZhenZuoYe201()
{
	int ret = 0;
	char*str = "aaaaaa,bbbbbb,ccccc,dddddd,lllllll";
	char ctemp = ',';
	int nCount = 0;
	char**ptemp = NULL;
	//ptemp = splitStringErJiZhiZhenZuoYe2(str, ctemp, &nCount);
	ret = splitStringErJiZhiZhenZuoYe201(str, ctemp, &nCount, &ptemp);
	if (ret == -1)
	{
		return -1;
	}
	for (int i = 0;i < nCount;++i)
	{
		printf("%s\n", ptemp[i]);
	}
	for (int i = 0; i < nCount; ++i) 
	{
		free(ptemp[i]);
		ptemp[i] = NULL;
	}
	free(ptemp);
	ptemp = NULL;

	system("pause");
	return 0;
}