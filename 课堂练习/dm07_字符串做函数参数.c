#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void maindm07()
{
	char a[] = "I am a student";
	char buf[64];
	int i = 0;
	for (i = 0; *(a + i) != '\0';++i)
	{
		*(buf + i) = *(a + i);
	}
	*(buf + i) = '\0';
	printf("a:%s\n",a);
	printf("buf:%s\n", buf);
	return;
}
//字符串copy工作
//from to 形参的值不停地在变化 不断地修改from to 的指向
void copy_str1(char*from, char*to)
{
	for (; *from != '\0'; ++from, ++to)
	{
		*to = *from;
	}
	*to = '\0';

	return;
}

//*操作 ++操作
//++优先级高
void copy_str2(char*from, char*to)
{
	for (; *from != '\0';)
	{
		*to++ = *from++;//虽然++优先级高，但是顺序上是*先执行
	}
	*to = '\0';
}

void copy_str3(char*from, char*to)
{
	while ((*to=*from)!='\0')
	{
		from++;
		to++;
	}
}

void copy_str4(char*from, char*to)
{
	while ((*to++ = *from++) != '\0'){}
}
//不要轻易改变形参的值 引入一个辅助的指针变量把形参接过来
void copy_str5(char*from, char*to)
{
	char*tempfrom = from;
	char*tempto = to;
	if (tempfrom == NULL || tempto == NULL)
	{
		return;
	}
	while (*tempto++ = *tempfrom++){}
	//while (*to++ = *from++);//这样也可以
}
void maindm071()
{
	char*from = "abcdefg";
	char*buf2[100];
	//copy_str1(from, buf2);
	//copy_str2(from, buf2);
	//copy_str3(from, buf2);
	//copy_str4(from, buf2);
	copy_str5(from, buf2);
	{
		//错误案例
		char*to = NULL;//要分配内存
		//copy_str5(from, to); 
	}
	printf("buf2:%s\n", buf2);
}