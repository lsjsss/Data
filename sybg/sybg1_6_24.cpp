// Created by lsjss on 2020/6/25.

#include <iostream>

using namespace std;
//#define sybg1_6_24 main

// �������Ķ���͸������㲿��
#define MaxSize 100
typedef char ElemType;
typedef struct node {
    ElemType data;
    struct node *lchild;
    struct node *rchild;
} BTNode;

//1 ����������
void CreateBTree(BTNode *&b, char *str) {  //��str ? ������b
    BTNode *St[MaxSize], *p;
    int top = -1, k, j = 0;
    char ch;
    b = NULL;        //�����Ķ�������ʼʱΪ��
    ch = str[j];
    while (ch != '\0') { //strδɨ����ʱѭ��
        switch (ch) {
            case '(':
                top++;
                St[top] = p;
                k = 1;
                break;  //���������ӽ�㣬��ջ
            case ')':
                top--;
                break;
            case ',':
                k = 2;
                break;  //����Ϊ�Һ��ӽ��
            default:    //�������ֵ
                p = (BTNode *) malloc(sizeof(BTNode));
                p->data = ch;
                p->lchild = p->rchild = NULL;
                if (b == NULL)  //pΪ�������ĸ����
                    b = p;
                else {  //�ѽ��������������
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
        ch = str[j];    //����ɨ��str
    }
}

//2 ���ٶ�����
void DestroyBTree(BTNode *&b) {
    if (b == NULL) return;
    else {
        DestroyBTree(b->lchild);
        DestroyBTree(b->rchild);
        free(b);    //ʣ��һ�����b��ֱ���ͷ�
    }
}

//3 ���ҽ��
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

//5 ��������ĸ߶�
int BTHeight(BTNode *b) {
    int lchilddep, rchilddep;
    if (b == NULL) return (0);  //�����ĸ߶�Ϊ0
    else {
        lchilddep = BTHeight(b->lchild);
        // ���������ĸ߶�Ϊ lchilddep
        rchilddep = BTHeight(b->rchild);
        // ���������ĸ߶�Ϊ rchilddep
        return (lchilddep > rchilddep) ? (lchilddep + 1) : (rchilddep + 1);
    }
}

//6 ���������
void DispBTree(BTNode *b) {
    if (b != NULL) {
        printf("%c", b->data);
        if (b->lchild != NULL || b->rchild != NULL) {
            printf("(");
            DispBTree(b->lchild);   //�ݹ鴦��������
            if (b->rchild != NULL) printf(",");
            DispBTree(b->rchild);   //�ݹ鴦��������
            printf(")");
        }
    }
}


// ���ж���͸����㷨����
#define MaxSize2 50
typedef struct {
    ElemType data[MaxSize2];
    int front, rear;    //���׺Ͷ�βָ��
} SqQueue;

////1 ��ʼ������
//void InitQueue(SqQueue *&q) {
//    q = (SqQueue *) malloc(sizeof(SqQueue));
//    q->front = q->rear = 0;
//}


// ջ���岿��
#define Maxsize3 50
typedef struct {
    BTNode *data[Maxsize3];
    int top;    //˳��ջջ��ָ��
} SqStack;

void InitStack(SqStack *&s) {
    s = (SqStack *) malloc(sizeof(SqStack));
    s->top = -1;
}

// ����˳��ջ
void DestroyStack(SqStack *&s) {
    free(s);
}

// �ж�˳��ջ�Ƿ�Ϊ��
bool StackEmpty(SqStack *s) {
    return (s->top == -1);
}

// ��ջ
bool Push(SqStack *&s, BTNode *e) {
    if (s->top == Maxsize3 - 1) {    //ջ�����������ջ�����
        return false;
    }
    s->top++;   //ջ��ָ����1
    s->data[s->top] = e;  //Ԫ��e����ջ��ָ�봦
    return true;
}

// ��ջ
bool Pop(SqStack *&s, BTNode *&e) {
    if (s->top == -1){  //ջΪ�յ��������ջ�����
        return false;
    }
    e = s->data[s->top];    //ȡջ��ָ��Ԫ�ص�Ԫ��
    s->top--;   //ջ��ָ���1
    return true;
}

// ��ȡ˳��ջջ��Ԫ��
bool GetTop(SqStack *s, BTNode *&e) {
    if (s->top == -1)
        return false;
    e = s->data[s->top];
    return true;
}

// �����㷨����
// �ݹ��������
void PreOrder(BTNode *b) {
    if (b != NULL) {
        cout << b->data;
        PreOrder(b->lchild);
        PreOrder(b->rchild);
    }
}

//�ǵݹ��������
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

//�ݹ��������
void InOrder(BTNode *b) {
    if (b != NULL) {
        InOrder(b->lchild);
        cout << b->data;
        InOrder(b->rchild);
    }
}

//�ǵݹ��������
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

//�ݹ�������
void PostOrder(BTNode *b) {
    if (b != NULL) {
        PostOrder(b->lchild);
        PostOrder(b->rchild);
        cout << b->data;
    }
}

//�ǵݹ�������
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

    // ����������A(B(D,E),C(F,G))
    printf("����һ�����ű�ʾ����������");
    scanf("%s", &str);

    CreateBTree(b, str);
    printf("��ʼ����������");
    DispBTree(b);

    printf("\n�ݹ����������");
    PreOrder(b);

    printf("\n�ݹ����������");
    InOrder(b);

    printf("\n�ݹ���������");
    PostOrder(b);

    printf("\n�ǵݹ����������");
    PreOrder1(b);

    printf("�ǵݹ����������");
    InOrder1(b);

    printf("�ǵݹ���������");
    PostOrder1(b);

    return 0;
}
