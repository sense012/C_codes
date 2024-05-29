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
		int sum = 0;
		tmp = i;//重要的一步！！求位数x时改变了tmp的值
		for (int j = 0; j < x; j++)//////////////////////或用while(tmp)
		{
			int m = tmp % 10;//m为各个位上的数
			tmp /= 10;
			sum += pow(m, x);
		}
		if (sum == i)
			printf("%d为自幂数\n",i);
	}
	return 0;
}