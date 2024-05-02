/*
 * 游戏实现文件
 */

#include "game.h"


void menu()
{
    // 菜单函数
    printf("++++++++++++++++++++++++++++++\n");
    printf("+++++++++ 1-> play +++++++++++\n");
    printf("+++++++++ 0-> exit +++++++++++\n");
    printf("++++++++++++++++++++++++++++++\n");
}

// 初始化棋盘
void init(char board[ROWS][COLS])
{
    // 把棋盘位置设置空格
    for (int i = 0; i < ROWS; ++i)
    {
        for (int j = 0; j < COLS; ++j)
        {
            board[i][j] = ' ';
        }
    }
}

// 打印棋盘
void print(char board[ROWS][COLS])
{
    int i = 0;
    int j = 0;
    for (i = 0; i < ROWS; ++i)
    {
        for (j = 0; j < COLS; ++j)
        {
            printf(" %c ", board[i][j]);
            if(j < COLS - 1)
            {
                printf("|");
            }
        }
        printf("\n");
        if(i < ROWS - 1)
        {
            for (j = 0; j < COLS; ++j)
            {
                printf("---");
                if(j < COLS - 1)
                {
                    printf("|");
                }
            }
        }

        printf("\n");
    }
}

void chess_game(char board[ROWS][COLS])
{
    init(board);
    while(1)
    {
        // 玩家下棋
        player(board);
        if(is_win(board) != 'C')
        {
            break;
        }
        // 电脑下棋
        computer(board);
        if(is_win(board) != 'C')
        {
            break;
        }
        print(board);
    }
    if(is_win(board) == '*')
    {
        printf("玩家胜利\n");
    }
    else if(is_win(board) == '#')
    {
        printf("电脑胜利\n");
    }
    else
    {
        printf("平局\n");
    }
    print(board);
}


void player(char board[ROWS][COLS])
{
    int x, y;
    again:
    printf("请玩家输入下棋位置(x, y):> ");
    scanf("%i %i", &x, &y);
    if(x > ROWS || y > COLS)
    {
        printf("参数不合法，请重新输入\n");
        goto again;
    }
    if(board[x - 1][y - 1] != ' ')
    {
        printf("该位置已有棋子，请重新输入\n");
        goto again;
    }
    board[x - 1][y - 1] = '*';
}

void computer(char board[ROWS][COLS])
{
    while(1)
    {
        // 随机生成0-2的整数
        int x = rand() % 3;
        int y = rand() % 3;
        if(board[x][y] == ' ')
        {
            board[x][y] = '#';
            break;
        }
    }
}

char is_win(char board[ROWS][COLS])
{
    int i = 0;
    int j = 0;
    // 判断同一行是否一样
    while(i < ROWS)
    {
        if(board[i][j] == board[i][j + 1] && board[i][j + 1] == board[i][j + 2] && board[i][j] != ' ')
        {
            return board[i][j];
        }
        i++;
    }
    // 判断同一列
    i = 0;
    j = 0;
    while(j < COLS)
    {
        if(board[i + 1][j] == board[i][j] && board[i][j] == board[i + 2][j] && board[i][j] != ' ')
        {
            return board[i][j];
        }
        j++;
    }
    // 判断对角线
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
    {
        return board[1][1];
    }
    if(board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[1][1] != ' ')
    {
        return board[1][1];
    }

    // 判断棋盘是否满了
    for (i = 0; i < ROWS; ++i) {
        for (j = 0; j < COLS; ++j) {
            if(board[i][j] == ' ')
            {
                return 'C'; // 棋盘未满
            }
        }
    }
    return 'Q'; // 棋盘满了
}
