#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char g_buf[1024];

int inverse(char*buf)
{
	if (buf == NULL)
	{
		return -1;
	}
	int length;
	char*p1;
	char*p2;
	char c;

	length = strlen(buf);
	p1 = buf;
	p2 = buf + length - 1;
	while (p1 < p2)
	{
		c = *p1;
		*p1 = *p2;
		*p2 = c;
		++p1;
		--p2;
	}
	return 0;
}

void maindm101()
{
	char buf[] = "abcdefg";
	//int length = strlen(buf);
	//char*p1 = buf;
	//char*p2 = buf + length - 1;
	//char c;
	//while (p1 < p2)
	//{
	//	c = *p1;
	//	*p1 = *p2;
	//	*p2 = c;
	//	++p1;
	//	--p2;
	//}
	inverse(buf);
	printf("%s\n", buf);
	return;
}

//通过递归的方式逆序打印
//递归和全局变量（把逆序结果存入全局变量）
//递归和非全局变量（递归指针做函数参数）

//理解递归 2个点比较重要
//参数的入栈模型
//函数嵌套调用模型
void inverse02(char*str)
{
	if (str == NULL)//递归结束的异常条件
	{
		return;
	}
	if (*str == '\0')//递归结束的条件
	{
		return;
	}
	inverse02(str + 1);//让字符串的每一个地址入栈
	printf("%c", *str);
}

void inverse03(char*str)
{
	if (str == NULL)//递归结束的异常条件
	{
		return;
	}
	if (*str == '\0')//递归结束的条件
	{
		return;
	}
	inverse03(str + 1);//让字符串的每一个地址入栈
	//strncpy_s(g_buf, 50, str, 1); 每次都覆盖掉
	strncat_s(g_buf, 50, str, 1);
}

void inverse04(char*str, char*bufresult)
{
	if (str == NULL)//递归结束的异常条件
	{
		return;
	}
	if (*str == '\0')//递归结束的条件
	{
		return;
	}
	inverse04(str + 1, bufresult);//让字符串的每一个地址入栈
	strncat_s(bufresult, 50, str, 1);
}

void maindm102()
{
	char buf[] = "abcd";
	//inverse02(buf);
	memset(g_buf,'\0',sizeof(g_buf));
	inverse03(buf);
	printf("%s\n", g_buf);
	{
		char result[1024] = { '\0' };
		inverse04(buf, result);
		printf("%s\n", result);
	}
	system("pause");
	return;
}