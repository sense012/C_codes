#include <stdio.h>
#pragma warning(disable:4996)
//�д���ѧ��������������
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
	printf("a��Ϊ��%d\nb��Ϊ��%d", a, b);
	return 0;
}