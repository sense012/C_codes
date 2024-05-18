# include <stdio.h>

int count1(int n)
{
	int count = 0;
	while (n = n & (n - 1))
	{
		count++;
	}
}
int diff(int a, int b)
{
	//01001
	//01111
	//00110
	int c = a ^ b;
	int d = count1(c);
	return d;
}
int main()
{
	int a = 9;
	int b = 15;
	int c = diff(a, b);
	printf("%d", c);

	return 0;
}