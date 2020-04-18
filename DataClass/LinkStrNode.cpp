// Created by lsjss on 2020/4/18.
#include <malloc.h>

// 链串
typedef struct snode {
    char data; //存放字符
    struct snode * next; // 指向下一个结点的指针
} LinkStrNode; // 链串的结点类型

//1 生成串
static void strAssign(LinkStrNode *&s, char cstr[]) {
    int index;
    LinkStrNode *r, *p;

    s = (LinkStrNode *) malloc(sizeof(LinkStrNode)); // 动态分配存储空间
    r = s; // r指向新建链串的尾结点

    for (index = 0; cstr[index] != '\0'; index++) {
        p = (LinkStrNode *) malloc(sizeof(LinkStrNode)); // 创建新的数据结点p
        p->data = cstr[index]; // 新数据结点p的数据域赋值
        r->next = p; // 尾插法建链表
        r = p; // r指向新建的数据结点p
    }
    r->next = NULL; // 尾结点的next域为空
}

//2 销毁串
static void DestroyStr(LinkStrNode *&s) {
    LinkStrNode *pre = s; // pre指向链表头结点
    LinkStrNode *p = s->next; // p指向链表中的第一个数据结点
    while (p != NULL) { // 扫描链串s
        free(pre); // 释放pre结点
        pre = p; // pre,p同步后移一个结点
        p = p->next;
    }
    free(pre); // 循环结束时,p为NULL,pre指向尾结点,释放它
}

//3 串的复制
static void StrCopy(LinkStrNode *&s, LinkStrNode *t) { // 串t复制给串s
    LinkStrNode *p = t->next, *q, *r;
    s = (LinkStrNode *) malloc(sizeof(LinkStrNode));
    r = s; // r始终指向尾结点
    while (p != NULL) { // 将t的所有结点复制到s,扫描链串 t 的所有节点
        q = (LinkStrNode *) malloc(sizeof(LinkStrNode));
        q->data = p->data; //将 p 结点复制到 q 结点
        r->next = q; //将 q 结点链接到链串 s 的末尾
        r = q;
        p = p->next;
    }
    r->next = NULL; // 尾结点的next域置为NULL
}

//4 判断串相等
static bool StrEqual(LinkStrNode *s, LinkStrNode *t) {
    LinkStrNode *p = s->next, *q = t->next; //p, q 分别扫描链串 s 和 t 的数据节点
    while (p != NULL && q != NULL && p->data == q->data) {
        p = p->next;
        q = q->next;
    }
    if (p == NULL && q == NULL) { //s 和 t 的长度相等且对应位置的字符均相同
        return true;
    } else {
        return false;
    }
}

//5 求串长
static int StrLength(LinkStrNode *s) {
    int len = 0; //len 用于累计数据节点的个数
    LinkStrNode *p = s->next; //p 指向链串 s 的首节点
    while (p != NULL) { //扫描所有数据节点
        len++;
        p = p->next;
    }
    return len;
}

//6 串的连接
static LinkStrNode *str_concat(LinkStrNode *s, LinkStrNode *t) {
    LinkStrNode *str, *p = s->next, *q, *r;
    str = (LinkStrNode *) malloc(sizeof(LinkStrNode));
    r = str; // r指向新建链串的尾结点
    while (p != NULL) { // 将s的所有结点复制到str，用 p 扫描 s 的所有数据节点
        q = (LinkStrNode *) malloc(sizeof(LinkStrNode));
        q->data = p->data; //将 p 结点复制到 q 结点中
        r->next = q; //将 q 结点链接到 str 末尾
        r = q;
        p = p->next;
    }
    p = t->next;
    while (p != NULL) { // 将t的所有结点复制到str，用 p 扫描 t 的所有数据结点
        q = (LinkStrNode *) malloc(sizeof(LinkStrNode));
        q->data = p->data; //将 p 结点复制到 q 结点中
        r->next = q; //将 q 结点链接到 str 的末尾
        r = q;
        p = p->next;
    }
    r->next = NULL; // 尾结点的next域置为NULL
    return str;
}

//7 求子串
static LinkStrNode *sub_str(LinkStrNode *s, int pos, int len) {
    int index;
    LinkStrNode *str, *p = s->next, *q, *r;
    str = (LinkStrNode *) malloc(sizeof(LinkStrNode)); // 动态分配内存空间
    str->next = NULL; //置结果串 str 为空串
    r = str; // r指向新建链串的尾结点
    if ((pos <= 0) || (pos > str_length(s)) || (len < 0) || (pos + len - 1 > str_length(s))) { // 参数不正确时返回空串
        return str; //参数不正确时返回空串
    }
    for (index = 0; index < pos - 1; index++) { //让 p 指向链串 s 的第 i 个数据结点
        p = p->next;
    }
    for (index = 1; index <= len; index++) { // 将s的第pos个结点开始的len个结点复制到str
        q = (LinkStrNode *) malloc(sizeof(LinkStrNode));
        q->data = p->data;
        r->next = q;
        r = q;
        p = p->next;
    }
    r->next = NULL;
    return str;
}

