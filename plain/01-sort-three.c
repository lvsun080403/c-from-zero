#include <stdio.h>

int main(void)
{
    int a, b, c, t;

    printf("请输入三个整数（空格分隔）：\n");
    if (scanf("%d %d %d", &a, &b, &c) != 3) {
        printf("输入格式不对\n");
        return 1;
    }

    if (a < b) { t = a; a = b; b = t; }
    if (b < c) { t = b; b = c; c = t; }
    if (a < b) { t = a; a = b; b = t; }

    printf("从大到小：%d %d %d\n", a, b, c);
    return 0;
}
