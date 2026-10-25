#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int secret, guess, i, win = 0;

    srand((unsigned)time(NULL));
    secret = rand() % 100 + 1;

    printf("猜一个 1 ~ 100 的数字，你有 3 次机会（输入负数直接退出）：\n");
    for (i = 1; i <= 3; i++) {
        printf("第 %d 次：\n", i);
        if (scanf("%d", &guess) != 1)
            break;
        if (guess < 0) {
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
            break;
        }
    }

    if (!win)
        printf("Game Over\n");

    return 0;
}
