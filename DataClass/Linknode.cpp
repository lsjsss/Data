// Created by lsjss on 2020/3/18.
#include <stdio.h>
#include <malloc.h>

#define MaxSize 50
typedef int ElemType;

typedef struct LNode {
    ElemType data;   //存放元素值
    struct LNode* next;  //推向后继节点
} LinkNode;  //单链表节点类型

//头插法
void CreateListF(LinkNode *&L, ElemType a[], int n) {
    LinkNode *s;
    L = (LinkNode * )malloc(sizeof(LinkNode));
    L->next = NULL; //创建头结点，其 next 域置为 NULL
    for (int i = 0; i < n; i++) {   //循环建立数据节点 s
        s = (LinkNode * )malloc(sizeof(LinkNode));
        s->data = a[i]; //赋值
        s->next = L->next;  //将结点 s 插入到原首结点之前，头结点之后
        L->next = s;
    }
}

//尾插法
void CreateListR(LinkNode *&L, ElemType a[], int n) {
    LinkNode *s, *r;
    L = (LinkNode *)malloc(sizeof(LinkNode));    //创建头结点
    r = L;  //r 始终指向尾结点，初始时指向头结点 （头结点序号为 0）
    for (int i = 0; i < n; i++) {   //循环建立数据节点 s
        s = (LinkNode *)malloc(sizeof(LinkNode));
        s->data = a[i]; //赋值
        r->next = s;    //将结点 s 插入到结点 r 之后
        r = s;
    }
    r->next = NULL;	    //尾结点其 next 域置为 NULL
}


//1 初始化线性表
void InitList(LinkNode*& L) {
    L = (LinkNode*)malloc(sizeof(LinkNode));
    L->next = NULL; //创建头结点，其 next 域置为 NULL
}

//2 销毁线性表
void DestroyList(LinkNode*& L) {
    LinkNode *pre = L, * p = L->next;   //pre 指向结点 p 的前驱节点
    while (p != NULL) { //扫描单链表 L
        free(pre);  //释放 pre 结点
        pre = p;    //pre、p 同步后移一个结点
        p = pre->next;
    }
    free(pre);  //循环结束时 p 为 NULL，pre指向尾结点释放它
}

//3 判断线性表是否为空表
bool ListEmpty(LinkNode* L) {
    return L->next == NULL;
}

//4 求线性表的长度
int ListLength(LinkNode* L) {
    int n = 0;
    LinkNode *p = L;    //p 指向头结点，n置为0
    while (p->next != NULL) {   //不为空，依次遍历
        n++;
        p = p->next;
    }
    return n;   //返回长度
}

//5 输出线性表
void Display(LinkNode* L) {
    LinkNode* p = L->next;  //p 指向首结点 （首结点序号为 1）
    while (p != NULL) { //不为空，依次遍历
        printf("%d ", p->data);
        p = p->next;    //p 移向下一个节点
    }
    printf("\n");
}

//6 查找某个数据元素值
bool GetData(LinkNode *L, int i, int &e) {
    int j = 0;
    LinkNode *p = L;  //p 指向首结点 （首结点序号为 1）
    if (i <= 0) {   //i 错误返回假
        return false;
    }
    while (j < i && p != NULL) {    //找第 i 个结点 p
        j++;
        p = p->next;
    }
    if (p == NULL) {    //不存在
        return false;
    }
    else {  //存在返回 true
        e = p->data;
        return true;
    }
}

//7 按元素值查找
int LocateData(LinkNode *L, ElemType e) {
    int i = 1;
    LinkNode* p = L->next;  //p 指向头结点 ，i 置为 1（首结点序号为 1）
    while (p != NULL && p->data != e) {  //查找 data 值，其序号为 i
        p = p->next;
        i++;
    }
    if (p == NULL) {    //不存在
        return 0;
    }
    else {  //存在并返回序号 i
        return i;
    }
}

//8 插入数据元素
bool ListInsert(LinkNode *&L, int i, ElemType e) {
    int j = 0;
    LinkNode *p = L, *s;   //p 指向头结点 （头结点序号为 0）
    if (i <= 0) {   //i 错误返回假
        return false;
    }
    while (j < i - 1 && p != NULL) {    //查找第 i-1 个结点 p
        j++;
        p = p->next;
    }
    if (p == NULL) {    //未找到
        return false;
    } else {  //找到第 i-1 个结点 p ,插入新结点并返回 true
        s = (LinkNode * )malloc(sizeof(LinkNode));
        s->data = e; //创建新结点 s,其值为 data
        s->next = p->next;  //头插法
        p->next = s;
        return true;
    }
}

//9 删除数据元素
bool ListDelete(LinkNode*& L, int i, ElemType &e) {
    LinkNode* p = L, * q;   //p 指向头结点 （头结点序号为 0）
    if (i <= 0) {   //i 错误返回假
        return false;
    }
    int j = 0;  //j 置为 0
    while (j < i - 1 && p != NULL) {    //查找第 i 个结点 p
        j++;
        p = p->next;
    }
    if (p == NULL) {    //未找到
        return false;
    }
    else {  //找到第 i-1 个结点 p
        q = p->next;    //q 指向第 i 个结点
        if (q == NULL) {    //若不存在第 i 个结点
            return false;
        }
        e = q->data;
        p->next = q->next;  //删除 q 结点，第 i-1 个结点 指向第 i+1 个结点
        free(q);    //释放 q 结点
        return true;
    }
}


void DelNodel(LinkNode *&L, ElemType a) {
    LinkNode *p,*q;
    p = L;
    while (p->next!=NULL) {
        if (p->next->data==a) {
            q=p->next;
            p->next=p->next->next;//删除指定的字符
            free(q);
        } else {
            p=p->next;//不删除，只是指针后移
        }
    }
}