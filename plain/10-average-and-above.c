#include <stdio.h>

int main(void)
{
    int number[100];
    int cnt = 0;
    int x, i;
    int sum = 0;
    double avg;

    printf("请输入数字（输入 -1 结束）：\n");
    if (scanf("%d", &x) != 1)
        return 1;

    while (x != -1 && cnt < 100) {
        number[cnt] = x;
        cnt++;
        sum += x;
        printf("继续输入（-1 结束）：\n");
        if (scanf("%d", &x) != 1)
            break;
    }

    if (cnt == 0) {
        printf("没有输入任何数字\n");
        return 0;
    }

    avg = (double)sum / cnt;
    printf("平均值：%.4f\n", avg);

    for (i = 0; i < cnt; i++) {
        if (number[i] > avg)
            printf("%d\n", number[i]);
    }

    return 0;
}
