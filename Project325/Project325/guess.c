#include <stdio.h>
#pragma warning(disable:4996)

void menu()
{
	printf("******************************\n");
	printf("********  1.开始游戏  ********\n");
	printf("********  0.结束游戏  ********\n");
	printf("******************************\n");
}

void game()
{
	int guess = 0;
	int random = rand() % 100 +1;//将随机数变为1到100
	printf("请输入你猜的数字:>");
	while (1)
	{
		scanf("%d", &guess);
		if (guess == random)
		{
			printf("恭喜你，猜对啦！\n");
			break;
		}
		else if (guess > random)
		{
			printf("太大了哦\n");
			printf("请重新输入:>");
		}
		else if (guess < random)
		{
			printf("太小了哦\n请重新输入:>");
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
		printf("请输入:>");
		scanf("%d", &input);
		switch(input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("游戏已退出\n");
			break;
		default:
			printf("输入出错，请重新输入!\n");
			break;
		}
		

	} while (input);




	return 0;
}
