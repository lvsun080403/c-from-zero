#include <stdio.h>

int search(int key, int a[], int length);

int main(void)
{
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18};
    int length = sizeof(a) / sizeof(a[0]);
    int x, p;

    printf("请输入要查找的数字：\n");
    if (scanf("%d", &x) != 1)
        return 1;

    p = search(x, a, length);

    if (p != -1)
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
            return i + 1;
    }

    return -1;
}
