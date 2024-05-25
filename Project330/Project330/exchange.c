#include <stdio.h>
#pragma warning(disable:4996)
//有待重学！！！！！！！
void exchange(int *a, int *b)
{
	int c;
	c = *a;
	*a = *b;
	*b = c;
}
int main()
{
	int a;
	int b;
	scanf("%d %d", &a, &b);
	exchange(&a, &b);
	printf("a变为：%d\nb变为：%d", a, b);
	return 0;
}