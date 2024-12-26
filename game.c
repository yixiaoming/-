#define _CRT_SECURE_NO_WARNINGS  1
#include "game.h"

//��ʼ������
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

//��ӡ����
void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
    int i = 0, j = 0;
    printf("ɨ����Ϸ\n");
    //��ӡ�к�
    for (i = 0; i <= col; i++)
    {
        printf("%d ", i);
    }
    printf("\n");
    //��ӡ������Ϣ
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

//������
void SetMine(char board[ROWS][COLS], int row, int col)
{
    //����10����
    //��������׵�λ��
    int count = EASY_COUNT;

    //ѭ������>=10����Ϊ�����׵�ʱ����Щλ���Ѿ��Ź��ˣ���Ҫ��λ��
    while (count)
    {
        int x = rand() % row +1; //1~9
        int y = rand() % col +1; //1~9

        if (board[x][y] == '0') //������λ�ò�����
        {
            board[x][y] = '1';  //�����ף�
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
        printf("��������Ҫ��������:\n");
        scanf("%d%d", &x, &y);
        if (x >= 1 && x <= row && y >= 1 && y <= col)
        {
            if (mine[x][y] == '1')
            {
                printf("�㱻��ը����\n");
                DisplayBoard(mine, ROW, COL);
                break;
            }
            else
            {
                //�ȼ����������Ƿ񱻼���
                if (show[x][y] == '*')
                {   
                    //1.ͳ�Ƹ�������Χ�м�����
                    int count = get_mine_count(mine, x, y);
                    //2.��������show��
                    show[x][y] = count + '0';  //��count + '0' �������ǽ����� count ת��Ϊ��Ӧ���ַ�.���磺count = 5��count + '0' ���� '5'��
                    DisplayBoard(show, ROW, COL);
                    win ++ ;
                }
                else
                {
                    printf("��λ���Ѿ���������\n");
                }
            }
        }
        else
        {
            printf("�����������,��������!\n");
        }
    }
    if (win == col * row - EASY_COUNT)
    {
        printf("��ϲ�㣬���׳ɹ�\n");
        DisplayBoard(mine, ROW, COL);
    }
}
