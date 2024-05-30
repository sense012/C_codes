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
		for (j = 0; j < x; j++);//��ӡ�Ǻ�
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
//��ΪAIģ���ҵĴ�����д
void AI_print_rhombus(int n)
{
    int i = 0;
    int j = 0;
    int space = (n - 1) / 2; // ÿ��ǰ�����ӡ�Ŀո����
    int stars = 1; // ÿ�����ӡ���ǺŸ���
    int mid = n / 2; // �м���������Ϊn������������ֱ���������ɣ�

    // ��ӡ�ϰ벿��
    for (i = 0; i < mid; i++)
    {
        // ��ӡ�ո�
        for (j = 0; j < space; j++)
            printf(" ");
        // ��ӡ�Ǻ�
        for (j = 0; j < stars; j++)
            printf("*");
        printf("\n"); // ����
        space--; // �ո����ݼ�
        stars += 2; // �Ǻ�������
    }

    // ��ӡ�м���
    for (j = 0; j < n; j++)
        printf("*");
    printf("\n");

    // ��ӡ�°벿��
    space++; // �ո���������׼����ӡ�°벿��
    stars -= 2; // �Ǻ����ݼ�
    for (i = mid; i < n; i++) // ���м�����һ�п�ʼ��ӡ
    {
        // ��ӡ�ո�
        for (j = 0; j < space; j++)
            printf(" ");
        // ��ӡ�Ǻ�
        for (j = 0; j < stars; j++)
            printf("*");
        printf("\n"); // ����
        space++; // �ո�������
        stars -= 2; // �Ǻ����ݼ�
    }
}
int main()
{
	print_rhombus(5);//����Ϊ�������м������ǺŸ���//////ֻ��Ϊ������
    printf("---------------\n");
    AI_print_rhombus(5);
	return 0;
}
