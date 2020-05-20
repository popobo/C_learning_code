#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int splitStringErJiZhiZhenZuoYe(const char*buf1, char c, char**buf2, int*count)
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
		buf2[i][j] = '\0';
		i++;
		j = 0;
		p1++;
		p2 = strchr(p1, ',');
	}
	return 0;
}


int mainErJiZhiZhenZuoYe()
{
	int ret = 0;
	char*str = "aaaaaa,bbbbbb,ccccc,dddddd,lllllll";
	char ctemp = ',';
	int nCount = 0;

	//char myArray[10][30] = { '0' };
	char**myArray = NULL;
	myArray = (char**)malloc(sizeof(char*)*10);
	for (int i = 0; i < 10; i++)
	{
		myArray[i] = (char*)malloc(sizeof(char) * 30);
		myArray[i][0] = '\0';
	}

	ret = splitStringErJiZhiZhenZuoYe(str, ctemp, myArray, &nCount);
	if (ret != 0)
	{
		printf("splitString Error");
		return ret;
	}

	for (int i = 0; i < 10; i++)
	{
		if (myArray[i][0] != '\0')
		{
			printf("%s\n", myArray[i]);
		}
	}
	for (int i = 0;i < 10;++i)
	{
		free(myArray[i]);
		myArray[i] = NULL;
	}
	free(myArray);
	myArray = NULL;
	system("pause");
	return 0;
}