//8 子串的插入
static LinkStrNode *insStr(LinkStrNode *s, int pos, LinkStrNode *t) {
    int index;
    LinkStrNode *str, *p = s->next, *p1 = t->next, *q, *r;
    str = (LinkStrNode *) malloc(sizeof(LinkStrNode)); // 动态分配内存空间
    str->next = NULL; //置结果串 str 为空串
    r = str; // r指向新建链串的尾结点
    if (pos <= 0 || pos > str_length(s) + 1) { // 参数不正确时返回空串
        return str;
    }
    for (index = 1; index < pos; index++) { // 将s的前pos个结点复制到str
        q = (LinkStrNode *) malloc(sizeof(LinkStrNode)); // 新建数据结点q
        q->data = p->data; // 对新建数据结点q数据域赋值
        r->next = q; // 尾插法建立链表
        r = q; // r指向新建数据结点q
        p = p->next; // p后移一个结点
    }
    while (p1 != NULL) { // 将t的所有结点复制到str
        q = (LinkStrNode *) malloc(sizeof(LinkStrNode));
        q->data = p1->data;
        q->next = NULL;
        r->next = q;
        r = q;
        p1 = p1->next;
    }
    while (p != NULL) // 将结点p及其后的结点复制到str
    {
        q = (LinkStrNode *) malloc(sizeof(LinkStrNode));
        q->data = p->data;
        r->next = q;
        r = q;
        p = p->next;
    }
    r->next = NULL; // 尾结点的next域为空
    return str;
}

//9 子串的删除
static LinkStrNode *DelStr(LinkStrNode *s, int pos, int len) {
    int index;
    LinkStrNode *str, *p = s->next, *q, *r;
    str = (LinkStrNode *) malloc(sizeof(LinkStrNode));
    str->next = NULL; //置结果串 str 为空串
    r = str; //r 指向新建链串的尾结点
    if ((pos <= 0) || (pos > str_length(s)) || (len < 0) || (pos + len - 1 > str_length(s))) { // 参数不正确时返回空串
        return str;
    }
    for (index = 0; index < pos - 1; index++) { // 将s的前pos - 1个结点复制到str
        q = (LinkStrNode *) malloc(sizeof(LinkStrNode));
        q->data = p->data;
        r->next = q;
        r = q;
        p = p->next;
    }
    for (index = 0; index < len; index++) { // 让p沿next跳len个结点
        p = p->next;
    }
    while (p != NULL) { // 将结点p及其后的结点复制到str
        q = (LinkStrNode *) malloc(sizeof(LinkStrNode));
        q->data = p->data;
        q->next = NULL;
        r->next = q;
        r = q;
        p = p->next;
    }
    r->next = NULL; // 尾结点的next域为空
    return str;
}

//10 子串的替换
static LinkStrNode *RepStr(LinkStrNode *s, int pos, int len, LinkStrNode *t) {
    int index;
    LinkStrNode *str, *p = s->next, *p1 = t->next, *q, *r;
    str = (LinkStrNode *) malloc(sizeof(LinkStrNode));
    str->next = NULL; //设置结果串 str 为空串
    r = str; // r指向新建链串的尾结点
    if ((pos <= 0) || (pos > str_length(s)) || (len < 0) || (pos + len - 1 > str_length(s))) {
        return str; // 参数不正确时返回空串
    }
    for (index = 0; index < pos - 1; index++) { // 将s的前pos - 1个结点复制到str
        q = (LinkStrNode *) malloc(sizeof(LinkStrNode));
        q->data = p->data;
        q->next = NULL;
        r->next = q;
        r = q;
        p = p->next;
    }
    for (index = 0; index < len; index++) { // 让p沿next跳len个结点
        p = p->next;
    }
    while (p1 != NULL) { // 将t的所有结点复制到str
        q = (LinkStrNode *) malloc(sizeof(LinkStrNode));
        q->data = p1->data;
        q->next = NULL;
        r->next = q;
        r = q;
        p1 = p1->next;
    }
    while (p != NULL) { // 将结点p及其后的结点复制到str
        q = (LinkStrNode *) malloc(sizeof(LinkStrNode));
        q->data = p->data;
        q->next = NULL;
        r->next = q;
        r = q;
        p = p->next;
    }
    r->next = NULL; // 将尾结点的next域设置为NULL
    return str;
}

//11 输出串s
static void disp_str(LinkStrNode *s) {
    LinkStrNode *p = s->next; //p 指向链串 s 的首节点
    while (p != NULL) { //扫描 s 的所有数据节点
        printf("%c", p->data); //输出 p 的结点值
        p = p->next;
    }
    printf("\n");
}




