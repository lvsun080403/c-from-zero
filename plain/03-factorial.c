#include <stdio.h>

int main(void)
{
    int n, i;
    int fact = 1;

    printf("请输入 n（0 ~ 12）：\n");
    if (scanf("%d", &n) != 1 || n < 0) {
        printf("请输入非负整数\n");
        return 1;
    }
    if (n > 12) {
        printf("13! 已经超出 int 范围，这里只算到 12!\n");
        return 1;
    }

    for (i = 1; i <= n; i++)
        fact *= i;

    printf("%d! = %d\n", n, fact);
    return 0;
}
