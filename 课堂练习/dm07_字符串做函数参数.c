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
//�ַ���copy����
//from to �βε�ֵ��ͣ���ڱ仯 ���ϵ��޸�from to ��ָ��
void copy_str1(char*from, char*to)
{
	for (; *from != '\0'; ++from, ++to)
	{
		*to = *from;
	}
	*to = '\0';

	return;
}

//*���� ++����
//++���ȼ���
void copy_str2(char*from, char*to)
{
	for (; *from != '\0';)
	{
		*to++ = *from++;//��Ȼ++���ȼ��ߣ�����˳������*��ִ��
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
//��Ҫ���׸ı��βε�ֵ ����һ��������ָ��������βνӹ���
void copy_str5(char*from, char*to)
{
	char*tempfrom = from;
	char*tempto = to;
	if (tempfrom == NULL || tempto == NULL)
	{
		return;
	}
	while (*tempto++ = *tempfrom++){}
	//while (*to++ = *from++);//����Ҳ����
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
		//������
		char*to = NULL;//Ҫ�����ڴ�
		//copy_str5(from, to); 
	}
	printf("buf2:%s\n", buf2);
}