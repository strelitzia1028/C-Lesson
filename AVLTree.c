#include <stdio.h>
#include <stdlib.h>

// 本文件是 AVLTree.c，存放 AVL 树的相关操作函数
// AVL 树是一种自平衡二叉搜索树，具有以下性质：
// 1. 每个节点的左子树和右子树的高度差不超过 1
// 2. 每个节点的左子树和右子树都是 AVL 树
// 3. 每个节点的左子树和右子树都是平衡二叉搜索树

// AVL 树可以用来实现高效的查找、插入和删除操作，时间复杂度为 O(log n)
// AVL 树可以用来实现排序、集合、映射等数据结构，具有广泛的应用场景

// C 语言的命名规范
// C 函数名推荐 snake_case，类型名推荐 PascalCase，宏用 UPPER_CASE

// 存放的数据类型，现在只用 int
typedef int ElemType;

// AVLTree 节点结构体定义
typedef struct TreeNode
{
    ElemType data;
    // 结构体内部需要指向自身的指针（自引用）
    // 所以上面不能用匿名结构体，必须给结构体起一个名字，即 TreeNode
    // 这是结构体自己的名字，属于标签命名空间
    struct TreeNode* left;
    struct TreeNode* right;
    // 记录当前节点高度
    int height;
} TreeNode, *AVLTree;

// typedef 把 TreeNode 定义为 struct TreeNode 的别名
// 后半部分定义了另一个别名 AVLTree，它等价于 struct TreeNode *

// 获取节点高度
int get_height(AVLTree node)
{
    return node == NULL ? 0 : node->height;
}

// 更新当前节点的高度
void update_height(AVLTree node)
{
    int left_height = get_height(node->left);
    int right_height = get_height(node->right);
    if (left_height > right_height)
    {
        node->height = left_height + 1;
    }
    else
    {
        node->height = right_height + 1;
    }

    printf("update node %d height to %d\n", node->data, node->height);
}

// 右旋函数
AVLTree right_rotate(AVLTree T)
{
    AVLTree L = T->left;
    AVLTree LR = L->right;

    L->right = T;
    T->left = LR;

    // 旋转后，T 变成了 L 的右孩子
    // L 的新高度依赖于 L->left 和 L->right（也就是 T）的高度
    // 如果先更新 L，此时 T 的高度还是旋转之前的旧值
    // L 就会以这个错误的高度为基础计算，得到一个虚高的值
    // 所以要先更新 T 的高度，再更新 L 的高度
    update_height(T);
    update_height(L);

    // L 成为新根
    printf("right rotate node %d, new root %d\n", T->data, L->data);
    return L;
}

// 左旋函数
AVLTree left_rotate(AVLTree T)
{
    AVLTree R = T->right;
    AVLTree RL = R->left;

    R->left = T;
    T->right = RL;

    // 旋转后，T 变成了 R 的左孩子
    // R 的新高度依赖于 R->left 和 R->right（也就是 T）的高度
    // 如果先更新 R，此时 T 的高度还是旋转之前的旧值
    // R 就会以这个错误的高度为基础计算，得到一个虚高的值
    // 所以要先更新 T 的高度，再更新 R 的高度
    update_height(T);
    update_height(R);

    // R 成为新根
    printf("left rotate node %d, new root %d\n", T->data, R->data);
    return R;
}

// BST 插入，之后回溯检查失衡
AVLTree avl_insert(AVLTree root, ElemType val)
{
    // 情况1：找到空位，创建全新叶子节点
    if (root == NULL)
    {
        AVLTree new_node = (AVLTree)malloc(sizeof(TreeNode));
        new_node->data = val;
        new_node->left = NULL;
        new_node->right = NULL;
        new_node->height = 1; // 新节点高度为 1
        return new_node;
    }

    // 情况2：递归插入到左子树或右子树
    if (val < root->data)
    {
        root->left = avl_insert(root->left, val);
    }
    else if (val > root->data)
    {
        root->right = avl_insert(root->right, val);
    }
    else
    {
        // 情况3：不允许插入重复值，直接返回原根
        printf("repeat value %d, ignore\n", val);
        return root;
    }

    update_height(root);
    int balance = get_height(root->left) - get_height(root->right); // 获取当前的节点平衡因子

    // LL 失衡，左边左子树过重，右旋
    if (balance > 1 && val < root->left->data)
    {
        return right_rotate(root);
    }

    // RR 失衡，右边右子树过重，左旋
    if (balance < -1 && val > root->right->data)
    {
        return left_rotate(root);
    }

    // LR 失衡，左边右子树过重，先左旋再右旋
    if (balance > 1 && val > root->left->data)
    {
        root->left = left_rotate(root->left);
        return right_rotate(root);
    }

    // RL 失衡，右边左子树过重，先右旋再左旋
    if (balance < -1 && val < root->right->data)
    {
        root->right = right_rotate(root->right);
        return left_rotate(root);
    }

    // 没有失衡，直接向上返回
    return root;
}

// 遍历函数，观察结果
void in_order(AVLTree root)
{
    if (root == NULL)
    {
        return;
    }

    in_order(root->left);
    printf("%d ", root->data);
    in_order(root->right);
}

// 主函数，测试 AVLTree 的插入和旋转操作
int main()
{
    // // 触发 LL 失衡，测试右旋
    printf("Test LL imbalance:\n");
    AVLTree root_ll = NULL;
    root_ll = avl_insert(root_ll, 30);
    root_ll = avl_insert(root_ll, 20);
    root_ll = avl_insert(root_ll, 10);
    printf("result: ");
    in_order(root_ll);
    printf("\n\n");

    // 触发 RR 失衡，测试左旋
    printf("Test RR imbalance:\n");
    AVLTree root_rr = NULL;
    root_rr = avl_insert(root_rr, 10);
    root_rr = avl_insert(root_rr, 20);
    root_rr = avl_insert(root_rr, 30);
    printf("result: ");
    in_order(root_rr);
    printf("\n\n");

    // 触发 LR 失衡，测试先左旋再右旋
    printf("Test LR imbalance:\n");
    AVLTree root_lr = NULL;
    root_lr = avl_insert(root_lr, 30);
    root_lr = avl_insert(root_lr, 10);
    root_lr = avl_insert(root_lr, 20);
    printf("result: ");
    in_order(root_lr);
    printf("\n\n");

    // 触发 RL 失衡，测试先右旋再左旋
    printf("Test RL imbalance:\n");
    AVLTree root_rl = NULL;
    root_rl = avl_insert(root_rl, 10);
    root_rl = avl_insert(root_rl, 30);
    root_rl = avl_insert(root_rl, 20);
    printf("result: ");
    in_order(root_rl);
    printf("\n\n");

    // 多数据测试和重复值插入测试
    printf("Test multiple and repeated values:\n");
    AVLTree root_multi = NULL;
    root_multi = avl_insert(root_multi, 10);
    root_multi = avl_insert(root_multi, 40);
    root_multi = avl_insert(root_multi, 20);
    root_multi = avl_insert(root_multi, 50);
    root_multi = avl_insert(root_multi, 30);
    root_multi = avl_insert(root_multi, 25); // 测试重复值插入
    root_multi = avl_insert(root_multi, 11);
    root_multi = avl_insert(root_multi, 45);
    root_multi = avl_insert(root_multi, 28);
    root_multi = avl_insert(root_multi, 53);
    root_multi = avl_insert(root_multi, 32);
    root_multi = avl_insert(root_multi, 25); // 测试重复值插入
    printf("result: ");
    in_order(root_multi);
    printf("\n\n");

    return 0;
}
