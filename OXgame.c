#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define space 0
#define maru 1
#define batu 2

int N, x, y, player;
int board[17][17];
char koma[] = {'+', 'O', 'X'};

void select()
{
    while (1)
    {
        srand((unsigned int)time(NULL));
        printf("1:四連○×ゲーム\n2:五連○×ゲーム\n3:おまかせ\n");
        scanf("%d", &N);

        if (N == 3)
            N = rand() % 2 + 1;

        if (N == 1)
        {
            printf("\n四連○×ゲームを始めます．\n");
            printf("【ルール】\n自分の駒をタテ，ヨコ，ナナメのいずれかに４つ連続で並べた方が勝ちです．\n\n");
            break;
        }
        else if (N == 2)
        {
            printf("\n五連○×ゲームを始めます．\n");
            printf("【ルール】\n自分の駒をタテ，ヨコ，ナナメのいずれかに５つ連続で並べた方が勝ちです．\n\n");
            break;
        }
        else
        {
            printf("再度選択してください．\n\n");
        }
    }
}

void output()
{
    printf(" y x1 2 3 4 5 6 7 8 9101112131415\n");
    for (y = 1; y < 16; y++)
    {
        printf("%2d ", y);
        for (x = 1; x < 16; x++)
        {
            printf(" %c", koma[board[y][x]]);
        }
        printf("\n");
    }
}

void input()
{
    player = -player;
    if (player == 1)
    {
        while (1)
        {
            printf("\n先攻O　置く場所を選択（x,y）\n");
            printf("x=");
            scanf("%d", &x);
            printf("y=");
            scanf("%d", &y);
            printf("\n");

            if (board[y][x] != space || x < 1 || x > 15 || y < 1 || y > 15)
            {
                printf("ここに置くことはできません．\n再度置く場所を入力してください．\n");
            }
            else
            {
                board[y][x] = maru;
                break;
            }
        }
    }
    else
    {
        while (1)
        {
            printf("\n後攻X　置く場所を選択（x,y）\n");
            printf("x=");
            scanf("%d", &x);
            printf("y=");
            scanf("%d", &y);
            printf("\n");

            if (board[y][x] != space || x < 1 || x > 15 || y < 1 || y > 15)
            {
                printf("ここに置くことはできません．\n再度置く場所を入力してください．\n");
            }
            else
            {
                board[y][x] = batu;
                break;
            }
        }
    }
}

void judge(int *flag)
{
    int i, j, count = 0;

    if (player == 1)
    {
        for (i = 1; i < 16; i++)
        {
            if (board[y][i] == maru)
                count++;
            else
                count = 0;

            if (count == N + 3)
            {
                output();
                printf("\n先攻の勝利です．\n");
                *flag = 1;
                return;
            }
        }
        for (i = 1; i < 16; i++)
        {
            if (board[i][x] == maru)
                count++;
            else
                count = 0;

            if (count == N + 3)
            {
                output();
                printf("\n先攻の勝利です．\n");
                *flag = 1;
                return;
            }
        }
        j = y - x + 1;
        for (i = 1; i < 16; i++)
        {
            if (board[j][i] == maru)
                count++;
            else
                count = 0;

            if (count == N + 3)
            {
                output();
                printf("\n先攻の勝利です．\n");
                *flag = 1;
                return;
            }
            j++;
        }
        j = y + x - 1;
        for (i = 1; i < 16; i++)
        {
            if (board[j][i] == maru)
                count++;
            else
                count = 0;

            if (count == N + 3)
            {
                output();
                printf("\n先攻の勝利です．\n");
                *flag = 1;
                return;
            }
            j--;
        }
    }

    else
    {
        for (i = 1; i < 16; i++)
        {
            if (board[y][i] == batu)
                count++;
            else
                count = 0;

            if (count == N + 3)
            {
                output();
                printf("\n後攻の勝利です．\n");
                *flag = 1;
                return;
            }
        }
        for (i = 1; i < 16; i++)
        {
            if (board[i][x] == batu)
                count++;
            else
                count = 0;

            if (count == N + 3)
            {
                output();
                printf("\n後攻の勝利です．\n");
                *flag = 1;
                return;
            }
        }
        j = y - x + 1;
        for (i = 1; i < 16; i++)
        {
            if (board[j][i] == batu)
                count++;
            else
                count = 0;

            if (count == N + 3)
            {
                output();
                printf("\n後攻の勝利です．\n");
                *flag = 1;
                return;
            }
            j++;
        }
        j = y + x - 1;
        for (i = 1; i < 16; i++)
        {
            if (board[j][i] == batu)
                count++;
            else
                count = 0;

            if (count == N + 3)
            {
                output();
                printf("\n後攻の勝利です．\n");
                *flag = 1;
                return;
            }
            j--;
        }
    }
}

int main()
{
    int x, y, menu = 1, flag = 0;

    while (menu == 1)
    {
        for (y = 1; y < 16; y++)
        {
            for (x = 1; x < 16; x++)
            {
                board[y][x] = space;
            }
        }
        printf("\nゲームを始めます．\n");
        printf("数字は半角で入力してください．\n\n");
        select();
        player = -1;

        while (flag != 1)
        {
            output();
            input();
            judge(&flag);
        }

        printf("\n1:もう一度遊ぶ．\n2:終了する．\n");
        scanf("%d", &menu);

        if (menu == 1)
            flag = 0;
        else
            break;
    }
    return 0;
}