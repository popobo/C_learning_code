 #include<stdio.h>
#include<stdlib.h>
#include<string.h>

//char*p="abcd11122abcd3333222abcd33333222qqq";//���ַ���p ��a,b,c,d�ĳ��ִ���
//���Զ��庯���ӿ� �������Ҫ��
//�Զ����ҵ������main��������ֿ�
void maindm081()
{
	int ncount = 0;
	//��ʼ��
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
	//��ʼ��
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