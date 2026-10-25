/*
 * 10 · 求平均值，再输出所有大于平均值的数
 * ------------------------------------------------------------
 * 题目：读入一串整数（输入 -1 结束，最多 100 个），
 *      先输出平均值（保留 4 位小数），再输出所有大于平均值的数。
 *
 * 思路：平均值 = 总和 / 个数，所以一边读一边累加 sum、一边计数 cnt，
 *      同时把每个数存进数组 number —— 因为后面还要回头比较它们。
 *      "存下来 + 统计"是数组最典型的用法。
 *
 * 易错点：
 *   1. 求平均必须先把 sum 转成 double，写成 sum / cnt 会做整数除法，
 *      比如 7 / 2 得到 3 而不是 3.5。
 *   2. cnt 既是"个数"又是"下一个要写入的下标"，所以写入用 number[cnt]，
 *      然后再 cnt++，顺序不能反。
 *   3. 一个数都没输入时不能除，要单独处理。
 */

#include <stdio.h>

int main(void)
{
    int number[100];          /* 最多存 100 个数 */
    int cnt = 0;              /* 已读入的个数，也正好是下一个空位的下标 */
    int x, i;
    int sum = 0;
    double avg;

    printf("请输入数字（输入 -1 结束）：\n");
    if (scanf("%d", &x) != 1)
        return 1;

    while (x != -1 && cnt < 100) {
        number[cnt] = x;      /* 先写 */
        cnt++;                /* 再计数 */
        sum += x;

        printf("继续输入（-1 结束）：\n");
        if (scanf("%d", &x) != 1)
            break;
    }

    if (cnt == 0) {
        printf("没有输入任何数字\n");
        return 0;
    }

    avg = (double)sum / cnt;  /* 强制转 double，避免整数除法 */
    printf("平均值：%.4f\n", avg);

    for (i = 0; i < cnt; i++) {
        if (number[i] > avg)
            printf("%d\n", number[i]);
    }

    return 0;
}
