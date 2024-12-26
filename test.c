#define _CRT_SECURE_NO_WARNINGS  1
#include <stdio.h>
#include "game.h"



void menu()
{
    printf("************************\n");
    printf("*********1.����Ϸ*******\n");
    printf("*********2.�˳�*********\n");
    printf("************************\n");
}


void game()
{
    //ɨ����Ϸ�Ĺ���
    char mine[ROWS][COLS] = { 0 };//��Ų��úõ��׵���Ϣ
    char show[ROWS][COLS] = { 0 };//����ų������׵���Ϣ

    InitBoard(mine, ROWS, COLS, '0');
    InitBoard(show, ROWS, COLS, '*');

    //��ӡ����
    //DisplayBoard(mine, ROW, COL);
    //DisplayBoard(show, ROW, COL);

    //������
    SetMine(mine, ROW, COL);
    DisplayBoard(show, ROW, COL);

    //�Ų���
    FindMine(mine, show, ROW, COL);
}


void test()
{
    int input = 0;
    srand((unsigned int)time(NULL));
    do
    {
        menu();
        printf("��ѡ��:\n");
        scanf("%d", &input);
        switch (input)
        {
        case 1:
            game();
            break;
        case 2:
            printf("�˳�...\n");
            break;
        default:
            printf("������������������...\n");
            break;
        }
    } while (input);
}


int main()
{
    test();
    return 0;
}

