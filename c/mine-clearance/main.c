/*
 * 扫雷游戏主函数
 */

#include "mine_clearance.h"

int main(void)
{
    int input;
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
                game();
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
