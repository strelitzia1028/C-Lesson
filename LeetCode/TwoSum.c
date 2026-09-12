#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int value;
    int index;
} Pair;

int compare(const void* a, const void* b)
{
    Pair* x = (Pair*)a;
    Pair* y = (Pair*)b;

    if (x->value < y->value)
    {
        return -1;
    }
    if (x->value > y->value)
    {
        return 1;
    }
    return 0;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    Pair* pairs = (Pair*)malloc(sizeof(Pair) * numsSize);

    for (int i = 0; i < numsSize; i++)
    {
        pairs[i].value = nums[i];
        pairs[i].index = i;
    }

    qsort(pairs, numsSize, sizeof(Pair), compare);

    int left = 0;
    int right = numsSize - 1;

    while (left < right)
    {
        long long sum = (long long)pairs[left].value
            + pairs[right].value;

        if (sum == target)
        {
            int* answer = (int*)malloc(sizeof(int) * 2);
            answer[0] = pairs[left].index;
            answer[1] = pairs[right].index;
            *returnSize = 2;

            free(pairs);
            return answer;
        }
        else if (sum < target)
        {
            left++;
        }
        else
        {
            right--;
        }
    }

    *returnSize = 0;
    free(pairs);
    return NULL;
}

int main(void)
{
    int nums[] = {2, 7, 11, 15};
    int target = 9;
    int returnSize = 0;

    int* answer = twoSum(nums, 4, target, &returnSize);

    if (answer != NULL)
    {
        printf("[%d, %d]\n", answer[0], answer[1]);
        free(answer);
    }

    return 0;
}
