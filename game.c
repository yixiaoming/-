#define _CRT_SECURE_NO_WARNINGS  1
#include "game.h"

//初始化棋盘
void InitBoard(char board[ROWS][COLS], int rows, int cols, char set)
{
    int i, j;
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            board[i][j] = set;
        }
    }
}

//打印棋盘
void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
    int i = 0, j = 0;
    printf("扫雷游戏\n");
    //打印列号
    for (i = 0; i <= col; i++)
    {
        printf("%d ", i);
    }
    printf("\n");
    //打印棋盘信息
    for (i = 1; i <= row; i++)
    {
        printf("%d ", i);
        for (j = 1; j <= col; j++)
        {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

//放置雷
void SetMine(char board[ROWS][COLS], int row, int col)
{
    //放置10个雷
    //随机生成雷的位置
    int count = EASY_COUNT;

    //循环次数>=10，因为放置雷的时候，有些位置已经放过了，需要换位置
    while (count)
    {
        int x = rand() % row +1; //1~9
        int y = rand() % col +1; //1~9

        if (board[x][y] == '0') //如果这个位置不是雷
        {
            board[x][y] = '1';  //放置雷；
            count--;
        }
    }
}


static int get_mine_count(char mine[ROWS][COLS], int x, int y)
{
    return mine[x-1][y] + mine[x - 1][y - 1] + mine[x][y - 1] + mine[x + 1][y - 1] +
        mine[x + 1][y] + mine[x + 1][y + 1] + mine[x][y + 1] + mine[x - 1][y + 1] - 8 * '0';
}

void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
    int x = 0;
    int y = 0;
    int win = 0;
    while (win < col * row - EASY_COUNT)
    {
        printf("请输入你要检查的坐标:\n");
        scanf("%d%d", &x, &y);
        if (x >= 1 && x <= row && y >= 1 && y <= col)
        {
            if (mine[x][y] == '1')
            {
                printf("你被雷炸死了\n");
                DisplayBoard(mine, ROW, COL);
                break;
            }
            else
            {
                //先检查这个坐标是否被检查过
                if (show[x][y] == '*')
                {   
                    //1.统计该坐标周围有几个雷
                    int count = get_mine_count(mine, x, y);
                    //2.放在数组show中
                    show[x][y] = count + '0';  //，count + '0' 的作用是将整数 count 转换为对应的字符.例如：count = 5，count + '0' 等于 '5'。
                    DisplayBoard(show, ROW, COL);
                    win ++ ;
                }
                else
                {
                    printf("该位置已经被检查过了\n");
                }
            }
        }
        else
        {
            printf("坐标输入错误,重新输入!\n");
        }
    }
    if (win == col * row - EASY_COUNT)
    {
        printf("恭喜你，排雷成功\n");
        DisplayBoard(mine, ROW, COL);
    }
}
