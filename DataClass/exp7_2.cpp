// Created by lsjss on 2020/6/1.

/**
 * ����P247��ʵ����2��ʵ�ֶ������ĸ��ֱ������ݹ顱�㷨��������ĿҪ������Ҫ�������Ĵ�������н����
 *
 * ʵ����2:ʵ�ֶ������ĸ��ֱ����㷨
 * Ŀ��:���������ĸ��ֱ��������Լ������㷨��ơ�
 * ����:��дһ������exp7-2.cpp,ʵ�ֶ������������������������ͺ�������ĵݹ�ͷǵݹ��㷨,
 * �Լ���α������㷨,����ͼ7.33��ʾ�Ķ�����b�����������
 */
#include <iostream>
#include "SqStack_BTNode.cpp"
#include "SqQueue_BTNode.cpp"

using namespace std;
#define exp7_2 main

void PreOrder(BTNode *b);   // ��������� �ݹ��㷨
void InOrder(BTNode *b);    // ��������� �ݹ��㷨
void PostOrder(BTNode *b);  // ��������� �ݹ��㷨
void PreOrder1(BTNode *b); // ������� �ǵݹ��㷨
void InOrder1(BTNode *b);  // ������� �ǵݹ��㷨
void PostOrder1(BTNode *b);    // ������� �ǵݹ��㷨
void LevelOrder(BTNode *b); // ��α���

int exp7_2() {
    BTNode *b;
    char str[64];

    // ����������A(B(D,E(H(J,K(L,M(,N))))),C(F,G(,I)))
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

    printf("��α�����");
    LevelOrder(b);

    return 0;
}


/** ������ 3 �ֱ����� �ݹ��㷨 */
// ��������ĵݹ��㷨
void PreOrder(BTNode *b) {
    if (b != NULL) {
        printf("%c ", b->data); // ���ʸ����
        PreOrder(b->lchild);    // �������������
        PreOrder(b->rchild);    // �������������
    }
}

// ��������ĵݹ��㷨
void InOrder(BTNode *b) {
    if (b != NULL) {
        InOrder(b->lchild); // �������������
        printf("%c ", b->data); // ���ʸ����
        InOrder(b->rchild); // �������������
    }
}

// ��������ĵݹ��㷨
void PostOrder(BTNode *b) {
    if (b != NULL) {
        PostOrder(b->lchild);   // �������������
        PostOrder(b->rchild);   // �������������
        printf("%c ", b->data); // ���ʸ����
    }
}

/** ������ 3 �ֱ����� �ǵݹ��㷨 */
// ��������ǵݹ��㷨1
void PreOrder1(BTNode *b) {
    BTNode *p;
    SqStack *st;    // ����ջָ�� st
    InitStack(st);  // ��ʼ��ջ st
    if (b != NULL) {
        Push(st, b);    // ������ջ
        while (!StackEmpty(st)) {   // ջ��Ϊ��ʱѭ��
            Pop(st, p); // ��ջ��� p ��������
            printf("%c ", p->data);
            if (p->rchild != NULL)  // ���Һ���ʱ�����ջ
                Push(st, p->rchild);
            if (p->lchild != NULL)  // ������ʱ�����ջ
                Push(st, p->lchild);
        }
        printf("\n");
    }
    DestroyStack(st);   // ����ջ
}

// ��������ǵݹ��㷨
void InOrder1(BTNode *b) {
    BTNode *p;
    SqStack *st;    // ����һ��˳��ջָ�� st
    InitStack(st);  // ��ʼ��ջ st
    p = b;
    while (!StackEmpty(st) || p != NULL) {
        while (p != NULL) { // ɨ���� p ���������½�㲢��ջ
            Push(st, p);    // ��� p ��ջ
            p = p->lchild;  // �ƶ�������
        }
        // ���¿���ջ�����
        if (!StackEmpty(st)) {  // ��ջ����
            Pop(st, p); // ��ջ��� p�����ʽ�� p
            printf("%c ", p->data);
            p = p->rchild;  // ת������������
        }
    }
    printf("\n");
    DestroyStack(st);   // ����ջ
}

// ��������ǵݹ��㷨
void PostOrder1(BTNode *b) {    // ����ǵݹ�����㷨
    BTNode *p, *r;
    bool flag;
    SqStack *st;    // ����һ��˳��ջָ�� st
    InitStack(st);  // ��ʼ��ջ st
    p = b;
    do {
        while (p != NULL) { // ɨ���� p ���������½�㲢��ջ
            Push(st, p);    // ��� p ��ջ
            p = p->lchild;  // �ƶ�������
        }
        r = NULL;   // r ָ��ոշ��ʵĽ�㣬��ʼʱΪ��
        flag = true;    // flag Ϊ���ʾ���ڴ���ջ�����
        while (!StackEmpty(st) && flag) {
            GetTop(st, p);  // ȡ����ǰ��ջ����� p
            if (p->rchild == r) {   // ����� p ���Һ���Ϊ�ջ���Ϊ�շ��ʽ��
                printf("%c ", p->data); // ���ʽ�� p
                Pop(st, p);
                r = p;  // r ָ��շ��ʹ��Ľ��
            } else {
                p = p->rchild;  // ת������������
                flag = false;   // ��ʾ��ǰ���Ǵ���ջ�����
            }
        }
    } while (!StackEmpty(st));  // ջ����ѭ��
    printf("\n");
    DestroyStack(st);   // ����ջ
}

// ��α���
void LevelOrder(BTNode *b) {
    BTNode *p;
    SqQueue *qu;    // ���廷�ζ���ָ��
    InitQueue(qu);  // ��ʼ������
    enQueue(qu, b);  // �����ָ��������
    while (!QueueEmpty(qu)) { // �Ӳ�Ϊ��ѭ��
        deQueue(qu, p);   // ���ӽ�� p
        printf("%c ", p->data);  // ���ʽ�� p
        if (p->lchild != NULL)    // ������ʱ�������
            enQueue(qu, p->lchild);
        if (p->rchild != NULL)    // ���Һ���ʱ�������
            enQueue(qu, p->rchild);
    }
}

