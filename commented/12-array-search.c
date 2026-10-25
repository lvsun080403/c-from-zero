/*
 * 12 · 数组线性查找
 * ------------------------------------------------------------
 * 题目：在数组里找一个数，找到就输出它是第几个（从 1 开始），否则输出"不存在"。
 * 输入：7        输出：7 在第 7 个位置上
 *
 * 思路：从前往后挨个比，找到就立刻 return，找不到就在循环结束后 return -1。
 *      "返回位置"和"没找到"必须有区分，所以约定用 -1 表示没找到
 *      （位置从 1 开始，-1 不会是合法位置）。
 *
 * 易错点（原作业里真实出现过）：
 *   函数返回的是 i + 1，没找到返回 -1；
 *   但判断写成了 if (p != 1) —— 于是"正好在第 1 个位置"会被当成没找到。
 *   正确写法是 if (p != -1)。
 *
 *   顺便，length 用 sizeof(a) / sizeof(a[0]) 算出来，
 *   这样以后往数组里加数，不用再手动改长度。
 */

#include <stdio.h>

int search(int key, int a[], int length);

int main(void)
{
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18};
    int length = sizeof(a) / sizeof(a[0]);   /* 元素个数 */
    int x, p;

    printf("请输入要查找的数字：\n");
    if (scanf("%d", &x) != 1)
        return 1;

    p = search(x, a, length);

    if (p != -1)                             /* 不是 p != 1 */
        printf("%d 在第 %d 个位置上\n", x, p);
    else
        printf("%d 不存在\n", x);

    return 0;
}

int search(int key, int a[], int length)
{
    int i;

    for (i = 0; i < length; i++) {
        if (a[i] == key)
            return i + 1;                    /* 位置从 1 开始数 */
    }

    return -1;                               /* 没找到 */
}
