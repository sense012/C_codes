#include <stdio.h>
#pragma warning(disable:4996)

void menu()
{
	printf("******************************\n");
	printf("********  1.��ʼ��Ϸ  ********\n");
	printf("********  0.������Ϸ  ********\n");
	printf("******************************\n");
}

void game()
{
	int guess = 0;
	int random = rand() % 100 +1;//���������Ϊ1��100
	printf("��������µ�����:>");
	while (1)
	{
		scanf("%d", &guess);
		if (guess == random)
		{
			printf("��ϲ�㣬�¶�����\n");
			break;
		}
		else if (guess > random)
		{
			printf("̫����Ŷ\n");
			printf("����������:>");
		}
		else if (guess < random)
		{
			printf("̫С��Ŷ\n����������:>");
		}
	}


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
		switch(input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("��Ϸ���˳�\n");
			break;
		default:
			printf("�����������������!\n");
			break;
		}
		

	} while (input);




	return 0;
}
