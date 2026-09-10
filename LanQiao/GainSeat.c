#include <stdio.h>

int gain_position(int N, int i, int j);

int main(void)
{
    int N, i, j;

    scanf("%d %d %d", &N, &i, &j);

    printf("%d\n", gain_position(N, i, j));

    return 0;
}

int gain_position(int N, int i, int j)
{
    // 当前座位所在层：最外层为第 0 层
    int layer = i - 1;
    if (j - 1 < layer)
    {
        layer = j - 1;
    }
    if (N - i < layer)
    {
        layer = N - i;
    }
    if (N - j < layer)
    {
        layer = N - j;
    }

    // 当前层四条边的位置
    int top = layer + 1;
    int bottom = N - layer;
    int left = layer + 1;
    int right = N - layer;

    // 当前层的边长
    int side = right - left + 1;

    // 当前层左上角的编号
    int num = N * N - side * side + 1;

    // 判断当前座位位于当前层的哪一条边
    int direction;

    if (i == top)
    {
        direction = 1; // 上边：从左向右
    }
    else if (j == right)
    {
        direction = 2; // 右边：从上向下
    }
    else if (i == bottom)
    {
        direction = 3; // 下边：从右向左
    }
    else
    {
        direction = 4; // 左边：从下向上
    }

    switch (direction)
    {
    case 1:
        num += j - left;
        break;

    case 2:
        num += (side - 1) + (i - top);
        break;

    case 3:
        num += 2 * (side - 1) + (right - j);
        break;

    case 4:
        num += 3 * (side - 1) + (bottom - i);
        break;
    }

    return num;
}
