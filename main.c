#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int size;
    int capacity;
    int *data;
} IntList;

int int_list_init(IntList *lst)
{
    // 锟斤拷指锟斤拷锟斤拷锟斤拷锟斤拷锟街癸拷锟斤拷锟絅ULL锟斤拷沙锟斤拷锟斤拷锟斤拷
    if (lst == NULL)
    {
        return 0;
    }
    lst->size = 0;
    lst->capacity = 4;
    // malloc
    // 锟斤拷一锟斤拷锟斤拷锟节讹拷态锟斤拷锟斤拷锟节达拷暮锟斤拷锟斤拷锟斤拷锟斤拷锟揭伙拷锟斤拷锟斤拷锟斤拷锟絖Size锟斤拷锟斤拷示要锟斤拷锟斤拷锟斤拷纸锟斤拷锟?
    // 锟矫猴拷锟斤拷锟斤拷锟斤拷一锟斤拷指锟斤拷锟斤拷锟斤拷诖锟斤拷锟街革拷耄拷锟斤拷锟斤拷锟斤拷失锟杰ｏ拷锟津返伙拷 NULL
    lst->data = (int *)malloc(lst->capacity * sizeof(int));
    if (lst->data == NULL)
    {
        return 0; // 锟节达拷锟斤拷锟绞э拷锟?
    }
    return 1; // 锟斤拷始锟斤拷锟缴癸拷
}

int int_list_push_back(IntList *lst, int value)
{
    // 锟斤拷指锟斤拷锟斤拷锟?
    if (lst == NULL)
    {
        return 0;
    }
    if (lst->size >= lst->capacity)
    {
        // 锟斤拷锟斤拷
        lst->capacity *= 2;
        // realloc
        // 锟斤拷一锟斤拷锟斤拷锟斤拷锟斤拷锟铰凤拷锟斤拷锟节达拷暮锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷锟街革拷锟街帮拷锟斤拷锟斤拷锟节达拷锟斤拷指锟诫，锟皆硷拷锟铰碉拷锟街斤拷锟斤拷
        // 锟矫猴拷锟斤拷锟斤拷锟斤拷一锟斤拷指锟斤拷锟铰凤拷锟斤拷锟节达拷锟斤拷指锟诫，锟斤拷锟斤拷锟斤拷锟绞э拷埽锟斤拷蚍祷锟? NULL
        int *new_data = (int *)realloc(lst->data, lst->capacity * sizeof(int));
        if (new_data == NULL)
        {
            return 0; // 锟节达拷锟斤拷锟绞э拷锟?
        }
        lst->data = new_data;
    }
    // 也锟斤拷锟皆猴拷锟斤拷++
    lst->data[lst->size] = value;
    lst->size++;
    return 1; // 锟斤拷锟接成癸拷
}

void int_list_free(IntList *lst)
{
    // 锟斤拷指锟斤拷锟斤拷锟?
    if (lst == NULL)
    {
        return;
    }
    free(lst->data);  // 锟酵放讹拷态锟斤拷锟斤拷锟斤拷诖锟?
    lst->data = NULL; // 锟斤拷锟斤拷锟斤拷锟揭爸革拷锟?
    lst->size = 0;
    lst->capacity = 0;
}

int main()
{
    IntList lst;
    if (!int_list_init(&lst))

        printf("锟叫憋拷锟斤拷始锟斤拷失锟斤拷\n");
    return 1;
}

for (int i = 0; i <= 20; i++)
{
    if (!int_list_push_back(&lst, i))
    {
        printf("锟斤拷锟斤拷元锟斤拷 %d 失锟斤拷\n", i);
        int_list_free(&lst);
        return 1;
    }
}

for (int i = 0; i < lst.size; i++)
{
    printf("%d ", lst.data[i]);
    printf("size: %d, capacity: %d\n", lst.size, lst.capacity);
}
printf("\n");

int_list_free(&lst);
return 0;
}
