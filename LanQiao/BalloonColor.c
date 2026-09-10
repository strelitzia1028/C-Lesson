#include <stdio.h>

int main(void)
{
    int count;
    int input;
    int max_count = 0;
    int arr[10] = {0}; // 下标 0~9，颜色 1~9 可直接使用

    // 有几个气球
    scanf("%d", &count);

    for (int i = 0; i < count; i++)
    {
        scanf("%d", &input);

        arr[input]++;
        if (arr[input] > max_count)
        {
            max_count = arr[input];
        }
    }

    printf("%d\n", count - max_count);

    return 0;
}
