// Created by lsjss on 2020/6/1.

/**
 * 书上P247，实验题2：实现二叉树的各种遍历“递归”算法。（按题目要求作答，要有完整的代码和运行结果）
 *
 * 实验题2:实现二叉树的各种遍历算法
 * 目的:领会二叉树的各种遍历过程以及遍历算法设计。
 * 内容:编写一个程序exp7-2.cpp,实现二叉树的先序遍历、中序遍历和后序遍历的递归和非递归算法,
 * 以及层次遍历的算法,并对图7.33所示的二叉树b给出求解结果。
 */
#include <iostream>
#include "SqStack_BTNode.cpp"
#include "SqQueue_BTNode.cpp"

using namespace std;
#define exp7_2 main

void PreOrder(BTNode *b);   // 先序遍历的 递归算法
void InOrder(BTNode *b);    // 中序遍历的 递归算法
void PostOrder(BTNode *b);  // 后序遍历的 递归算法
void PreOrder1(BTNode *b); // 先序遍历 非递归算法
void InOrder1(BTNode *b);  // 中序遍历 非递归算法
void PostOrder1(BTNode *b);    // 后序遍历 非递归算法
void LevelOrder(BTNode *b); // 层次遍历

int exp7_2() {
    BTNode *b;
    char str[64];

    // 二叉树：　A(B(D,E(H(J,K(L,M(,N))))),C(F,G(,I)))
    printf("给定一个括号表示法二叉树：");
    scanf("%s", &str);

    CreateBTree(b, str);
    printf("初始化二叉树：");
    DispBTree(b);

    printf("\n递归先序遍历：");
    PreOrder(b);

    printf("\n递归中序遍历：");
    InOrder(b);

    printf("\n递归后序遍历：");
    PostOrder(b);

    printf("\n非递归先序遍历：");
    PreOrder1(b);

    printf("非递归中序遍历：");
    InOrder1(b);

    printf("非递归后序遍历：");
    PostOrder1(b);

    printf("层次遍历：");
    LevelOrder(b);

    return 0;
}


/** 二叉树 3 种遍历的 递归算法 */
// 先序遍历的递归算法
void PreOrder(BTNode *b) {
    if (b != NULL) {
        printf("%c ", b->data); // 访问根结点
        PreOrder(b->lchild);    // 先序遍历左子树
        PreOrder(b->rchild);    // 先序遍历右子树
    }
}

// 中序遍历的递归算法
void InOrder(BTNode *b) {
    if (b != NULL) {
        InOrder(b->lchild); // 中序遍历左子树
        printf("%c ", b->data); // 访问根结点
        InOrder(b->rchild); // 中序遍历右子树
    }
}

// 后序遍历的递归算法
void PostOrder(BTNode *b) {
    if (b != NULL) {
        PostOrder(b->lchild);   // 后序遍历左子树
        PostOrder(b->rchild);   // 后序遍历右子树
        printf("%c ", b->data); // 访问根结点
    }
}

/** 二叉树 3 种遍历的 非递归算法 */
// 先序遍历非递归算法1
void PreOrder1(BTNode *b) {
    BTNode *p;
    SqStack *st;    // 定义栈指针 st
    InitStack(st);  // 初始化栈 st
    if (b != NULL) {
        Push(st, b);    // 根结点进栈
        while (!StackEmpty(st)) {   // 栈不为空时循环
            Pop(st, p); // 退栈结点 p 并访问它
            printf("%c ", p->data);
            if (p->rchild != NULL)  // 有右孩子时将其进栈
                Push(st, p->rchild);
            if (p->lchild != NULL)  // 有左孩子时将其进栈
                Push(st, p->lchild);
        }
        printf("\n");
    }
    DestroyStack(st);   // 销毁栈
}

// 中序遍历非递归算法
void InOrder1(BTNode *b) {
    BTNode *p;
    SqStack *st;    // 定义一个顺序栈指针 st
    InitStack(st);  // 初始化栈 st
    p = b;
    while (!StackEmpty(st) || p != NULL) {
        while (p != NULL) { // 扫描结点 p 的所有左下结点并进栈
            Push(st, p);    // 结点 p 进栈
            p = p->lchild;  // 移动到左孩子
        }
        // 以下考虑栈顶结点
        if (!StackEmpty(st)) {  // 若栈不空
            Pop(st, p); // 出栈结点 p，访问结点 p
            printf("%c ", p->data);
            p = p->rchild;  // 转向处理其右子树
        }
    }
    printf("\n");
    DestroyStack(st);   // 销毁栈
}

// 后序遍历非递归算法
void PostOrder1(BTNode *b) {    // 后序非递归遍历算法
    BTNode *p, *r;
    bool flag;
    SqStack *st;    // 定义一个顺序栈指针 st
    InitStack(st);  // 初始化栈 st
    p = b;
    do {
        while (p != NULL) { // 扫描结点 p 的所有左下结点并进栈
            Push(st, p);    // 结点 p 进栈
            p = p->lchild;  // 移动到左孩子
        }
        r = NULL;   // r 指向刚刚访问的结点，初始时为空
        flag = true;    // flag 为真表示正在处理栈顶结点
        while (!StackEmpty(st) && flag) {
            GetTop(st, p);  // 取出当前的栈顶结点 p
            if (p->rchild == r) {   // 若结点 p 的右孩子为空或者为刚访问结点
                printf("%c ", p->data); // 访问结点 p
                Pop(st, p);
                r = p;  // r 指向刚访问过的结点
            } else {
                p = p->rchild;  // 转向处理其右子树
                flag = false;   // 表示当前不是处理栈顶结点
            }
        }
    } while (!StackEmpty(st));  // 栈不空循环
    printf("\n");
    DestroyStack(st);   // 销毁栈
}

// 层次遍历
void LevelOrder(BTNode *b) {
    BTNode *p;
    SqQueue *qu;    // 定义环形队列指针
    InitQueue(qu);  // 初始化队列
    enQueue(qu, b);  // 根结点指针进入队列
    while (!QueueEmpty(qu)) { // 队不为空循环
        deQueue(qu, p);   // 出队结点 p
        printf("%c ", p->data);  // 访问结点 p
        if (p->lchild != NULL)    // 有左孩子时将其进队
            enQueue(qu, p->lchild);
        if (p->rchild != NULL)    // 有右孩子时将其进队
            enQueue(qu, p->rchild);
    }
}

