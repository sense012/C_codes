#include <stdio.h>
#pragma warning(disable:4996)
#include "game.h"

void menu()
{
	printf("*************************************\n");
	printf("**********  ����1������Ϸ  **********\n");
	printf("**********  ����0�˳���Ϸ  **********\n");
	printf("*************************************\n");
}
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("������:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("��Ϸ���˳�����л���룡");
			break;
		default:
			printf("��������������ѡ��\n");
			break;
		}


	} while (input);
	
	return 0;
}