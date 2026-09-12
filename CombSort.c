#include <stdio.h>

void comb_sort(int arr[], int len);

int main(void)
{
    int input;
    int arr[100];
    int counter = 0;

    printf("请输入数字（输入 -1 结束）: ");
    fflush(stdout);
    scanf("%d", &input);
    while (input != -1)
    {
        arr[counter] = input;
        scanf("%d", &input);
        counter++;
    }

    printf("原始数组：");
    for (int i = 0; i < counter; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    comb_sort(arr, counter);

    printf("排序后数组：");
    for (int i = 0; i < counter; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

void comb_sort(int arr[], int len)
{
    int gap = len;

    do
    {
        // gap不断缩小
        gap = (int)(gap / 1.3);
        if (gap < 1) gap = 1; // 最小gap为1
        printf("当前的 gap 是：%d\n", gap);

        // 也可以从 1 开始计数
        // 但是需要把 i + gap < len 改为 i + gap <= len
        // 并且需要把 arr[i + gap] 改为 arr[i + gap - 1]
        for (int i = 0; i + gap < len; i++)
        {
            if (arr[i] > arr[i + gap])
            {
                int temp = arr[i];
                arr[i] = arr[i + gap];
                arr[i + gap] = temp;
            }
        }
    } while (gap > 1);
}
