#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//һ��ָ��ĵ����÷�
//����int a[10]
//�ַ���
//1.C���Ե��ַ��� ��0��β���ַ���
//2.��C������û���ַ������� ͨ���ַ����� ��ģ���ַ���
//3.�ַ������ڴ���� ���� ջ�� ȫ����������Ҫ��

//�ַ����� ��ʼ��
void maindm051()
{
	//1.ָ������
	char buf2[100] = { 's', 'a', 'b', 'c' };
	//1-1.char buf3[3]={ 's', 'a', 'b', 'c' }; �����ʼ�����������ڴ���� �������
	//1-2.buf2[4]��buf2[99] ֵΪ0��'\0'

	//2.��ָ������
	char buf1[] = { 's', 'a', 'b' ,'c'};//buf1��һ������ ����һ����0��β���ַ���
	
	printf("buf2:%s\n", buf2);
	printf("buf2[88]:%d\n",buf2[88]);

	return;
}

//���ַ�����ʼ���ַ�����
//strlen()���Ȳ�����0
//sizeof()�ڴ��Ĵ�С
void maindm052()
{
	char buf3[] = "abcd";//buf3 ��Ϊ�ַ����� Ӧ����5���ֽ� ��Ϊ�ַ��� Ӧ����4���ֽ�
	int len = strlen(buf3);
	printf("�ַ����ȣ�%d\n",len);
	//buf3 ��Ϊ���� ������һ���������� ���ʣ��̶��ڴ��С�ı�����
	int size = sizeof(buf3);
	printf("�ڴ泤�ȣ�%d\n", size);

	{
		char buf4[128] = "abcd";
		printf("buf4[100]:%d\n",buf4[100]);
	}
	
}

//ͨ�������±��ָ��
void maindm053()
{
	char buf5[128] = "abcdefg";
	char*p = NULL;
	for (int i = 0; i < strlen(buf5); ++i)
	{
		printf("%c",buf5[i]);
	}
	p = buf5;//buf5����������Ԫ�ص�ַ
	for (int i = 0; i < strlen(buf5);++i)
	{
		printf("%c", *(p + i));
	}
	for (int i = 0; i < strlen(buf5); ++i)
	{
		printf("%c", *(buf5 + i));
	}
	{
		//buf5=0x123;
		//buf5 = buf5 + 1;
	}
	//[] * ���Ƶ�����
	//buf5[i]==>buf5[0+i]==>*(buf5+i)
	return;
}

//[]�ı��ʺ�*��һ����
//buf5��һ��ָ�� ֻ���ĳ��� buf5��һ������ָ��
//Ϊʲô��ô��
//�����ڴ�ʱ ��֤buf5��ָ����ڴ�ռ䰲ȫ�ͷ