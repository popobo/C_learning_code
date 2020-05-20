#include<stdio.h>

void PrintArr(int arr[], int len)
{
	printf("函数中的sizeof(arr)=%d\n", sizeof(arr));
}


//数组做函数参数的退回问题，退回为一个指针
//结论：把数组的内存首地址和数组的有效长度传给被调用函数
//实参的a和形参的a的数据类型本质不一样
//形参中的数组，编译器会把它当成指针处理，这是C语言的特色
//形参写在函数上和写在函数内是一样的，只不过是具有对外的属性而已
int main01()
{
	int arr[] = { 1, 5, 6, 3, 4 };
	printf("main中的sizeof(arr)=%d\n",sizeof(arr));
	PrintArr(arr, 5);
	return 0;
}