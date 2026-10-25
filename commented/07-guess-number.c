/*
 * 07 · 猜数字（三次机会）
 * ------------------------------------------------------------
 * 题目：程序随机想一个 1~100 的数，玩家猜三次；猜中输出 Good Guess，
 *      三次都没中输出 Game Over；输入负数直接退出。
 *
 * 思路：srand(time(NULL)) 用当前时间播种，保证每次运行结果不同；
 *      rand() % 100 + 1 把随机数压到 1~100。
 *      用一个 win 标记记录"猜中过没有"，循环结束后统一判断，
 *      这样就不会出现"猜中了还打印 Game Over"。
 *
 * 易错点：
 *   1. srand 只能调一次且要播种，否则每次运行都是同一串随机数。
 *   2. rand() % 100 是 0~99，要 +1 才是 1~100。
 *   3. 猜中后要 break，否则还会继续消耗次数。
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int secret, guess, i, win = 0;

    /* 用当前时间做种子，避免每次运行都猜同一个数 */
    srand((unsigned)time(NULL));
    secret = rand() % 100 + 1;      /* 1 ~ 100 */

    printf("猜一个 1 ~ 100 的数字，你有 3 次机会（输入负数直接退出）：\n");

    for (i = 1; i <= 3; i++) {
        printf("第 %d 次：\n", i);
        if (scanf("%d", &guess) != 1)
            break;

        if (guess < 0) {            /* 负数 = 主动投降 */
            printf("Game Over\n");
            return 0;
        }

        if (guess < secret) {
            printf("Too small\n");
        } else if (guess > secret) {
            printf("Too big\n");
        } else {
            printf("Good Guess\n");
            win = 1;
            break;                  /* 猜中就不再消耗次数 */
        }
    }

    /* 三次机会用完还没中才 Game Over */
    if (!win)
        printf("Game Over\n");

    return 0;
}
