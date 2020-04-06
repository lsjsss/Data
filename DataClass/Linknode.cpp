// Created by lsjss on 2020/3/18.
#include <stdio.h>
#include <malloc.h>
//线性表
#define MaxSize 50
typedef int ElemType;

typedef struct LNode {
    ElemType data;  //存放元素值
    struct LNode* next; //推向后继节点
} LinkNode; //单链表节点类型

//头插法
void CreateListF(LinkNode *&L, ElemType a[], int n) {
    LinkNode *s;
    L = (LinkNode * )malloc(sizeof(LinkNode));
    L->next = NULL; //创建头结点，其 next 域置为 NULL
    for (int i = 0; i < n; i++) {   //循环建立数据节点 s
        s = (LinkNode * )malloc(sizeof(LinkNode));
        s->data = a[i]; //创建数据节点 s
        s->next = L->next;  //将结点 s 插入到原首结点之前、头结点之后
        L->next = s;
    }
}

//尾插法
void CreateListR(LinkNode *&L, ElemType a[], int n) {
    LinkNode *s, *r;
    L = (LinkNode *)malloc(sizeof(LinkNode));   //创建头结点
    r = L;  //r 始终指向尾结点，初始时指向头结点
    for (int i = 0; i < n; i++) {   //循环建立数据节点
        s = (LinkNode *)malloc(sizeof(LinkNode));
        s->data = a[i]; //创建数据节点 s
        r->next = s;    //将结点 s 插入到结点 r 之后
        r = s;
    }
    r->next = NULL; //尾结点其 next 域置为 NULL
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
    LinkNode *p = L;    //p 指向头结点，n置为0(即头节点序号为0)
    while (p->next != NULL) {
        n++;
        p = p->next;
    }
    return n;   //循环结束，p指向尾节点，其序号 n 为节点个数
}

//5 输出线性表
void Display(LinkNode* L) {
    LinkNode* p = L->next;  //p 指向首结点
    while (p != NULL) { //p 不为 NULL, 输出 p 节点的 data 域
        printf("%d ", p->data);
        p = p->next;    //p 移向下一个节点
    }
    printf("\n");
}

//6 查找某个数据元素值
bool GetData(LinkNode *L, int i, int &e) {
    int j = 0;
    LinkNode *p = L;    //p 指向首结点, j 置为 0
    if (i <= 0) {   //i 错误返回假
        return false;
    }
    while (j < i && p != NULL) {    //找第 i 个结点 p
        j++;
        p = p->next;
    }
    if (p == NULL) {    //不存在第 i 个数据节点，返回 false
        return false;
    }
    else {  //存在第 i 个数据节点，返回 true
        e = p->data;
        return true;
    }
}

//7 按元素值查找
int LocateData(LinkNode *L, ElemType e) {
    int i = 1;
    LinkNode* p = L->next;  //p 指向首结点 ，i 置为 1（首结点的序号为 1）
    while (p != NULL && p->data != e) { //查找 data 值为 e 的节点，其序号为 i
        p = p->next;
        i++;
    }
    if (p == NULL) {    //不存在值为 e 的节点，返回其逻辑序号 0
        return 0;
    }
    else {  //存在值为 e 的节点，返回其逻辑序号 i
        return i;
    }
}

//8 插入数据元素
bool ListInsert(LinkNode *&L, int i, ElemType e) {
    int j = 0;
    LinkNode *p = L, *s;    //p 指向头结点, j 置为 0（即头结点序号为 0）
    if (i <= 0) {   //i 错误返回 false
        return false;
    }
    while (j < i - 1 && p != NULL) {    //未找第 i-1 个结点 p
        j++;
        p = p->next;
    }
    if (p == NULL) {    //未找到 i-1 个结点,返回 false
        return false;
    } else {    //找到第 i-1 个结点 p,插入新结点并返回 true
        s = (LinkNode * )malloc(sizeof(LinkNode));
        s->data = e;    //创建新结点 s,其值 data 值为 e
        s->next = p->next;  //将结点 s 插入到结点 p 之后
        p->next = s;
        return true;
    }
}

//9 删除数据元素
bool ListDelete(LinkNode*& L, int i, ElemType &e) {
    int j = 0;
    LinkNode* p = L, * q;   //p 指向头结点, j置为 0 （即头结点序号为 0）
    if (i <= 0) {   //i 错误返回 false
        return false;
    }
    while (j < i - 1 && p != NULL) {    //查找第 i-1 个结点
        j++;
        p = p->next;
    }
    if (p == NULL) {    //未找到第 i-1 个结点,返回 false
        return false;
    }
    else {  //找到第 i-1 个结点 p
        q = p->next;    //q 指向第 i 个结点
        if (q == NULL) {    //若不存在第 i 个结点, 返回 false
            return false;
        }
        e = q->data;    //从单链表中删除 q 节点
        p->next = q->next;  //释放 q 结点
        return true;    //返回 true 表示成功删除第 i 个节点
    }
}

void DelNodel(LinkNode *&L, ElemType a) {
    LinkNode *p,*q;
    p = L;
    while (p->next!=NULL) {
        if (p->next->data==a) {
            q=p->next;
            p->next=p->next->next;  //删除指定的字符
            free(q);
        } else {
            p=p->next;  //指针后移
        }
    }
}


