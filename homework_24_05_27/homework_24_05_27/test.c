#include <stdio.h>
#pragma warning(disable:4996)
int an(int a, int n)
{
	if (n > 1)
	{
		n--;
		return a + 10 * an(a, n);
	}
	else
		return a;
}
int main()
{
	int a = 0;
	int n = 0;
	int i = 0;
	int S = 0;
	int An = 0;
	printf("������a��n\n");//nֻ�ܴ���0
	scanf("%d %d", &a,&n);
	//An = an(a, n);
	/*for (i = 0; i < n; i++)
	{
		S += an(a, i + 1);
		printf("%d\n", an(a, i + 1));
	}
	printf("ǰ%d��ͣ�%d\n", n, S);*/
	for (i = 0; i < n; i++)
	{
		An = a + 10 * An;
		S += An;
	}
	printf("ǰ%d��ͣ�%d\n", n, S);
	return 0;
}