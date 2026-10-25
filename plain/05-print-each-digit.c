#include <stdio.h>

int main(void)
{
    int a, mask = 1, t;

    printf("请输入一个正整数：\n");
    if (scanf("%d", &a) != 1 || a < 0) {
        printf("请输入非负整数\n");
        return 1;
    }

    for (t = a / 10; t > 0; t /= 10)
        mask *= 10;

    while (mask > 0) {
        printf("%d", a / mask);
        a %= mask;
        mask /= 10;
        if (mask >= 1)
            printf(" ");
    }
    printf("\n");

    return 0;
}
