#include <stdio.h>
#pragma warning(disable:4996)
#include "game.h"

void menu()
{
	printf("*************************************\n");
	printf("**********  输入1进行游戏  **********\n");
	printf("**********  输入0退出游戏  **********\n");
	printf("*************************************\n");
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
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("游戏已退出，感谢参与！");
			break;
		default:
			printf("输入有误，请重新选择！\n");
			break;
		}


	} while (input);
	
	return 0;
}