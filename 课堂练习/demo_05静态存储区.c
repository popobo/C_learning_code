#include<stdio.h>
#include<malloc.h>


char* getStr1()
{	//1��ָ��ָ��˭�Ͱ�˭�ĵ�ַ����ָ��
	char*p1 = "adsdda";//�ַ���������ȫ��������ϵͳ�ͷ�
	return p1;
}
char* getStr2()
{
	char*p2 = "adsdda";
	return p2;
}

void main()
{
	char* p1 = getStr1();//2��ָ�����������ָ����ڴ�ռ������������ͬ�ĸ���
	char* p2 = getStr2();

	//��ӡp1,p2��ָ���ڴ������
	printf("p1:%s,p2:%s\n", p1, p2);
	//��ӡp1,p2��ֵ
	//��ʹ���������д��ڶ����ͬ������������Ҳֻ���ھ�̬�洢������һ��
	printf("p1:%d,p2:%d\n", p1, p2);
	system("pause");
}