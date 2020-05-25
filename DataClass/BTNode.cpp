// Created by lsjss on 2020/5/24.
#include <iostream>
#include <malloc.h>

using namespace std;
// 二叉链
#define MaxSize 50
typedef int ElemType;

typedef struct node {
    ElemType data;
    struct node *lchild, *rchild;
} BTNode;

//1 创建二叉树
void CreateBTree(BTNode *&b, char *str) {  //由str  二叉链b
    BTNode *St[MaxSize], *p;
    int top = -1, k, j = 0;
    char ch;
    b = NULL;        //建立的二叉链初始时为空
    ch = str[j];
    while (ch != '\0')    //str未扫描完时循环
    {
        switch (ch) {
            case '(':
                top++;
                St[top] = p;
                k = 1;
                break; //可能有左孩子结点，进栈
            case ')':
                top--;
                break;
            case '，':
                k = 2;
                break;             //后面为右孩子结点
            default:                 //遇到结点值
                p = (BTNode *) malloc(sizeof(BTNode));
                p->data = ch;
                p->lchild = p->rchild = NULL;
                if (b == NULL)            //p为二叉树的根结点
                    b = p;
                else                //已建立二叉树根结点
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
        j++;
        ch = str[j];        //继续扫描str
    }
}

//2 销毁二叉链
void DestroyBTree(BTNode *&b) {
    if (b == NULL) return;
    else {
        DestroyBTree(b->lchild);
        DestroyBTree(b->rchild);
        free(b);      //剩下一个结点b，直接释放
    }
}

//3 查找结点
BTNode *FindNode(BTNode *b, ElemType x) {
    BTNode *p;
    if (b == NULL) return NULL;
    else if (b->data == x) return b;
    else {
        p = FindNode(b->lchild
        x);
        if (p != NULL) return p;
        else return FindNode(b->rchild, x);
    }
}

//4 找左孩子结点
BTNode *LchildNode(BTNode *p) {
    return p->lchild;
}

//4 找右孩子结点
BTNode *RchildNode(BTNode *p) {
    return p->rchild;
}

//5 求高度
int BTHeight(BTNode *b) {
    int lchilddep, rchilddep;
    if (b == NULL) return (0);    //空树的高度为0
    else {
        lchilddep = BTHeight(b->lchild);
        //求左子树的高度为lchilddep
        rchilddep = BTHeight(b->rchild);
        //求右子树的高度为rchilddep
        return (lchilddep > rchilddep) ? (lchilddep + 1) : (rchilddep + 1));
    }
}

//6 输出二叉树
void DispBTree(BTNode *b) {
    if (b != NULL) {
        printf("%c", b->data);
        if (b->lchild != NULL || b->rchild != NULL) {
            printf("(");
            DispBTree(b->lchild); //递归处理左子树
            if (b->rchild != NULL) printf("，");
            DispBTree(b->rchild); //递归处理右子树
            printf(")");
        }
    }
}


/** 二叉树3种遍历的递归算法 */
// 先序遍历的递归算法
void PreOrder(BTNode *b) {
    if (b != NULL) {
        printf("%c ", b->data);    //访问根结点
        PreOrder(b->lchild);
        PreOrder(b->rchild);
    }
}

// 中序遍历的递归算法
void InOrder(BTNode *b) {
    if (b != NULL) {
        InOrder(b->lchild);
        printf("%c ", b->data);    //访问根结点
        InOrder(b->rchild);
    }
}

// 后序遍历的递归算法
void PostOrder(BTNode *b) {
    if (b != NULL) {
        PostOrder(b->lchild);
        PostOrder(b->rchild);
        printf("%c ", b->data);    //访问根结点
    }
}

/** 计算一棵给定二叉树的所有结点个数 */
int Nodes(BTNode *b) {
    int num1, num2;
    if (b == NULL)
        return 0;
    else
        return Nodes(b->lchild) + Nodes(b->rchild) + 1
}

/** 输出一棵给定二叉树的所有叶子结点 */
void DispLeaf(BTNode *b) {
    if (b != NULL) {
        if (b->lchild == NULL && b->rchild == NULL)
            printf("%c ", b->data);     //访问叶子结点
        DispLeaf(b->lchild);            //输出左子树中的叶子结点
        DispLeaf(b->rchild);            //输出右子树中的叶子结点
    }
}

/** 求二叉树b中值为x的结点的层次 */
int Level(BTNode *b, ElemType x, int h)
//找到*p结点后h为其层次，否则为0
{
    if (b == NULL) return 0;        //空树时返回0
    else if (b->data == x) return h;    //找到结点时
    else {
        l = Level(b->lchild, x, h + 1);    //在左子树中查找
        if (l == 0)          //左子树中未找到时在右子树中查找
            return Level(b->rchild, x, h + 1);
        else return l;
    }
}

/** 求二叉树b中第k层的结点个数 */
// 采用基于先序遍历
void Lnodenum(BTNode *b, int h, int k, int &n) {
    if (b == NULL) //空树直接返回
        return;
    else { //处理非空树
        if (h == k) n++; //当前访问的结点在第k层时，n增1
        else if (h < k) //若当前结点层次小于k，递归处理左、右子树
        {
            Lnodenum(b->lchild, h + 1, k, n);
            Lnodenum(b->rchild, h + 1, k, n);
        }
    }
}

// 引用型形参n用于记录二叉树b中第k层的结点个数
int n = 0;        //全局变量
void Lnodenum1(BTNode *b, int h, int k) {
    if (b == NULL)    //空树直接返回
        return;
    else            //处理非空树
    {
        if (h == k) n++;    //当前访问的结点在第k层时，n增1
        else if (h < k)    //若当前结点层次小于k，递归处理左、右子树
        {
            Lnodenum1(b->lchild, h + 1, k);
            Lnodenum1(b->rchild, h + 1, k);
        }
    }
}

/** 判断两棵二叉树是否相似 */
bool Like(BTNode *b1, BTNode *b2) {
//b1和b2两棵二叉树相似时返回true，否则返回false
    bool like1, like2;
    if (b1 == NULL && b2 == NULL)
        return true;
    else if (b1 == NULL || b2 == NULL)
        return false;
    else {
        like1 = Like(b1->lchild, b2->lchild);
        like2 = Like(b1->rchild, b2->rchild);
        return (like1 && like2); //返回like1和like2的与运算结果
    }
}
