#include<stdio.h>
#include<malloc.h>

//��
char* getMem(int num)
{
	char*p = NULL;
	p = (char*)malloc(sizeof(num));
	if (p == NULL)
	{
		return NULL;
	}
	return p;
}

//ջ
//return���ǰ��ڴ��64���ֽ�return���� ���ǰ��ڴ��ĵ��׵�ַ���ڴ��ţ����س���
//���ָ��Ĺؼ����ڴ棬û���ڴ�������ָ��
//
char*getMem2()
{
	char buf[64];//��ʱ������ջ�����
	strcpy(buf,"dasdads");
	printf("buf:%s\n", buf);
	return buf;
	//Ϊʲô���ܷ��ؾֲ�ָ�������ȴ���Է��ؾֲ�����
	//�����ľֲ�������������ֵʱ��������һ���ֲ������Ŀ�����������ֵ��֮��ֲ������ᱻϵͳ���գ��������ܷ��ؾֲ������ĵ�ַ����Ϊ������ؾֲ������ĵ�ַ��ϵͳ���պ�ָ��ָ������ݾ��������ˣ����Ƕ��ھ�̬����Ҳ���Է�����ָ��
}


void main06()
{
	char*temp = getMem(10);
	printf("temp:%s.\n", temp);
	strcpy(temp,"dasdsda");//��temp��ָ����ڴ�ռ���copy����
	temp = getMem2();
	printf("temp:%s.\n",temp);

}
