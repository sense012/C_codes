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
		for (j = 0; j < x; j++);//打印星号
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
//此为AI模仿我的代码所写
void AI_print_rhombus(int n)
{
    int i = 0;
    int j = 0;
    int space = (n - 1) / 2; // 每行前面需打印的空格个数
    int stars = 1; // 每行需打印的星号个数
    int mid = n / 2; // 中间行数（因为n是奇数，所以直接整除即可）

    // 打印上半部分
    for (i = 0; i < mid; i++)
    {
        // 打印空格
        for (j = 0; j < space; j++)
            printf(" ");
        // 打印星号
        for (j = 0; j < stars; j++)
            printf("*");
        printf("\n"); // 换行
        space--; // 空格数递减
        stars += 2; // 星号数递增
    }

    // 打印中间行
    for (j = 0; j < n; j++)
        printf("*");
    printf("\n");

    // 打印下半部分
    space++; // 空格数递增，准备打印下半部分
    stars -= 2; // 星号数递减
    for (i = mid; i < n; i++) // 从中间行下一行开始打印
    {
        // 打印空格
        for (j = 0; j < space; j++)
            printf(" ");
        // 打印星号
        for (j = 0; j < stars; j++)
            printf("*");
        printf("\n"); // 换行
        space++; // 空格数递增
        stars -= 2; // 星号数递减
    }
}
int main()
{
	print_rhombus(5);//参数为菱形最中间那行星号个数//////只能为奇数！
    printf("---------------\n");
    AI_print_rhombus(5);
	return 0;
}
