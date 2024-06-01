#include <stdio.h>
void print_rhombus(int n)
{
	int i = 0;
	int j = 0;
	int space = (n - 1) / 2;//每行需打印的空格个数
	int x = 1;//每行需打印的*个数
	int mid = (n + 1) / 2;
	for (i = 1; i <= mid; i++)//打印上半
	{
		for (j = 0; j < space; j++)//打印空格
			printf(" ");
		for (j = 0; j < x; j++)//打印星号
			printf("*");
		printf("\n");
		space -= 1;
		x += 2;
	}
	space += 2;
	x -= 4;
	for (i = 1; i < mid; i++)//打印下半
	{
		for (j = 0; j < space; j++)//打印空格
			printf(" ");
		for (j = 0; j < x; j++)//打印星号
			printf("*");
		printf("\n");
		space += 1;
		x -= 2;
	}
}
int main()
{
	print_rhombus(7);//参数为菱形最中间那行星号个数//////只能为奇数！
	return 0;
}
