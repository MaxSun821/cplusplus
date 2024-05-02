/*
 * 三子棋游戏主函数
 */

#include "game.h"

int main(void)
{
    int input;
    // 创建棋盘
    char board[ROWS][COLS] = {0};
    srand(time(NULL));
    do
    {
        menu();
        printf("请选择:> ");
        scanf("%i", &input);
        switch (input)
        {
            case 1:
                // 进入游戏
                chess_game(board);
                break;
            case 0:
                printf("退出游戏\n");
                break;
            default:
                printf("选择错误\n");
                break;
        }
    } while (input);
    return 0;
}
