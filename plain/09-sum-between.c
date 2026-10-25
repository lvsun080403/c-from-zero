#include <stdio.h>

void sum(int begin, int end);

int main(void)
{
    sum(1, 10);
    sum(20, 30);
    sum(35, 45);
    return 0;
}

void sum(int begin, int end)
{
    int i;
    int total = 0;

    for (i = begin; i <= end; i++)
        total += i;

    printf("%d 到 %d 的和是 %d\n", begin, end, total);
}
