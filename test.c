#define _CRT_SECURE_NO_WARNINGS  1
#include <stdio.h>
#include "game.h"



void menu()
{
    printf("************************\n");
    printf("*********1.玩游戏*******\n");
    printf("*********2.退出*********\n");
    printf("************************\n");
}


void game()
{
    //扫雷游戏的过程
    char mine[ROWS][COLS] = { 0 };//存放布置好的雷的信息
    char show[ROWS][COLS] = { 0 };//存放排除出的雷的信息

    InitBoard(mine, ROWS, COLS, '0');
    InitBoard(show, ROWS, COLS, '*');

    //打印棋盘
    //DisplayBoard(mine, ROW, COL);
    //DisplayBoard(show, ROW, COL);

    //布置雷
    SetMine(mine, ROW, COL);
    DisplayBoard(show, ROW, COL);

    //排查雷
    FindMine(mine, show, ROW, COL);
}


void test()
{
    int input = 0;
    srand((unsigned int)time(NULL));
    do
    {
        menu();
        printf("请选择:\n");
        scanf("%d", &input);
        switch (input)
        {
        case 1:
            game();
            break;
        case 2:
            printf("退出...\n");
            break;
        default:
            printf("输入有误，请重新输入...\n");
            break;
        }
    } while (input);
}


int main()
{
    test();
    return 0;
}

