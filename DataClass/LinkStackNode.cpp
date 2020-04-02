// Created by lsjss on 2020/4/2.
#include <stdio.h>
#include <malloc.h>
using namespace std;

#define MaxSize 50
typedef int ElemType;

typedef struct linknode {
    ElemType data;		//数据域
    struct linknode *next;	//指针域
} LinkStackNode;

//1 初始化链栈
void InitLinkStack(LinkStackNode *&s) {
    s=(LinkStackNode *)malloc(sizeof(LinkStackNode));
    s->next = NULL;
}

//2 创建链栈
void CreateLinkStack(LinkStackNode *&L, ElemType a[], int n) {
    LinkStackNode *s, *r;
    L = (LinkStackNode *)malloc(sizeof(LinkStackNode));   //创建头结点
    r = L;  //r 始终指向尾结点，初始时指向头结点
    for (int i = 0; i < n; i++) {   //循环建立数据节点
        s = (LinkStackNode *)malloc(sizeof(LinkStackNode));
        s->data = a[i]; //创建数据节点 s
        r->next = s;    //将结点 s 插入到结点 r 之后
        r = s;
    }
    r->next = NULL; //尾结点其 next 域置为 NULL
}

//3 销毁链栈
void DestroyLinkStack(LinkStackNode *&s) {
    LinkStackNode *p = s, *q = s->next;
    while (q != NULL) {
        free(p);
        p = q;
        q = p->next;
    }
    free(p);	//此时p指向尾结点，释放其空间
}

//4 判断链栈是否为空
bool LinkStackEmpty(LinkStackNode *s) {
    return(s->next == NULL);
}

//5 进栈
void Push(LinkStackNode *&s, ElemType e) {
    LinkStackNode *p;
    p=(LinkStackNode *)malloc(sizeof(LinkStackNode));
    p->data = e;    //新建元素e对应的结点p
    p->next = s->next;  //插入p结点作为开始结点
    s->next = p;
}

//6 出栈
bool Pop(LinkStackNode *&s, ElemType &e) {
    LinkStackNode *p;
    if (s->next == NULL){ //栈空的情况
        return false;
    }
    p = s->next;  //p指向开始结点
    e = p->data;
    s->next = p->next;    //删除p结点
    free(p);    //释放p结点
    return true;
}

//7 取链栈栈顶元素 (Peer)
bool GetTop(LinkStackNode *s, ElemType &e) {
    if (s->next == NULL) {//栈空的情况
        return false;
    }
    e = s->next->data;
    return true;
}

//8 获取链栈的长度
int LinkStackLength(LinkStackNode* L) {
    int n = 0;
    LinkStackNode *p = L;    //p 指向头结点，n置为0(即头节点序号为0)
    while (p->next != NULL) {
        n++;
        p = p->next;
    }
    return n;   //循环结束，p指向尾节点，其序号 n 为节点个数
}

//9 输出链栈
void ShowLinkStack(LinkStackNode* L) {
    LinkStackNode* p = L->next;  //p 指向首结点
    while (p != NULL) { //p 不为 NULL, 输出 p 节点的 data 域
        printf("%d ", p->data);
        p = p->next;    //p 移向下一个节点
    }
    printf("\n");
}
