#include "mine_clearance.h"


void menu()
{
    // 菜单函数
    printf("++++++++++++++++++++++++++++++\n");
    printf("+++++++++ 1-> play +++++++++++\n");
    printf("+++++++++ 0-> exit +++++++++++\n");
    printf("++++++++++++++++++++++++++++++\n");
}

void game()
{
    char hide[ROWS][COLS];
    char show[ROWS][COLS];
    // 初始化扫雷界面
    init(hide, show);

    // 放置雷
    bomb(hide);

    // 打印

    print(show);

    // 游玩
    play(hide, show);

}

void init(char hide[ROWS][COLS], char show[ROWS][COLS])
{
    // hide数组中全部放字符'0'
    // show数组中全部放字符'*'
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            hide[i][j] = '0';
            show[i][j] = '*';
        }
    }
}

void bomb(char hide[ROWS][COLS])
{
    int count = 0;
    while(count < BOMB)
    {
        int x = rand() % 9 + 1;
        int y = rand() % 9 + 1;

        if(hide[x][y] == '0')
        {
            hide[x][y] = '1';
            count++;
        }
    }
}

void print(char board[ROWS][COLS])
{
    printf("0  1  2  3  4  5  6  7  8  9\n");
    for (int i = 1; i <= ROW; ++i) {
        printf("%i ", i);
        for (int j = 1; j <= COL; ++j) {
            printf(" %c ", board[i][j]);
        }
        printf("\n");
    }
}

void play(char hide[ROWS][COLS], char show[ROWS][COLS])
{
    int x, y;
    int count = ROW * COL - BOMB;
    while(count > 0)
    {
        printf("请输入扫雷坐标:> ");
        scanf("%i %i", &x, &y);
        if(x < 1 || y < 1 || x > ROW || y > COL)
        {
            printf("输入不合法，请重新输入\n");
            continue;
        }
        if(hide[x][y] == '1')
        {
            printf("引爆地雷，game over!!!\n");
            print(hide);
            return;
        }
        if(show[x][y] != '*')
        {
            printf("该位置已经扫过，请重新输入\n");
            continue;
        }
        char ret = check(hide, x, y);
        show[x][y] = ret;
        print(show);
        count--;
    }

    if(count == 0)
    {
        printf("恭喜你，扫雷成功!!!!\n");
    }
}

char check(char hide[ROWS][COLS], int x, int y)
{
    // 检查九宫格内有多少雷
    int count = 0;
    for(int i = x - 1; i <= x + 1; i++)
    {
        for(int j = y - 1; j <= y + 1; j++)
        {
            if(hide[i][j] == '1')
            {
                count++;
            }
        }
    }
    return (char)(count + '0');
}
