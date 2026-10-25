#include <stdio.h>

int main(void)
{
    int count[10] = {0};
    int x, i;

    printf("请输入数字（0 ~ 9，输入 -1 结束）：\n");
    if (scanf("%d", &x) != 1)
        return 1;

    while (x != -1) {
        if (x >= 0 && x <= 9)
            count[x]++;
        if (scanf("%d", &x) != 1)
            break;
    }

    for (i = 0; i < 10; i++)
        printf("%d: %d\n", i, count[i]);

    return 0;
}
