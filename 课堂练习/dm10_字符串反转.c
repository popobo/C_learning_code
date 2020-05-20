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

//ͨ���ݹ�ķ�ʽ�����ӡ
//�ݹ��ȫ�ֱ�����������������ȫ�ֱ�����
//�ݹ�ͷ�ȫ�ֱ������ݹ�ָ��������������

//���ݹ� 2����Ƚ���Ҫ
//��������ջģ��
//����Ƕ�׵���ģ��
void inverse02(char*str)
{
	if (str == NULL)//�ݹ�������쳣����
	{
		return;
	}
	if (*str == '\0')//�ݹ����������
	{
		return;
	}
	inverse02(str + 1);//���ַ�����ÿһ����ַ��ջ
	printf("%c", *str);
}

void inverse03(char*str)
{
	if (str == NULL)//�ݹ�������쳣����
	{
		return;
	}
	if (*str == '\0')//�ݹ����������
	{
		return;
	}
	inverse03(str + 1);//���ַ�����ÿһ����ַ��ջ
	//strncpy_s(g_buf, 50, str, 1); ÿ�ζ����ǵ�
	strncat_s(g_buf, 50, str, 1);
}

void inverse04(char*str, char*bufresult)
{
	if (str == NULL)//�ݹ�������쳣����
	{
		return;
	}
	if (*str == '\0')//�ݹ����������
	{
		return;
	}
	inverse04(str + 1, bufresult);//���ַ�����ÿһ����ַ��ջ
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