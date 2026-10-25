#include <stdio.h>

int main(void)
{
    int n, k, i, isPrime;

    printf("请输入上界 n：\n");
    if (scanf("%d", &n) != 1) {
        printf("输入格式不对\n");
        return 1;
    }

    for (k = n; k >= 2; k--) {
        isPrime = 1;
        for (i = 2; i * i <= k; i++) {
            if (k % i == 0) {
                isPrime = 0;
                break;
            }
        }
        if (isPrime)
            printf("%d\n", k);
    }

    return 0;
}
