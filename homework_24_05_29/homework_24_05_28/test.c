#include <stdio.h>
#pragma warning(disable:4996)
#include <math.h>
//�ҵ�һ����Χ����������������λ������Ϊˮ�ɻ�����
//��1^3+3^3+5^3==135��
int main()
{
	int n = 0;
	printf("��������ҷ�Χ(0-n)��");
	scanf("%d", &n);
	int i = 0;
	//for (i = 0; i <= n; i++)
	//{
	//		int x = 1;//xλ��
	//		while ((i / pow(10, x)) != 0)//�˴��������⣡����
	//			x++;
	//		printf("%d��λ��:%d\n", i, x);
	//}
	for (i = 0; i <= n; i++)
	{
		int x = 1;
		int tmp = i;//�Լ����뵽
		while (tmp /= 10)//�Լ��Ż���
		{
			x++;
		}
		//�ɹ��õ�λ��x���������ж��Ƿ�Ϊ������
		int sum = 0;
		tmp = i;//��Ҫ��һ��������λ��xʱ�ı���tmp��ֵ
		for (int j = 0; j < x; j++)//////////////////////����while(tmp)
		{
			int m = tmp % 10;//mΪ����λ�ϵ���
			tmp /= 10;
			sum += pow(m, x);
		}
		if (sum == i)
			printf("%dΪ������\n",i);
	}
	return 0;
}