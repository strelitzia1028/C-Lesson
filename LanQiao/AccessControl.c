#include <stdio.h>

int main(void)
{
    int len;
    long long combination[31][31] = {0};
    long long answer = 0;

    scanf("%d", &len);

    // 使用杨辉三角计算组合数 C(i, j)
    for (int i = 0; i <= len; i++)
    {
        combination[i][0] = 1;
        combination[i][i] = 1;

        for (int j = 1; j < i; j++)
        {
            combination[i][j] =
                combination[i - 1][j - 1] +
                combination[i - 1][j];
        }
    }

    // 枚举连续段的段数 r
    for (int r = (len + 1) / 2; r <= len; r++)
    {
        int two_count = len - r; // 长度为 2 的段数
        answer += 2 * combination[r][two_count];
    }

    printf("%lld\n", answer);

    return 0;
}
