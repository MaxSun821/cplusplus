/*
 * 猜数字游戏
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void menu();
void game();

int main(void)
{
    int input;
    srand(time(NULL)); // 初始化rand
    do
    {
        menu();
        printf("请选择(0->退出, 1->开始游戏):> ");
        scanf("%i", &input);
        switch (input) {
            case 1:
                game();
                break;
            case 0:
                printf("退出游戏\n");
                break;
            default:
                printf("选择错误\n");
        }
    } while (input);
    return 0;
}

/*
 * 菜单函数，打印菜单
 */
void menu()
{
    printf("++++++++++++++++++++++++++++\n");
    printf("+++++++++ 1-> play +++++++++\n");
    printf("+++++++++ 0-> exit +++++++++\n");
    printf("++++++++++++++++++++++++++++\n");
}

/*
 * 游戏实现函数
 */
void game()
{
    // 创建1-100的随机数
    // rand函数需要使用srand初始化
    int rand_num = rand() % 100 + 1;
    // printf("%i\n", rand_num);
    int guess;
    while (1)
    {
        printf("请猜数字:> ");
        scanf("%i", &guess);
        if(guess < rand_num)
        {
            printf("猜小了\n");
        }
        else if(guess > rand_num)
        {
            printf("猜大了\n");
        }
        else
        {
            printf("恭喜你，猜对了\n");
            break;
        }
    }
}
