#include <stdlib.h>
#include <stdio.h>

// getNextValue：指针变量名字

// (*getNextValue)：括号不能丢！代表这是一个函数指针，不是普通指针。

// 如果写成 int *getNextValue(void)，含义完全变了：这是一个函数声明，返回 int*。括号区分是函数指针还是普通函数声明。

// (void)：被指向的函数，接收 0 个参数

// 最前面 int：被指向的函数返回 int

void populate_array(int* array, size_t arraySize, int (*getNextValue)(void))
{
    for (size_t i = 0; i < arraySize; i++)
        array[i] = getNextValue();
}

// 获取随机值
int getNextRandomValue(void)
{
    return rand();
}

int main(void)
{
    int myarray[10];
    /* getNextRandomValue 不能加括号，否则无法编译，因为加上括号之后相当于传入此参数时传入了 int , 而不是函数指针*/
    populate_array(myarray, 10, getNextRandomValue);
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", myarray[i]);
    }
    printf("\n");
    return 0;
}

// 函数指针的等价 typedef 写法
// 定义类型 FuncPtr：代表“指向无参返回int的函数”的指针类型

// typedef int (*FuncPtr)(void);
//
// void populate_array(int *array, size_t arraySize, FuncPtr getNextValue)
// {
//     for (size_t i=0; i<arraySize; i++)
//         array[i] = getNextValue();
// }
