#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int splitString(const char*buf1, char c, char buf2[10][30], int*count)
{
	char*p1 = buf1;
	char*p2 = strchr(p1, c);
	int i = 0, j = 0;
	while (p2 != NULL)
	{
		while (p1 != p2)
		{
			buf2[i][j] = *p1;
			p1++;
			j++;
		}
		i++;
		j = 0;
		p1++;
		p2 = strchr(p1, ',');
	}
	return 0;
}

//用第三种内存模型求解
int splitString2(const char*buf1, char c, char***buf2)
{

}
int maindm04LiangGeFuZhu()
{
	int ret = 0;
	char*str = "aaaaaa,bbbbbb,ccccc,dddddd,lllllll";
	char ctemp = ',';
	int nCount = 0;

	char myArray[10][30] = { '0' };
	
	ret = splitString(str, ctemp, myArray, nCount);
	if (ret != 0)
	{
		printf("splitString Error");
		return ret;
	}

	for (int i = 0; i < 10; i++) 
	{
		printf("%s\n", myArray[i]);
	}
	system("pause");
	return 0;
}
//void main()
//{
//	char*str = "aaaaaa,bbbbbb,ccccc,dddddd,";
//	char ch = ',';
//	char temp[10][30] = { '\0' };
//	int i = 0, j = 0, k = 0;
//	while (str[i] != '\0')
//	{
//		if (str[i] == ch)
//		{
//			j++;
//			k = 0;
//		}
//		else
//		{
//			temp[j][k] = str[i];
//			k++;
//		}
//		i++;
//	}
//	for (i = 0; i < 10; i++)
//	{
//		if (temp[i][0] == '\0')
//		{
//			break;
//		}
//		else
//		{
//			printf("%s\n", temp[i]);
//		}
//	}
//
//	system("pause");
//	return;
//}