#include <stdio.h>

int main(void)
{
    int n, i, j, digits, first = 1, t, d, sum, p;

    printf("请输入位数 n（3 就是水仙花数）：\n");
    if (scanf("%d", &n) != 1 || n < 1 || n > 7) {
        printf("位数取 1 ~ 7\n");
        return 1;
    }

    for (i = 1; i < n; i++)
        first *= 10;

    for (i = first; i < first * 10; i++) {
        t = i;
        sum = 0;
        while (t > 0) {
            d = t % 10;
            t /= 10;
            p = 1;
            for (j = 0; j < n; j++)
                p *= d;
            sum += p;
        }
        if (sum == i)
            printf("%d\n", i);
    }

    return 0;
}
