#define _CRT_SECURE_NO_WARNINGS

#include "game.h"
void menu()
{
	printf("-----------------------\n");
	printf("----1.play   0.exit----\n");
	printf("-----------------------\n");
}
void game()
{
	int ret = 0;
	char board[ROW][COL] = { 0 };
	init_board(board,ROW,COL);//初始化数组
	display_board(board, ROW, COL);//打印棋盘
	while (1)
	{
		player_move(board, ROW, COL);
		display_board(board, ROW, COL);
		ret = is_win(board, ROW, COL);//用ret来接受返回值
		if (ret != ' ')
		{
			break;
		}
		computer_move(board, ROW, COL);
		display_board(board, ROW, COL);
		ret = is_win(board, ROW, COL);
		if (ret != ' ')
		{
			break;
		}

	}
	if (ret == '0')
	{
		printf("恭喜玩家，赢得比赛\n");
	}
	else if (ret == 'X')
	{
		printf("恭喜电脑，赢得比赛\n");
	}
	else
	{
		printf("平局\n");
	}
}
int main()
{
	int input = 0;
	do
	{
		menu();
		printf("请输入一个数：");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
		case 0:
			printf("退出游戏?\n");
			break;
		default:
			printf("输入错误，请重新输\n");
			break;
		}
	} while (input);
	return 0;
}
