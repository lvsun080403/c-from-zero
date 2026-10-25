#include <stdio.h>

int main(void)
{
    int a, n, i, t = 0, sum = 0;

    printf("请输入 a 和 n（例如 2 3 表示 2 + 22 + 222）：\n");
    if (scanf("%d %d", &a, &n) != 2 || n < 1) {
        printf("输入格式不对\n");
        return 1;
    }

    for (i = 1; i <= n; i++) {
        t = t * 10 + a;
        sum += t;
    }

    printf("%d\n", sum);
    return 0;
}
