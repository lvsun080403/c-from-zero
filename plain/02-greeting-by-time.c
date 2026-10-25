#include <stdio.h>
#include <time.h>

int main(void)
{
    time_t t = time(NULL);
    struct tm *now = localtime(&t);
    int minutes = now->tm_hour * 60 + now->tm_min;

    if (minutes > 6 * 60 && minutes < 11 * 60)
        printf("早上好\n");
    else if (minutes >= 11 * 60 && minutes <= 12 * 60)
        printf("中午好\n");
    else if (minutes > 12 * 60 && minutes < 18 * 60)
        printf("下午好\n");
    else
        printf("晚上好\n");

    return 0;
}
