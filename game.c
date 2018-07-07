#define _CRT_SECURE_NO_WARNINGS

#include "game.h"

void init_board(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row;i++)
	{
		int j = 0;
		for (j = 0; j < col;j++)
		{
			board[i][j] = ' ';
		}
	}
}
void display_board(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		printf("  %c  |  %c  |  %c  \n", board[i][0], board[i][1], board[i][2]);
		if (i <row - 1)
		{
			printf(" --- | --- | --- \n");
		}
	}
}

void player_move(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	
	while (1)
	{
		printf("请玩家输入要下子的坐标\n");
		printf("(例如“1 1” 行和列范围 1 - 3)：");
		scanf("%d %d",&x,&y);
		if ( (x >= 1 && x <= row + 1) && ( y >= 1 && y <= col+1) )
		{
			if (board[x-1][y-1] == ' ')
			{
				board[x-1][y-1] = '0';
				break;
			}
			else
			{
				printf("该坐标已被占用，请重新输入\n");
			}
		}
		else
		{
			printf("输入错误，请重新输入\n");
		}
	}
}

void computer_move(char board[ROW][COL], int row, int col)
{
	printf("请电脑下棋：\n");
	srand((unsigned)time(NULL));

	int count = 0;
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col;j++)
		{
			if (board[i][j] == '0')
			{
				count++;
			}
		}
	}
	while (count==1)
	{
		int x = rand() % 3;
		int y = rand() % 3;
		if (board[x][y] == ' ')
		{
			board[x][y] = 'X';
			break;
		}
	}
	while (count==2)
	{
		if (board[0][0]=='0'&&board[0][1]=='0')
		{
			board[0][2] = 'X';
			break;
	
		}
		else if (board[0][0] == '0'&&board[0][2] == '0')
		{
			board[0][1] = 'X';
			break;
		}
		else if (board[0][1] == '0'&&board[0][2] == '0')
		{
			board[0][0] = 'X';
			break;
		}//第一行
		else if (board[1][0] == '0'&&board[1][1] == '0')
		{
			board[1][2] = 'X';
			break;
		}
		else if (board[1][0] == '0'&&board[1][2] == '0')
		{
			board[1][1] = 'X';
			break;
		}
		else if (board[1][1] == '0'&&board[1][2] == '0')
		{
			board[1][0] = 'X';
			break;
		}//第二行
		else if (board[2][0] == '0'&&board[2][1] == '0')
		{
			board[2][2] = 'X';
			break;
		}
		else if (board[2][0] == '0'&&board[2][2] == '0')
		{
			board[2][1] = 'X';
			break;
		}
		else if (board[2][1] == '0'&&board[2][2] == '0')
		{
			board[2][0] = 'X';
			break;
		}//第三行
		else if (board[0][0] == '0'&&board[1][0] == '0')
		{
			board[2][0] = 'X';
			break;
		}
		else if (board[0][0] == '0'&&board[2][0] == '0')
		{
			board[1][0] = 'X';
			break;
		}
		else if (board[1][0] == '0'&&board[2][0] == '0')
		{
			board[0][0] = 'X';
			break;
		}//第一列
		else if (board[0][1] == '0'&&board[1][1] == '0')
		{
			board[2][1] = 'X';
			break;
		}
		else if (board[0][1] == '0'&&board[2][1] == '0')
		{
			board[1][1] = 'X';
			break;
		}
		else if (board[1][1] == '0'&&board[2][1] == '0')
		{
			board[0][1] = 'X';
			break;
		}//第二列
		else if (board[0][2] == '0'&&board[1][2] == '0')
		{
			board[2][2] = 'X';
			break;
		}
		else if (board[0][2] == '0'&&board[2][2] == '0')
		{
			board[1][2] = 'X';
			break;
		}
		else if (board[1][2] == '0'&&board[2][2] == '0')
		{
			board[0][2] = 'X';
			break;
		}//第三列
		else if (board[0][0] == '0'&&board[1][1] == '0')
		{
			board[2][2] = 'X';
			break;
		}
		else if (board[0][0] == '0'&&board[2][2] == '0')
		{
			board[1][1] = 'X';
			break;
		}
		else if (board[1][1] == '0'&&board[2][2] == '0')
		{
			board[0][0] = 'X';
			break;
		}//斜对角
		else if (board[0][2] == '0'&&board[1][1] == '0')
		{
			board[2][0] = 'X';
			break;
		}
		else if (board[0][2] == '0'&&board[2][0] == '0')
		{
			board[1][1] = 'X';
			break;
		}
		else if (board[1][1] == '0'&&board[2][0] == '0')
		{
			board[0][2] = 'X';
			break;
		}//斜对角
	}
	while (count == 3)
	{
		if (board[0][2] == 'X'&& board[1][1] == 'X'&&board[2][0] == ' ')
		{
			board[2][0] = 'X';
			break;
		}
		else if (board[0][2] == 'X'&& board[2][0] == 'X'&&board[1][1] == ' ')
		{
			board[1][1] = 'X';
			break;
		}
		else if (board[1][1] == 'X'&& board[2][0] == 'X'&&board[0][2] == ' ')
		{
			board[0][2] = 'X';
			break;
		}//斜对角
		else if (board[0][0] == 'X'&& board[1][1] == 'X'&&board[2][2] == ' ')
		{
			board[2][2] = 'X';
			break;
		}
		else if (board[0][0] == 'X'&& board[2][2] == 'X'&&board[1][1] == ' ')
		{
			board[1][1] = 'X';
			break;
		}
		else if (board[1][1] == 'X'&& board[2][2] == 'X'&&board[0][0] == ' ')
		{
			board[0][0] = 'X';
			break;
		}//斜对角
		else if (board[0][0] == 'X'&& board[0][1] == 'X'&&board[0][2] == ' ')
		{
			board[0][2] = 'X';
			break;
		}
		else if (board[0][0] == 'X'&& board[0][2] == 'X'&&board[0][1] == ' ')
		{
			board[0][1] = 'X';
			break;
		}
		else if (board[0][1] == 'X'&& board[0][2] == 'X'&&board[0][0] == ' ')
		{
			board[0][0] = 'X';
			break;
		}//第一行
		else if (board[1][0] == 'X'&& board[1][1] == 'X'&&board[1][2] == ' ')
		{
			board[1][2] = 'X';
			break;
		}
		else if (board[1][0] == 'X'&& board[1][2] == 'X'&&board[1][1] == ' ')
		{
			board[1][1] = 'X';
			break;
		}
		else if (board[1][1] == 'X'&& board[1][2] == 'X'&&board[0][0] == ' ')
		{
			board[0][0] = 'X';
			break;
		}//第二行
		else if (board[2][0] == 'X'&& board[2][1] == 'X'&&board[2][2] == ' ')
		{
			board[2][2] = 'X';
			break;
		}
		else if (board[2][0] == 'X'&& board[2][2] == 'X'&&board[2][1] == ' ')
		{
			board[2][1] = 'X';
			break;
		}
		else if (board[2][1] == 'X'&& board[2][2] == 'X'&&board[2][0] == ' ')
		{
			board[2][0] = 'X';
			break;
		}//第三行
		else if (board[0][0] == 'X'&& board[1][0] == 'X'&&board[2][0] == ' ')
		{
			board[2][0] = 'X';
			break;
		}
		else if (board[0][0] == 'X'&& board[2][0] == 'X'&&board[1][2] == ' ')
		{
			board[1][0] = 'X';
			break;
		}
		else if (board[1][0] == 'X'&& board[2][0] == 'X'&&board[0][0] == ' ')
		{
			board[0][0] = 'X';
			break;
		}//第一列
		else if (board[0][1] == 'X'&& board[1][1] == 'X'&&board[2][1] == ' ')
		{
			board[2][1] = 'X';
			break;
		}
		else if (board[0][1] == 'X'&& board[2][1] == 'X'&&board[1][1] == ' ')
		{
			board[1][1] = 'X';
			break;
		}
		else if (board[1][1] == 'X'&& board[2][1] == 'X'&&board[0][0] == ' ')
		{
			board[0][0] = 'X';
			break;
		}//第二列
		else if (board[0][2] == 'X'&& board[1][2] == 'X'&&board[2][2] == ' ')
		{
			board[2][2] = 'X';
			break;
		}
		else if (board[0][2] == 'X'&& board[2][2] == 'X'&&board[1][2] == ' ')
		{
			board[1][2] = 'X';
			break;
		}
		else if (board[1][2] == 'X'&& board[2][2] == 'X'&&board[0][2] == ' ')
		{
			board[0][2] = 'X';
			break;
		}//第三列
		else if (board[0][0] == ' '&&board[0][1] == '0'&&board[0][2] == '0')
		{
			board[0][0] = 'X';
			break;
		}
		else if (board[0][2] == ' '&& board[0][0] == '0'&& board[0][1] == '0')
		{
			board[0][2] = 'X';
			break;
		}
		else if (board[0][1] == ' '&&board[0][0] == '0'&&board[0][2] == '0')
		{
			board[0][1] = 'X';
			break;
		}//第一行
		else if (board[2][0] == ' '&&board[2][1] == '0'&&board[2][2] == '0')
		{
			board[2][0] = 'X';
			break;
		}
		else if (board[2][2] == ' '&&board[2][1] == '0'&&board[2][0] == '0')
		{
			board[2][2] = 'X';
			break;
		}
		else if (board[2][1] == ' '&&board[2][0] == '0'&&board[2][2] == '0')
		{
			board[2][1] = 'X';
			break;
		}//第三行
		else if (board[1][0] == ' '&&board[1][1] == '0'&&board[1][2] == '0')
		{
			board[1][0] = 'X';
			break;
		}
		else if (board[1][2] == ' '&&board[1][0] == '0'&&board[1][1] == '0')
		{
			board[1][2] = 'X';
			break;
		}//中间行
		else if (board[0][1] == ' '&&board[1][1] == '0'&&board[2][1] == '0')
		{
			board[0][1] = 'X';
			break;
		}
		else if (board[2][1] == ' '&&board[0][1] == '0'&&board[1][1] == '0')
		{
			board[2][1] = 'X';
			break;
		}//中间列
		else if (board[0][0] == ' '&&board[1][0] == '0'&&board[2][0] == '0')
		{
			board[0][0] = 'X';
			break;
		}
		else if (board[2][0] == ' '&&board[1][0] == '0'&&board[0][0] == '0')
		{
			board[2][0] = 'X';
			break;
		}
		else if (board[1][0] == ' '&&board[0][0] == '0'&&board[2][0] == '0')
		{
			board[1][0] = 'X';
			break;
		}//第一列
		else if (board[0][2] == ' '&&board[1][2] == '0'&&board[2][2] == '0')
		{
			board[0][2] = 'X';
			break;
		}
		else if (board[2][2] == ' '&&board[1][2] == '0'&&board[0][2] == '0')
		{
			board[2][2] = 'X';
			break;
		}
		else if (board[1][2] == ' '&&board[0][2] == '0'&&board[2][2] == '0')
		{
			board[1][2] = 'X';
			break;
		}//第三列
		//else if (board[0][2] == 'X'&& board[1][1] == 'X')
		//{
		//	board[2][0] = 'X';
		//	break;
		//}
		//else if (board[0][2] == 'X'&& board[2][0] == 'X')
		//{
		//	board[1][1] = 'X';
		//	break;
		//}
		//else if (board[1][1] == 'X'&& board[2][0] == 'X')
		//{
		//	board[0][2] = 'X';
		//	break;
		//}//斜对角
		//else if (board[0][0] == 'X'&& board[1][1] == 'X')
		//{
		//	board[2][2] = 'X';
		//	break;
		//}
		//else if (board[0][0] == 'X'&& board[2][2] == 'X')
		//{
		//	board[1][1] = 'X';
		//	break;
		//}
		//else if (board[1][1] == 'X'&& board[2][2] == 'X')
		//{
		//	board[0][0] = 'X';
		//	break;
		//}//斜对角
		//else if (board[0][0] == 'X'&& board[0][1] == 'X')
		//{
		//	board[0][2] = 'X';
		//	break;
		//}
		//else if (board[0][0] == 'X'&& board[0][2] == 'X')
		//{
		//	board[0][1] = 'X';
		//	break;
		//}
		//else if (board[0][1] == 'X'&& board[0][2] == 'X')
		//{
		//	board[0][0] = 'X';
		//	break;
		//}//第一行
		//else if (board[1][0] == 'X'&& board[1][1] == 'X')
		//{
		//	board[1][2] = 'X';
		//	break;
		//}
		//else if (board[1][0] == 'X'&& board[1][2] == 'X')
		//{
		//	board[1][1] = 'X';
		//	break;
		//}
		//else if (board[1][1] == 'X'&& board[1][2] == 'X')
		//{
		//	board[0][0] = 'X';
		//	break;
		//}//第二行
		//else if (board[2][0] == 'X'&& board[2][1] == 'X')
		//{
		//	board[2][2] = 'X';
		//	break;
		//}
		//else if (board[2][0] == 'X'&& board[2][2] == 'X')
		//{
		//	board[2][1] = 'X';
		//	break;
		//}
		//else if (board[2][1] == 'X'&& board[2][2] == 'X')
		//{
		//	board[2][0] = 'X';
		//	break;
		//}//第三行
		//else if (board[0][0] == 'X'&& board[1][0] == 'X')
		//{
		//	board[2][0] = 'X';
		//	break;
		//}
		//else if (board[0][0] == 'X'&& board[2][0] == 'X')
		//{
		//	board[1][0] = 'X';
		//	break;
		//}
		//else if (board[1][0] == 'X'&& board[2][0] == 'X')
		//{
		//	board[0][0] = 'X';
		//	break;
		//}//第一列
		//else if (board[0][1] == 'X'&& board[1][1] == 'X')
		//{
		//	board[2][1] = 'X';
		//	break;
		//}
		//else if (board[0][1] == 'X'&& board[2][1] == 'X')
		//{
		//	board[1][1] = 'X';
		//	break;
		//}
		//else if (board[1][1] == 'X'&& board[2][1] == 'X')
		//{
		//	board[0][0] = 'X';
		//	break;
		//}//第二列
		//else if (board[0][2] == 'X'&& board[1][2] == 'X')
		//{
		//	board[2][2] = 'X';
		//	break;
		//}
		//else if (board[0][2] == 'X'&& board[2][2] == 'X')
		//{
		//	board[1][2] = 'X';
		//	break;
		//}
		//else if (board[1][2] == 'X'&& board[2][2] == 'X')
		//{
		//	board[0][2] = 'X';
		//	break;
		//}//第三列
		
		
	}
	while (count == 4)
	{
		if (board[0][1] == ' '&&board[1][1] == '0'&&board[2][1] == '0')
		{
			board[0][1] = 'X';
			break;
		}//第一行
		else if (board[1][2] == ' '&&board[0][2] == '0'&&board[2][2] == '0')
		{
			board[1][2] = 'X';
			break;
		}//第三列
		else if (board[2][1] == ' '&&board[2][0] == '0'&&board[2][2] == '0')
		{
			board[2][1] = 'X';
			break;
		}//第三行
		else if (board[1][0] == ' '&&board[0][0] == '0'&&board[2][0] == '0')
		{
			board[1][0] = 'X';
			break;
		}//第一列
		else if (board[1][0] == ' '&&board[1][1] == '0'&&board[1][2] == '0')
		{
			board[1][0] = 'X';
			break;
		}
		else if (board[1][2] == ' '&&board[1][0] == '0'&&board[1][1] == '0')
		{
			board[1][2] = 'X';
			break;
		}//第二行
		else if (board[0][1] == ' '&&board[1][1] == '0'&&board[2][1] == '0')
		{
			board[0][1] = 'X';
			break;
		}
		else if (board[2][1] == ' '&&board[0][1] == '0'&&board[1][1] == '0')
		{
			board[2][1] = 'X';
			break;
		}//第二列
	}


}

static int is_full(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;
			}
		}
	}
	return 1;//棋盘满了
}

char is_win(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		if ((board[i][0] != ' ')&&(board[i][0] == board[i][1]) && (board[i][1] == board[i][2]))
		{
			return board[i][1];
		}
	}

	for (j = 0; j < col; j++)
	{
		if ((board[0][j] != ' ')&&(board[0][j] == board[1][j]) && (board[1][j] == board[2][j]))
		{
			return board[1][j];
		}
	}

	if ((board[0][0] != ' ')&&(board[0][0] == board[1][1]) && (board[1][1] == board[2][2]))
	{
		return board[1][1];
	}
	if ((board[0][2] != ' ')&&(board[0][2] == board[1][1]) &&( board[1][1] == board[2][0]))
	{
		return board[1][1];
	}

	if (is_full(board, row, col))
	{
		return 'q';
	}
	return ' ';
}
