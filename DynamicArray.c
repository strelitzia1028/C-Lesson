#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int size;
    int capacity;
    int* data;
} IntList;

int int_list_init(IntList* lst)
{
    // 空指针防御，防止传入NULL造成程序崩溃
    if (lst == NULL)
    {
        return 0;
    }
    lst->size = 0;
    lst->capacity = 4;
    // malloc 是一个用于动态分配内存的函数，接受一个参数：_Size，表示要分配的字节数
    // 该函数返回一个指向分配内存块的指针，如果分配失败，则返回 NULL
    lst->data = (int*)malloc(lst->capacity * sizeof(int));
    if (lst->data == NULL)
    {
        return 0; // 内存分配失败
    }
    return 1; // 初始化成功
}

int int_list_push_back(IntList* lst, int value)
{
    // 空指针防御
    if (lst == NULL)
    {
        return 0;
    }
    if (lst->size >= lst->capacity)
    {
        // 扩容
        lst->capacity *= 2;
        // realloc 是一个用于重新分配内存的函数，接受两个参数：指向之前分配的内存块的指针，以及新的字节数
        // 该函数返回一个指向新分配内存块的指针，如果分配失败，则返回 NULL
        int* new_data = (int*)realloc(lst->data, lst->capacity * sizeof(int));
        if (new_data == NULL)
        {
            return 0; // 内存分配失败
        }
        lst->data = new_data;
    }
    // 将后置++拆开，逻辑更加直观
    lst->data[lst->size] = value;
    lst->size++;
    return 1; // 添加成功
}

void int_list_free(IntList* lst)
{
    // 空指针防御
    if (lst == NULL)
    {
        return;
    }
    free(lst->data); // 释放动态分配的内存
    lst->data = NULL; // 避免出现野指针
    lst->size = 0;
    lst->capacity = 0;
}

int main()
{
    IntList lst;
    if (!int_list_init(&lst))
    {
        printf("Failed to initialize list\n");
        return 1;
    }

    for (int i = 0; i < 10; i++)
    {
        if (!int_list_push_back(&lst, i))
        {
            printf("Failed to add element %d\n", i);
            int_list_free(&lst);
            return 1;
        }
    }

    for (int i = 0; i < lst.size; i++)
    {
        printf("%d ", lst.data[i]);
    }
    printf("\n");

    int_list_free(&lst);
    return 0;
}
