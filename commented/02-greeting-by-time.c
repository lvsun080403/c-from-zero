/*
 * 02 · 按时段打招呼
 * ------------------------------------------------------------
 * 题目：读取系统当前时间，按时间段输出"早上好 / 中午好 / 下午好 / 晚上好"。
 *
 * 思路：把"几点几分"压缩成一维的"今天第几分钟"，
 *      于是原本要写成 hour 和 min 的两层判断，变成了一次比较。
 *      这也解释了为什么 6*60 这种写法：6 点 = 6 × 60 分钟。
 *
 * 易错点：
 *   1. 边界要闭合。10:59 属于早上，11:00 属于中午，
 *      所以上午的条件用 < 11*60，中午用 >= 11*60。
 *   2. 最后一个分支用 else 兜底，就不会出现"什么也没打印"的时段。
 *   3. 用了 ctime 库函数，记得 #include <time.h>。
 */

#include <stdio.h>
#include <time.h>

int main(void)
{
    /* time(NULL) 取当前时间戳，localtime 转成本地时间的结构体 */
    time_t t = time(NULL);
    struct tm *now = localtime(&t);

    /* 把时、分压成一个数：今天已经过去的分钟数，比较起来最省事 */
    int minutes = now->tm_hour * 60 + now->tm_min;

    if (minutes > 6 * 60 && minutes < 11 * 60)          /* 06:01 ~ 10:59 */
        printf("早上好\n");
    else if (minutes >= 11 * 60 && minutes <= 12 * 60)  /* 11:00 ~ 12:00 */
        printf("中午好\n");
    else if (minutes > 12 * 60 && minutes < 18 * 60)    /* 12:01 ~ 17:59 */
        printf("下午好\n");
    else                                                /* 其余时段 */
        printf("晚上好\n");

    return 0;
}
