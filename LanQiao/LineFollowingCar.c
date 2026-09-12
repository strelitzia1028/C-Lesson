#include <stdio.h>

int main(void)
{
    char t[100005];
    scanf("%s", t);

    // 向右运动的总计贡献值
    int cur_right = 0;
    // 最优情况下能向右多远
    int best_right = 0;

    // 向左运动的总计贡献值
    int cur_left = 0;
    // 最优情况下能向左多远
    int best_left = 0;

    for (int i = 0; t[i] != '\0'; i++)
    {
        // 向右运动的瞬时贡献值
        int value_right;
        // 向左运动的瞬时贡献值
        int value_left;

        if (t[i] == 'L')
        {
            value_right = -1;
            value_left = 1;
        }
        else if (t[i] == 'R')
        {
            value_right = 1;
            value_left = -1;
        }
        else if (t[i] == 'S')
        {
            // S：机器人不动，贡献 0
            value_right = 0;
            value_left = 0;
        }
        else // if (t[i] == '?')
        {
            // ?：选择向有利方向移动，贡献 +1
            value_right = 1;
            value_left = 1;
        }

        // 总贡献值的累加计算
        cur_right += value_right;
        if (cur_right < 0)
        {
            cur_right = 0;
        }
        if (cur_right > best_right)
        {
            best_right = cur_right;
        }

        cur_left += value_left;
        if (cur_left < 0)
        {
            cur_left = 0;
        }
        if (cur_left > best_left)
        {
            best_left = cur_left;
        }
    }

    int max_distance = best_right;
    if (best_left > max_distance)
    {
        max_distance = best_left;
    }

    // 不要遗漏初始位置的格子，所以 max_distance 要 +1
    printf("%d\n", max_distance + 1);

    return 0;
}
