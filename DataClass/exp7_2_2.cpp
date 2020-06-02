// Created by lsjss on 2020/6/1.

/**
 * 书上P247，实验题2：实现二叉树的各种遍历“递归”算法。（按题目要求作答，要有完整的代码和运行结果）
 *
 * 实验题2:实现二叉树的各种遍历算法
 * 目的:领会二叉树的各种遍历过程以及遍历算法设计。
 * 内容:编写一个程序exp7-2. cpp,实现二叉树的先序遍历、中序遍历和后序遍历的递归和非递归算法,
 * 以及层次遍历的算法,并对图7.33所示的二叉树b给出求解结果。
 * 图7.33(https://raw.githubusercontent.com/lsjsss/For-Pcigo/master/20200602011234.png)
 */

#include <iostream>
using namespace std;


/*********************二叉树的定义和各种运算部分**********************/
#define Maxsize 100
typedef char ElemType;
typedef struct node
{
    ElemType data;
    struct node *lchild;
    struct node *rchild;
}BTNode;

void CreateBTree(BTNode * &b, char *str) //创造二叉树
{
    BTNode *St[Maxsize], *p;
    int top=-1,k,j=0;
    char ch;
    b=NULL;
    ch=str[j];
    while(ch!='\0')
    {
        switch (ch)
        {
            case '(':top++;St[top]=p;k=1;break;
            case ')':top--;              break;
            case ',':k=2;                break;
            default:
                p=(BTNode*)malloc(sizeof(BTNode));
                p->data=ch;
                p->lchild=p->rchild=NULL;
                if(b==NULL)
                    b=p;
                else
                {
                    switch(k)
                    {
                        case 1:St[top]->lchild=p;break;
                        case 2:St[top]->rchild=p;break;
                    }
                }
        }
        j++;
        ch=str[j];
    }
}

void DestroyBtree(BTNode *&b)  //销毁二叉树
{
    if(b!=NULL)
    {
        DestroyBtree(b->lchild);
        DestroyBtree(b->rchild);
        free(b);
    }
}

BTNode *FindNode(BTNode *b,ElemType x)
{
    BTNode *p;
    if(b==NULL)
    {
        return NULL;
    }
    else if(b->data==x)
    {
        return b;
    }
    else
    {
        p=FindNode(b->lchild, x);
        if(p!=NULL)
        {
            return p;
        }
        else
        {
            return FindNode(b->rchild, x);
        }
    }
}

BTNode *LchildNode(BTNode *p)  //返回左子树
{
    return p->lchild;
}

BTNode *RchildNode(BTNode *p)  //返回右子树
{
    return p->rchild;
}

int BTHeight(BTNode *b)       //求二叉树的高度
{
    int lchildh,rchildh;
    if(b==NULL) return 0;
    else
    {
        lchildh=BTHeight(b->lchild);
        rchildh=BTHeight(b->rchild);
        return (lchildh>rchildh)? (lchildh+1):(rchildh+1);
    }
}

void DispBTree(BTNode *b)      //输出二叉树
{
    if(b!=NULL) {
        cout<<b->data;
        if(b->lchild!=NULL || b->rchild!=NULL) {
            cout<<"(";
            DispBTree(b->lchild);
            if(b->rchild!= NULL) cout<<",";
            DispBTree(b->rchild);
            cout<<")";
        }
    }
}
/*****************队列定义和各种算法部分********************/
#define MaxSize2 50

typedef struct {
    BTNode *data[MaxSize2];
    int front, rear;
} SqQueue;

void InitQueue(SqQueue *&q)
{
    q=(SqQueue *)malloc(sizeof(SqQueue));
    q->front=q->rear=0;
}

void DestroyQueue(SqQueue *&q)
{
    free(q);
}

bool QueueEmpty(SqQueue *q)
{
    return (q->front==q->rear);
}

bool enQueue(SqQueue *&q,BTNode *e)
{
    if((q->rear+1)%MaxSize2==q->front)
    {
        return false;
    }
    q->rear=(q->rear+1)%MaxSize2;
    q->data[q->rear]=e;
    return true;
}

bool deQueue(SqQueue *&q,BTNode *&e)
{
    if(q->front==q->rear)
    {
        return false;
    }
    q->front=(q->front+1)%MaxSize2;
    e=q->data[q->front];
    return true;
}


/**********************栈定义部分**********************/
/****************************************************/
#define Maxsize3 50
typedef struct
{
    BTNode *data[Maxsize3];
    int top;
}SqStack;

