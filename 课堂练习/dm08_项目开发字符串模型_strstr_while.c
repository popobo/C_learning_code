 #include<stdio.h>
#include<stdlib.h>
#include<string.h>

//char*p="abcd11122abcd3333222abcd33333222qqq";//求字符串p 种a,b,c,d的出现次数
//请自定义函数接口 完成上述要求
//自定义的业务函数和main函数必须分开
void maindm081()
{
	int ncount = 0;
	//初始化
	char*p = "abcd11122abcd3333222abcd33333222qqq";

	do 
	{
		p = strstr(p, "abcd");
		if (p != NULL)
		{
			ncount++;
			p = p + strlen("abcd");
		}
		else
		{
			break;
		}
	} while (*p!='\0');
	printf("ncount:%d\n", ncount);
	return;
}

void maindm082()
{
	int ncount = 0;
	//初始化
	char*p = "abcd11122abcd3333222abcd33333222qqqabcd";
	while (*p != '\0' && (p = strstr(p, "abcd")))
	{
		ncount++;
		p = p + strlen("abcd");
		/*if (*p == '\0')
		{
		break;
		}*/
	}
	printf("ncount:%d\n", ncount);
}

int getCount(char*mystr, char*mysub, int*ncount)
{
	if (mystr == NULL || mysub == NULL)
	{
		printf("getCountError");
		return -1;
	}
	char*tempmystr = mystr;
	char*tempmysub = mysub;
	int tempncount = 0;
	while (*tempmystr != '\0' && (tempmystr = strstr(tempmystr, tempmysub)))
	{
		tempncount++;
		tempmystr += strlen(mysub);
	}
	*ncount = tempncount;
	return 0;
}

void maindm083()
{
	int ncount = 0;
	char*str = "abcd11122abcd3333222abcd33333222qqq";
	char*sub = "abcd";
	getCount(str, sub, &ncount);
	printf("ncount:%d\n", ncount);
	return;
}