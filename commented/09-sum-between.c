/*
 * 09 · 用函数求区间和
 * ------------------------------------------------------------
 * 题目：写一个函数 void sum(int begin, int end)，
 *      打印 [begin, end] 区间内所有整数之和；在 main 里调用三次。
 *
 * 思路：把"求和"这件事从 main 里抽出来，main 就只剩下三次调用，
 *      读起来像一句话。这是函数最朴素的用途：给一段逻辑起个名字。
 *
 * 易错点：
 *   1. 函数里的局部变量名不要和函数名同名（写成 int sum 会遮蔽函数，容易糊）。
 *   2. total 必须每次进入函数时重置为 0，否则第二次调用会接着上次的结果加。
 *   3. 函数声明（原型）要写在 main 之前，或者把整个函数体挪到 main 前面。
 */

#include <stdio.h>

void sum(int begin, int end);   /* 函数原型：先告诉编译器有这个函数 */

int main(void)
{
    sum(1, 10);                 /* 55   */
    sum(20, 30);                /* 275  */
    sum(35, 45);                /* 440  */
    return 0;
}

void sum(int begin, int end)
{
    int i;
    int total = 0;              /* 每次调用都重新从 0 开始 */

    for (i = begin; i <= end; i++)
        total += i;

    printf("%d 到 %d 的和是 %d\n", begin, end, total);
}
