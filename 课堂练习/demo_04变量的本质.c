#include<stdio.h>
#include<malloc.h>

//�������ʣ�һ�������ռ�����ƺ�
void main04()
{
	int a; 
	int b;
	char* p;
	p = 0xAA11;
	a = 10;//1��ֱ�Ӹ�ֵ//cpu����ִ��

	//*((int*)7731568) = 200;//2����Ӹ�ֵ==ֱ��ͨ���ڴ�
	{
		int* p = &a;//��Ӹ�ֵ==ͨ��ָ��
		*p = 300;
	}
	printf("&a:%d\n",&a);
	printf("a:%d\n", a);
	
	//���ڴ�ռ��ܲ�����ȡ����.... C++����

}

void sub1()
{

}