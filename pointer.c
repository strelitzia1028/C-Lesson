#include <stdio.h>
#include <stdlib.h>

int main()
{
    // 指针：指针（pointer），常用 p 和 ptr 来命名

    // & 变量：取出该变量在内存上的门牌（内存地址）
    // * 指针：顺着门牌，去到该地址，取出里面存放的数据
    // & 和 * 同级，右结合（碰到就先算最右边那一个）

    // int* p 和 int *p 是等价的，都是定义一个指针变量 p，指向 int 类型数据

    // 盒子比喻：
    // a → 盒子里面装的数据
    // p → 盒子 (a) 的门牌号码（内存地址）
    // *p → 根据门牌号码，找到盒子，拿出里面的数据
    int a = 10;
    int *ptr = &a;

    printf("a = %d\n", a);
    printf("*ptr = %d\n", *ptr);

    // %p 是地址和指针格式化占位符，专门用来输出内存地址（十六进制）
    // 传给 %p 的参数必须是 void*（通用空指针）
    printf("&a = %p\n", (void *)&a);
    printf("ptr = %p\n", (void *)ptr);

    int nums[5] = { 1, 2, 3, 4, 5 };
    int *p = nums;    // 数组名就是数组首元素的地址，等价于 int *p = &nums[0];
    int returnSize = 2;

    int *two_sum(int *nums, int numsSize, int target, int *returnSize)
    {
        for (int i = 0; i < numsSize; i++)
        {
            for (int j = i + 1; j < numsSize; j++)
            {
                if (nums[i] + nums[j] == target)
                {
                    int *result = (int *)malloc(2 * sizeof(int));
                    result[0] = i;
                    result[1] = j;
                    *returnSize = 2;
                    return result;
                }
            }
        }
        *returnSize = 0;
        return NULL;
    }

    printf(two_sum(nums, 5, 9, &returnSize));
}
