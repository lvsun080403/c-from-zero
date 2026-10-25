#include <stdio.h>

#define EMPTY 2
#define O 0
#define X 1
#define SIZE 3

int same(int a, int b, int c);
int winner(int board[SIZE][SIZE]);
void printBoard(int board[SIZE][SIZE]);
void printCell(int v);

int main(void)
{
    int board[SIZE][SIZE];
    int row, col, steps, player, result;
    int r, c;

    for (r = 0; r < SIZE; r++)
        for (c = 0; c < SIZE; c++)
            board[r][c] = EMPTY;

    printBoard(board);

    for (steps = 0; steps < SIZE * SIZE; steps++) {
        player = (steps % 2 == 0) ? X : O;
        printf("%c 走哪一格（行 列，1~3）：\n", player == X ? 'X' : 'O');

        if (scanf("%d %d", &row, &col) != 2) {
            printf("输入结束\n");
            return 0;
        }
        if (row < 1 || row > SIZE || col < 1 || col > SIZE) {
            printf("超出棋盘范围\n");
            steps--;
            continue;
        }
        if (board[row - 1][col - 1] != EMPTY) {
            printf("这一格已经被占了\n");
            steps--;
            continue;
        }

        board[row - 1][col - 1] = player;
        printBoard(board);

        result = winner(board);
        if (result == X) {
            printf("X 赢了！\n");
            return 0;
        }
        if (result == O) {
            printf("O 赢了！\n");
            return 0;
        }
    }

    printf("平局\n");
    return 0;
}

int same(int a, int b, int c)
{
    if (a == b && b == c && a != EMPTY)
        return a;
    return -1;
}

int winner(int board[SIZE][SIZE])
{
    int i, r;

    for (i = 0; i < SIZE; i++) {
        r = same(board[i][0], board[i][1], board[i][2]);
        if (r != -1)
            return r;
        r = same(board[0][i], board[1][i], board[2][i]);
        if (r != -1)
            return r;
    }

    r = same(board[0][0], board[1][1], board[2][2]);
    if (r != -1)
        return r;
    r = same(board[0][2], board[1][1], board[2][0]);
    if (r != -1)
        return r;

    return -1;
}

void printCell(int v)
{
    if (v == X) {
        printf("X");
    } else if (v == O) {
        printf("O");
    } else {
        printf(".");
    }
}

void printBoard(int board[SIZE][SIZE])
{
    int r, c;

    printf("\n  1 2 3\n");
    for (r = 0; r < SIZE; r++) {
        printf("%d ", r + 1);
        for (c = 0; c < SIZE; c++) {
            printCell(board[r][c]);
            printf(" ");
        }
        printf("\n");
    }
    printf("\n");
}
