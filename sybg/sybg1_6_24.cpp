// Created by lsjss on 2020/6/25.

#include <iostream>

using namespace std;
//#define sybg1_6_24 main

// 二叉树的定义和各种运算部分
#define MaxSize 100
typedef char ElemType;
typedef struct node {
    ElemType data;
    struct node *lchild;
    struct node *rchild;
} BTNode;

//1 创建二叉树
void CreateBTree(BTNode *&b, char *str) {  //由str ? 二叉链b
    BTNode *St[MaxSize], *p;
    int top = -1, k, j = 0;
    char ch;
    b = NULL;        //建立的二叉链初始时为空
    ch = str[j];
    while (ch != '\0') { //str未扫描完时循环
        switch (ch) {
            case '(':
                top++;
                St[top] = p;
                k = 1;
                break;  //可能有左孩子结点，进栈
            case ')':
                top--;
                break;
            case ',':
                k = 2;
                break;  //后面为右孩子结点
            default:    //遇到结点值
                p = (BTNode *) malloc(sizeof(BTNode));
                p->data = ch;
                p->lchild = p->rchild = NULL;
                if (b == NULL)  //p为二叉树的根结点
                    b = p;
                else {  //已建立二叉树根结点
                    {
                        switch (k) {
                            case 1:
                                St[top]->lchild = p;
                                break;
                            case 2:
                                St[top]->rchild = p;
                                break;
                        }
                    }
                }
        }
        j++;
        ch = str[j];    //继续扫描str
    }
}

//2 销毁二叉树
void DestroyBTree(BTNode *&b) {
    if (b == NULL) return;
    else {
        DestroyBTree(b->lchild);
        DestroyBTree(b->rchild);
        free(b);    //剩下一个结点b，直接释放
    }
}

//3 查找结点
BTNode *FindNode(BTNode *b, ElemType x) {
    BTNode *p;
    if (b == NULL) return NULL;
    else if (b->data == x) return b;
    else {
        p = FindNode(b->lchild, x);
        if (p != NULL) return p;
        else return FindNode(b->rchild, x);
    }
}

//5 求二叉树的高度
int BTHeight(BTNode *b) {
    int lchilddep, rchilddep;
    if (b == NULL) return (0);  //空树的高度为0
    else {
        lchilddep = BTHeight(b->lchild);
        // 求左子树的高度为 lchilddep
        rchilddep = BTHeight(b->rchild);
        // 求右子树的高度为 rchilddep
        return (lchilddep > rchilddep) ? (lchilddep + 1) : (rchilddep + 1);
    }
}

//6 输出二叉树
void DispBTree(BTNode *b) {
    if (b != NULL) {
        printf("%c", b->data);
        if (b->lchild != NULL || b->rchild != NULL) {
            printf("(");
            DispBTree(b->lchild);   //递归处理左子树
            if (b->rchild != NULL) printf(",");
            DispBTree(b->rchild);   //递归处理右子树
            printf(")");
        }
    }
}


// 队列定义和各种算法部分
#define MaxSize2 50
typedef struct {
    ElemType data[MaxSize2];
    int front, rear;    //队首和队尾指针
} SqQueue;

////1 初始化队列
//void InitQueue(SqQueue *&q) {
//    q = (SqQueue *) malloc(sizeof(SqQueue));
//    q->front = q->rear = 0;
//}


// 栈定义部分
#define Maxsize3 50
typedef struct {
    BTNode *data[Maxsize3];
    int top;    //顺序栈栈顶指针
} SqStack;

void InitStack(SqStack *&s) {
    s = (SqStack *) malloc(sizeof(SqStack));
    s->top = -1;
}

// 销毁顺序栈
void DestroyStack(SqStack *&s) {
    free(s);
}

// 判断顺序栈是否为空
bool StackEmpty(SqStack *s) {
    return (s->top == -1);
}

// 进栈
bool Push(SqStack *&s, BTNode *e) {
    if (s->top == Maxsize3 - 1) {    //栈满的情况，即栈上溢出
        return false;
    }
    s->top++;   //栈顶指针增1
    s->data[s->top] = e;  //元素e放在栈顶指针处
    return true;
}

// 出栈
bool Pop(SqStack *&s, BTNode *&e) {
    if (s->top == -1){  //栈为空的情况，即栈下溢出
        return false;
    }
    e = s->data[s->top];    //取栈顶指针元素的元素
    s->top--;   //栈顶指针减1
    return true;
}

// 获取顺序栈栈顶元素
bool GetTop(SqStack *s, BTNode *&e) {
    if (s->top == -1)
        return false;
    e = s->data[s->top];
    return true;
}

// 遍历算法部分
// 递归先序遍历
void PreOrder(BTNode *b) {
    if (b != NULL) {
        cout << b->data;
        PreOrder(b->lchild);
        PreOrder(b->rchild);
    }
}

//非递归先序遍历
void PreOrder1(BTNode *b) {
    BTNode *p;
    SqStack *st;
    InitStack(st);
    if (b != NULL) {
        Push(st, b);
        while (!StackEmpty(st)) {
            Pop(st, p);
            cout << p->data;
            if (p->rchild != NULL) {
                Push(st, p->rchild);
            }
            if (p->lchild != NULL) {
                Push(st, p->lchild);
            }
        }
        cout << endl;
    }
    DestroyStack(st);
}

//递归中序遍历
void InOrder(BTNode *b) {
    if (b != NULL) {
        InOrder(b->lchild);
        cout << b->data;
        InOrder(b->rchild);
    }
}

//非递归中序遍历
void InOrder1(BTNode *b) {
    BTNode *p;
    SqStack *st;
    InitStack(st);
    p = b;
    while (!StackEmpty(st) || p != NULL) {
        while (p != NULL) {
            Push(st, p);
            p = p->lchild;
        }
        if (!StackEmpty(st)) {
            Pop(st, p);
            cout << p->data;
            p = p->rchild;
        }
    }
    cout << endl;
    DestroyStack(st);
}

//递归后序遍历
void PostOrder(BTNode *b) {
    if (b != NULL) {
        PostOrder(b->lchild);
        PostOrder(b->rchild);
        cout << b->data;
    }
}

//非递归后序遍历
void PostOrder1(BTNode *b) {
    BTNode *p, *r;
    bool flag;
    SqStack *st;
    InitStack(st);
    p = b;
    do {
        while (p != NULL) {
            Push(st, p);
            p = p->lchild;
        }
        r = NULL;
        flag = true;
        while (!StackEmpty(st) && flag) {
            GetTop(st, p);
            if (p->rchild == r) {
                cout << p->data;
                Pop(st, p);
                r = p;
            } else {
                p = p->rchild;
                flag = false;
            }
        }
    } while (!StackEmpty(st));
    cout << endl;
    DestroyStack(st);
}


int sybg1_6_24() {
    BTNode *b;
    char str[64];

    // 二叉树：　A(B(D,E),C(F,G))
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

    return 0;
}
