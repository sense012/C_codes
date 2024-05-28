#include <stdio.h>
#pragma warning(disable:4996)
#include <math.h>
//找到一定范围内所有自幂数（三位自幂数为水仙花数）
//（1^3+3^3+5^3==135）
int main()
{
	int n = 0;
	printf("请输入查找范围(0-n)：");
	scanf("%d", &n);
	int i = 0;
	//for (i = 0; i <= n; i++)
	//{
	//		int x = 1;//x位数
	//		while ((i / pow(10, x)) != 0)//此处出现问题！！！
	//			x++;
	//		printf("%d的位数:%d\n", i, x);
	//}
	for (i = 0; i <= n; i++)
	{
		int x = 1;
		int tmp = i;//自己有想到
		while (tmp /= 10)//自己优化版
		{
			x++;
		}
		//成功得到位数x，接下来判断是否为自幂数


	}
	return 0;
}