void InitStack(SqStack *&s)
{
    s=(SqStack*)malloc(sizeof(SqStack));
    s->top=-1;
}

void DestroyStack(SqStack *&s)
{
    free(s);
}

bool StackEmpty(SqStack *s)
{
    return (s->top==-1);
}

bool Push(SqStack *&s,BTNode *e)
{
    if(s->top==Maxsize3-1){
        return false;
    }
    s->top++;
    s->data[s->top]=e;
    return true;
}

bool Pop(SqStack *&s,BTNode* &e)
{
    if(s->top==-1)
        return false;
    e=s->data[s->top];
    s->top--;
    return true;
}

bool GetTop(SqStack *s,BTNode* &e)
{
    if(s->top==-1)
        return false;
    e=s->data[s->top];
    return true;
}

/*********************遍历算法部分*********************/
void PreOrder_recursion(BTNode *b)   //递归先序遍历
{
    if(b!=NULL)
    {
        cout<<b->data;
        PreOrder_recursion(b->lchild);
        PreOrder_recursion(b->rchild);
    }
}

void PreOrder_not_recursion(BTNode *b) //非递归先序遍历
{
    BTNode *p;
    SqStack *st;
    InitStack(st);
    if(b!=NULL)
    {
        Push(st,b);
        while(!StackEmpty(st))
        {
            Pop(st,p);
            cout<<p->data;
            if(p->rchild!=NULL)
            {
                Push(st,p->rchild);
            }
            if(p->lchild!=NULL)
            {
                Push(st,p->lchild);
            }
        }
        cout<<endl;
    }
    DestroyStack(st);
}

void InOrder_recursion(BTNode *b)   //递归中序遍历
{
    if(b!=NULL)
    {
        InOrder_recursion(b->lchild);
        cout<<b->data;
        InOrder_recursion(b->rchild);
    }
}

void InOrder_not_recursion(BTNode *b) //非递归中序遍历
{
    BTNode *p;
    SqStack *st;
    InitStack(st);
    p=b;
    while(!StackEmpty(st) || p!=NULL)
    {
        while(p!=NULL)
        {
            Push(st,p);
            p=p->lchild;
        }
        if(!StackEmpty(st))
        {
            Pop(st,p);
            cout<<p->data;
            p=p->rchild;
        }
    }
    cout<<endl;
    DestroyStack(st);
}

void PostOrder_recursion(BTNode *b)   //递归后序遍历
{
    if(b!=NULL)
    {
        PostOrder_recursion(b->lchild);
        PostOrder_recursion(b->rchild);
        cout<<b->data;
    }
}

void PostOrder_not_recursion(BTNode *b) //非递归后序遍历
{
    BTNode *p,*r;
    bool flag;
    SqStack *st;
    InitStack(st);
    p=b;
    do{
        while(p!=NULL)
        {
            Push(st,p);
            p=p->lchild;
        }
        r=NULL;
        flag=true;
        while(!StackEmpty(st)&&flag)
        {
            GetTop(st,p);
            if(p->rchild==r)
            {
                cout<<p->data;
                Pop(st,p);
                r=p;
            }
            else
            {
                p=p->rchild;
                flag=false;
            }
        }
    }while (!StackEmpty(st));
    cout<<endl;
    DestroyStack(st);
}



void LevelOrder(BTNode *b)
{
    BTNode *p;
    SqQueue *qu;
    InitQueue(qu);
    if(b!= nullptr)
    {
        enQueue(qu,b);
        while(!QueueEmpty(qu))
        {
            deQueue(qu,p);
            cout<<p->data;
            if(p->lchild!=NULL)
                enQueue(qu,p->lchild);
            if(p->rchild!=NULL)
                enQueue(qu,p->rchild);
        }
    }

}


int main() {
    BTNode *b;
    char str[] = "A(B(D,E(H(J,K(L,M(,N))))),C(F,G(,I)))";
    CreateBTree(b, str);
    cout << "初始化二叉树为：" << endl;
    DispBTree(b);
    cout << endl;

    cout << "递归先序遍历";
    PreOrder_recursion(b);
    cout << endl;
    cout << "非递归先序遍历";
    PreOrder_not_recursion(b);

    cout << "递归中序遍历";
    InOrder_recursion(b);
    cout << endl;
    cout << "非递归中序遍历";
    InOrder_not_recursion(b);

    cout << "递归先序遍历";
    PostOrder_recursion(b);
    cout << endl;
    cout << "非递归先序遍历";
    PostOrder_not_recursion(b);

    cout << "层次遍历:";
    LevelOrder(b);
    return 0;
}



