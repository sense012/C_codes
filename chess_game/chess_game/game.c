# include "game.h"
void Makeboard(char board[ROW][COL], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			board[i][j] = ' ';//��˫�����ƺ����У�Ϊʲô��
		}
	}
}

void Printboard(char board[ROW][COL], int row, int col)
{
	for (int i=0;i<row;i++)
	{
		for (int j = 0; j < col; j++)
		{
			//�Լ�д��(Ҳ��)
			//if (j < col - 1)//����������ƺ����Բ��ô�
			//	printf(" %c |", board[i][j]);
			//else
			//	printf(" %c \n", board[i][j]);
			printf(" %c ", board[i][j]);
			if (j < col - 1)
			{
				printf("|");
			}
		}
		printf("\n");//��24-28��һ���
		//�����Լ��ģ��д��Ľ�
		//if (i < row - 1)
		//	for (int k = 0; k < col; k++)
		//	{
		//			printf("---|");							
		//	}
		//	printf("\n");
		if (i < row - 1)
		{
			for (int j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
				{
					printf("|");
				}
			}
			printf("\n");
		}

	}
	
}
void player(char board[ROW][COL], int row, int col)
{

	while (1)
	{
		int a = 1;
		int b = 1;
		scanf("%d %d", &a, &b);
		//�жϺϷ���
		if (1 <= a && a <= ROW && 1 <= b && b <= COL)
		{
			if (board[a - 1][b - 1] == ' ')
			{
				board[a - 1][b - 1] = '*';
				
				break;
			}
			else
			{
				printf("����������Ŷ�����°�:>");

			}
		}
		else
		{
			printf("�����������������:>");
		}
	}	
}

void AnotI(char board[ROW][COL], int row, int col)
{
	while (1)////////////////////�Լ���д��
	{
		int x = rand() % row;
		int y = rand() % col;
		if (board[x][y] == ' ')//
		{
			board[x][y] = '#';
			break;
		}
	}
}

char ifwin(char board[ROW][COL], int row, int col)
{
	
	//�����Ų�
	for (int i = 0; i < row; i++)
	{
		int flag = 1;
		for (int j = 0; j < col - 1; j++)
		{
			if (board[i][j] != board[i][j + 1])
			{
				flag = 0;
				break;
			}
		}
		if (flag == 1 && board[i][0] != ' ')
		{
			return board[i][0];
		}
	}
	//�����Ų�
	for (int i = 0; i < col; i++)
	{
		int flag = 1;
		for (int j = 0; j < row - 1; j++)
		{
			if (board[j][i] != board[j + 1][i])
			{
				flag = 0;
				break;
			}
		}
		if (flag == 1 && board[0][i] != ' ')
		{
			return board[0][i];
		}
	}
	//�Խ����Ų�
	int i = 0;
	int j = 0;
	int flag = 1;
	while (i < row-1 && j < col-1)
	{
		if (board[i][j] != board[i + 1][j + 1])
		{
			flag = 0;
			break;
		}
		i++;
		j++;
	}
	if (flag == 1 && board[i][j] != ' ')
	{
		return board[i][j];
	}
	i = row - 1;
	j = col - 1;
	flag = 1;
	while (i >0 && j > 0)
	{
		if (board[i][j] != board[i - 1][j - 1])
		{
			flag = 0;
			break;
		}
		i--;
		j--;
	}
	if (flag == 1 && board[i][j] != ' ')
	{
		return board[i][j];
	}
	if (flag == 0)
	{
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++) 
			{
				if (board[i][j] == ' ')
				{
					return 'C';
				}
			}
		}
		return 'Q';
	}
}

void game()//game������������������
{
	char board[ROW][COL];
	Makeboard(board, ROW, COL);
	Printboard(board, ROW, COL);
	char flag = '0';
	while(1)
	{
		printf("��һغϣ�����������:>");
		player(board, ROW, COL);
		Printboard(board, ROW, COL);
		flag = ifwin(board, ROW, COL);
		if (flag == '*')
		{
			printf("���Ӯ\n");
			Printboard(board, ROW, COL);
			break;
		}
		if (flag == 'Q')
		{
			printf("ƽ��\n");
			Printboard(board, ROW, COL);
			break;
		}
		printf("���Իغϣ�AnotI������:\n");
		AnotI(board, ROW, COL);
		Printboard(board, ROW, COL);
		flag = ifwin(board, ROW, COL);
		if (flag == '#')
		{
			printf("����Ӯ\n");
			Printboard(board, ROW, COL);
			break;
		}
		if (flag == 'Q')
		{
			printf("ƽ��\n");
			Printboard(board, ROW, COL);
			break;
		}
	}
}