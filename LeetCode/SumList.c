#include <stdio.h>
#include <stdlib.h>

/* 链表节点结构体定义 */
struct ListNode
{
    int val;
    struct ListNode* next;
};

/* 根据数组创建逆序存储数字的链表 */
struct ListNode* createList(const int* arr, int size)
{
    struct ListNode dummy;
    dummy.val = 0;
    dummy.next = NULL;

    struct ListNode* tail = &dummy;

    for (int i = 0; i < size; i++)
    {
        struct ListNode* node =
            (struct ListNode*)malloc(sizeof(struct ListNode));

        node->val = arr[i];
        node->next = NULL;

        tail->next = node;
        tail = node;
    }

    return dummy.next;
}

/* 打印链表，例如：[7, 0, 8] */
void printList(struct ListNode* head)
{
    printf("[");

    struct ListNode* current = head;
    while (current != NULL)
    {
        printf("%d", current->val);

        if (current->next != NULL)
        {
            printf(", ");
        }

        current = current->next;
    }

    printf("]\n");
}

/* 释放链表空间 */
void freeList(struct ListNode* head)
{
    struct ListNode* current = head;

    while (current != NULL)
    {
        struct ListNode* next = current->next;
        free(current);
        current = next;
    }
}

/* 两数相加 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    struct ListNode dummy;
    dummy.val = 0;
    dummy.next = NULL;

    struct ListNode* tail = &dummy;

    int carry = 0;

    while (l1 != NULL || l2 != NULL || carry != 0)
    {
        int sum = carry;

        if (l1 != NULL)
        {
            sum += l1->val;
            l1 = l1->next;
        }

        if (l2 != NULL)
        {
            sum += l2->val;
            l2 = l2->next;
        }

        carry = sum / 10;

        struct ListNode* node =
            (struct ListNode*)malloc(sizeof(struct ListNode));

        node->val = sum % 10;
        node->next = NULL;

        tail->next = node;
        tail = node;
    }

    return dummy.next;
}

/* 本地测试的 main 函数 */
int main(void)
{
    int arr1[] = {2, 4, 3};
    int arr2[] = {5, 6, 4};

    struct ListNode* l1 = createList(arr1, 3);
    struct ListNode* l2 = createList(arr2, 3);

    struct ListNode* result = addTwoNumbers(l1, l2);

    printf("l1: ");
    printList(l1);

    printf("l2: ");
    printList(l2);

    printf("结果: ");
    printList(result);

    freeList(l1);
    freeList(l2);
    freeList(result);

    return 0;
}
