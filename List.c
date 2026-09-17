#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
    int value;
    struct _node* next;
} Node;

typedef struct _list
{
    Node* head;
    // 可以再定义一个 Node* tail
} List;

void add(List* pList, int number);
void print(List* pList);
void insert(List* pList, int number, int position);
void find(List* pList, int number);

int main(void)
{
    int number;
    List list;
    list.head = NULL;
    printf("请连续输入整数（输入 -1 结束）：");
    fflush(stdout);
    do
    {
        scanf("%d", &number);
        if (number != -1)
        {
            add(&list, number);
        }
    } while (number != -1);
    print(&list);
    insert(&list, 5, 2);
    find(&list, 5); // 这里还是有 bug，如果有重复值，只能查询到第一个出现的
    return 0;
}

// 向链表中添加一个节点
void add(List* pList, int number)
{
    Node* p = (Node*)malloc(sizeof(Node));
    p->value = number;
    p->next = NULL;
    Node* last = pList->head;
    if (last)
    {
        while (last->next)
        {
            last = last->next;
        }
        last->next = p;
    }
    else
    {
        pList->head = p;
    }

    // 方法一（传出节点）
    // 在这里我们可以 return head
    // 然后在调用 add 的地方 head = add(head, number)

    // 方法二（传入指针的指针）
    // 在这里我们可以传入 Node** pHead
    // 然后在调用 add 的地方 add(&head, number)
}

// 打印链表中的所有节点
void print(List* pList)
{
    Node* p;
    for (p = pList->head; p; p = p->next)
    {
        printf("%d ", p->value);
    }
    printf("\n");
}

// 在链表的指定位置插入一个节点
void insert(List* pList, int number, int position)
{
    Node* p = (Node*)malloc(sizeof(Node));
    p->value = number;
    p->next = NULL;

    if (position == 0)
    {
        p->next = pList->head;
        pList->head = p;
        return;
    }

    Node* current = pList->head;
    for (int i = 0; i < position - 1 && current != NULL; i++)
    {
        current = current->next;
    }

    if (current != NULL)
    {
        p->next = current->next;
        current->next = p;
    }
}

// 在链表中查找指定的节点
void find(List* pList, int number)
{
    Node* current = pList->head;
    int position = 0;
    while (current != NULL)
    {
        if (current->value == number)
        {
            printf("Found %d at position %d\n", number, position);
            return;
        }
        current = current->next;
        position++;
    }
    printf("%d not found in the list\n", number);
}
