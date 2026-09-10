#include <stdio.h>

void get_num(int n, int* sum);

int main(void)
{
    int input;
    int day = 0;

    scanf("%d", &input);

    while (input > 0)
    {
        int sum = 0; // 每天都要重新计算数位和
        get_num(input, &sum); // 计算当前保护值的数位和

        input -= sum; // 更新当前保护值
        day++; // 完成一天的处理
    }

    printf("%d\n", day);

    return 0;
}

void get_num(int n, int* sum)
{
    if (n > 0)
    {
        *sum += n % 10;
        get_num(n / 10, sum);
    }
}
