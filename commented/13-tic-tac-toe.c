/*
 * 13 · 井字棋（三子棋）
 * ------------------------------------------------------------
 * 题目：两个人轮流在 3×3 棋盘上下子，先连成一条线（横、竖、斜）的人赢。
 *      输入"行 列"（1~3），越界、占位、非法输入都要有提示，最后判胜负或平局。
 *
 * 思路：
 *   1. 棋盘用 int board[3][3] 表示，EMPTY=2、O=0、X=1。
 *   2. 谁走由步数决定：偶数是 X，奇数是 O。
 *   3. 每次落子后只做一件事 —— 判断"现在有没人赢"，
 *      把判断单独写成 winner()，main 里的流程就非常短。
 *   4. same(a,b,c) 是复用的核心：三个格子相同且不是空，就返回那个棋子。
 *
 * 易错点：
 *   1. 用户输入 1~3，但数组下标是 0~2，落子时必须 -1。
 *   2. 越界和占位要"不消耗这一步"：steps-- 后 continue，否则该玩家会白白丢一次机会。
 *   3. same() 里必须排除 EMPTY，否则三个空格也会被判定成"同一方赢"。
 *   4. 九步走完还没人赢才是平局，所以平局判断放在循环外面。
 */

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

    /* 初始化：全部置空 */
    for (r = 0; r < SIZE; r++)
        for (c = 0; c < SIZE; c++)
            board[r][c] = EMPTY;

    printBoard(board);

    for (steps = 0; steps < SIZE * SIZE; steps++) {
        player = (steps % 2 == 0) ? X : O;   /* 偶 X 奇 O */
        printf("%c 走哪一格（行 列，1~3）：\n", player == X ? 'X' : 'O');

        if (scanf("%d %d", &row, &col) != 2) {
            printf("输入结束\n");
            return 0;
        }

        if (row < 1 || row > SIZE || col < 1 || col > SIZE) {
            printf("超出棋盘范围\n");
            steps--;                         /* 不算一步 */
            continue;
        }
        if (board[row - 1][col - 1] != EMPTY) {
            printf("这一格已经被占了\n");
            steps--;
            continue;
        }

        board[row - 1][col - 1] = player;    /* 用户输入 1~3，数组下标 0~2 */
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

    printf("平局\n");                        /* 下满九格还没人赢 */
    return 0;
}

/* 三个格子同色且非空则返回该棋子，否则返回 -1 */
int same(int a, int b, int c)
{
    if (a == b && b == c && a != EMPTY)
        return a;
    return -1;
}

/* 检查 3 行、3 列、2 条对角线 */
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
