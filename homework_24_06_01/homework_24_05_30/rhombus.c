#include <stdio.h>
void print_rhombus(int n)
{
	int i = 0;
	int j = 0;
	int space = (n - 1) / 2;//ÿ�����ӡ�Ŀո����
	int x = 1;//ÿ�����ӡ��*����
	int mid = (n + 1) / 2;
	for (i = 1; i <= mid; i++)//��ӡ�ϰ�
	{
		for (j = 0; j < space; j++)//��ӡ�ո�
			printf(" ");
		for (j = 0; j < x; j++)//��ӡ�Ǻ�
			printf("*");
		printf("\n");
		space -= 1;
		x += 2;
	}
	space += 2;
	x -= 4;
	for (i = 1; i < mid; i++)//��ӡ�°�
	{
		for (j = 0; j < space; j++)//��ӡ�ո�
			printf(" ");
		for (j = 0; j < x; j++)//��ӡ�Ǻ�
			printf("*");
		printf("\n");
		space += 1;
		x -= 2;
	}
}
int main()
{
	print_rhombus(7);//����Ϊ�������м������ǺŸ���//////ֻ��Ϊ������
	return 0;
}
