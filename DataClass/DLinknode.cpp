// Created by lsjss on 2020/3/25.
#include <iostream>
using namespace std;
//双链表
typedef int ElemType;
typedef struct DNode {
    ElemType data;//数据域
    struct DNode *prior;//指向前驱结点
    struct DNode *next;//指向后继结点
} DLinkNode;//声明双链表结点类型

//头插法建立双链表
void CreateListF(DLinkNode *&L, ElemType a[], int n) {
    DLinkNode *s;
    L = (DLinkNode *)malloc(sizeof(DLinkNode));//创建头结点
    L->prior = L->next = NULL;
    for(int i = 0; i < n; i++)
    {
        s = (DLinkNode *)malloc(sizeof(DLinkNode));//创建新结点
        s->data = a[i];
        s->next = L->next;//将结点 s 插入到原开始结点之前,头结点之后
        if(L->next != NULL){
            L->next->prior = s;
        }
        L->next = s;
        s->prior = L;
    }
}

//尾插法建立双链表
void CreateListR(DLinkNode *&L, ElemType a[], int n) {
    DLinkNode *s, *r;
    L = (DLinkNode *)malloc(sizeof(DLinkNode));// 创建头结点
    L->prior = L->next = NULL;
    r = L;//r 始终指向尾结点,开始时指向头结点

    for(int i = 0; i < n; i++) {
        s = (DLinkNode *)malloc(sizeof(DLinkNode));//创建新结点
        s->data = a[i];
        r->next = s;
        s->prior = r;//将新结点 s 插入到结点 r 之后
        r = s;
    }
    r->next = NULL;// 尾结点 next 域指向头结点
}

//初始化双链表
void InitList(DLinkNode *&L) {//指针的引用
    L = (DLinkNode *) malloc(sizeof(DLinkNode));//创建头节点
    L->prior = L->next = NULL;
}

//销毁双链表
void DestroyList(DLinkNode *&L) {
    DLinkNode *pre = L, *p = pre->next;
    while (p != NULL) {
        free(pre);
        pre = p;// pre, p 同步后移一个结点
        p = pre->next;
    }
    free(pre);
}

//判断双链表是否为空
bool ListEmpty(DLinkNode *L) {
    return (L->next == NULL);
}

//求双链表的长度
int ListLength(DLinkNode *L) {
    DLinkNode *p = L;
    int i = 0;
    while (p->next != NULL) {
        i++;
        p = p->next;
    }
    return  i;
}

//输出双链表
void DispList(DLinkNode *L) {
    DLinkNode *p = L->next;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

//求双链表中第 i 个元素值
bool GetElem(DLinkNode *L, int i, ElemType &e) {
    int j = 0;    i--;
    DLinkNode *p = L->next;//p 指向第 1 个结点
    if (i <= 0) {
        return false;
    }
    while (j < i && p != NULL) {
        j++;
        p = p->next;
    }
    if (p == NULL) {
        return false;
    } else {
        e = p->data;
        return true;
    }
}

//查找第一个值域为 e 的元素序号
int LocateElem(DLinkNode *L, ElemType e) {
    int n = 1;
    DLinkNode *p = L->next;
    while (p != NULL && p->data != e) {
        n++;
        p = p->next;
    }
    if (p == NULL) {
        return 0;
    } else {
        return n;
    }
}

//插入第 i 个元素
bool ListInsert(DLinkNode *&L, int i, ElemType e) {
    int j = 0;
    DLinkNode *p = L, *s;
    if (i <= 0) {
        return false;
    }
    while (j < i-1 && p != NULL) {
        j++;
        p = p->next;
    }
    if (p == NULL) {
        return false;
    } else {
        s = (DLinkNode *) malloc(sizeof(DLinkNode));
        s->data = e;
        s->next = p->next;
        if (p->next != NULL) {
            p->next->prior = s;
        }
        s->prior = p;
        p->next = s;
        return true;
    }
}

//删除第 i 个元素 e
static bool ListDelete(DLinkNode *&L, int i, ElemType &e)
{
    int j = 1;
    DLinkNode *p = L, *q;

    if(i <= 0 || L->next == L) {//i 错误或者为空表返回假
        return false;
    }

    if(i == 1) {//删除第 1 个结点
        q = L->next;
        e = q->data;
        L->next = q->next;
        q->next->prior = L;
        free(q);
        return true;
    } else {//i 不为 1 时
        p = L->next;
        while(j <= i - 2 && p != NULL) {//查找到第 i-1 个结点 p
            j++;
            p = p->next;
        }
        // 未找到第 i-1 个结点
        if(p == NULL) {
            return false;
        } else {// 找到第 i-1 个结点 p
            q = p->next;//q 指向要删除的结点
            if(q == NULL) {//不存在第 i 个结点
                return 0;
            }
            e = q->data;
            p->next = q->next;
            if(p->next != NULL){//从单链表中删除 q 结点
                p->next->prior = p;
            }
            free(q);//释放 q 结点
        }
    }
}












///////////DLinknode

//typedef struct DNode{
//    ElemType data;
//    struct DNode * prior;
//    struct DNode* next;
//} DLinkNode;
//
////void Initalize(DLinkNode *&L, ElemType a[], int n) { //采用头插法建立双链表
////    L = new DLinkNode;
////    L->prior = 0;
////    L->next = 0;
////}
//
//void Push_Back(DLinkNode *&L, ElemType a[], int x) { //采用头插法建立双链表
//    DLinkNode * p = L, * A = new DLinkNode;
//    A->data = x;
//    while (p->next != 0) {
//        p = p->next;
//    }
//    p->next = A;
//    A->prior = p;
//    A->next = 0;
//}
//
//void Push_Head(DLinkNode*& L, int x) { //尾部插入
//    DLinkNode* A = new DLinkNode;
//    A->data = x;
//    A->next = L->next;
//    L->next->prior = A;
//    L->next = A;
//    A->prior = L;
//}
//
//int Length(DLinkNode* L) { //计算单链表的长度
//    DLinkNode* p;
//    p = L->next;
//    int len = 0;
//    while (p) {
//        len++;
//        p = p->next;
//    }
//    return len;
//}
//
//DLinkNode* Find(DLinkNode*& L, int i) { //找到第i个元素的地址
//    if (i<0 || i>Length(L)) return 0;
//    DLinkNode* p;
//    p = L;
//    int j = 0;
//    while (j < i) {
//        p = p->next;
//        j++;
//    }
//    return p;
//}
//
//void Insert(DLinkNode*& L, int i, int x) { //在第i个位置插入
//    if (i<0 || i>Length(L) + 1) return;
//    if (i == Length(L) + 1)
//        Push_Back(L, x);
//    else {
//        DLinkNode* p = Find(L, i - 1);
//        Push_Head(p, x);
//    }
//}
//
//void Pop_Back(DLinkNode*& L) { //尾部删除
//    DLinkNode* p;
//    p = L;
//    while (p->next != 0) {
//        p = p->next;
//    }
//    p->prior->next = 0;
//    delete p;
//}
//
//void Pop_Head(DLinkNode*& L) { //头部删除
//    DLinkNode* p;
//    p = L;
//    p->next->prior = L;
//    L = L->next;
//    delete p;
//}
//
//void Delete(DLinkNode*&L,int i) { //删除第i个元素
//    if (i<0 || i>Length(L)) return;
//    if (i == 0)
//        Pop_Head(L);
//    if (i == Length(L))
//        Pop_Back(L);
//    else {
//        DLinkNode* p = Find(L, i);
//        p->prior->next = p->next;
//        p->next->prior = p->prior;
//        delete p;
//    }
//}
//
//void Print(DLinkNode* L) { //打印链表
//    DLinkNode* p;
//    p = L->next;
//    while (p) {
//        cout << p->data;
//        p = p->next;
//        if (p)
//            cout << ' ';
//    }
//    cout << endl;
//}


//////////////////////////////////////2t

//typedef struct DNode
//{
//    ElemType data;//数据域
//    struct DNode *prior;//指向前驱结点
//    struct DNode *next;//指向后继结点
//} DLinkNode;// 声明循环双链表结点类型
//
//static void CreateListF(DLinkNode *&L, ElemType a[], int n) {//chafa cai'yong'tou
//    DLinkNode *s;
//    L = (DLinkNode *)malloc(sizeof(DLinkNode));// 创建头结点
//    L->prior = L->next = NULL;
//    for(int i = 0; i < n; i++)
//    {
//        // 创建新结点
//        s = (DLinkNode *)malloc(sizeof(DLinkNode));
//        s->data = a[i];
//
//        // 将结点s插入到原开始结点之前,头结点之后
//        s->next = L->next;
//        if(L->next != NULL)
//            L->next->prior = s;
//        L->next = s;
//        s->prior = L;
//    }
//    s = L->next;
//    // 查找尾结点,由s指向它
//    while(s->next != NULL)
//        s = s->next;
//    // 尾结点next域指向头结点
//    s->next = L;
//    // 头结点的prior域指向尾结点
//    L->prior = s;
//}
//
///*---------------------尾插法建立循环双链表------------------------*/
//static void CreateListR(DLinkNode *&L, ElemType a[], int n)
//{
//    DLinkNode *s, *r;
//
//    // 创建头结点
//    L = (DLinkNode *)malloc(sizeof(DLinkNode));//分配内存空间
//
//    // r始终指向尾结点,开始时指向头结点
//    r = L;
//
//    for(int i = 0; i < n; i++)
//    {
//        // 创建新结点
//        s = (DLinkNode *)malloc(sizeof(DLinkNode));
//        s->data = a[i];
//        // 将新结点s插入到结点r之后
//        r->next = s;
//        s->prior = r;
//        r = s;
//    }
//    // 尾结点next域指向头结点
//    r->next = NULL;
//    // 头结点的prior域指向尾结点
////    L->prior = r;
////    L->next = NULL;
//}
//
//
///*---------------------初始化线性表------------------------*/
//static void InitList(DLinkNode *&L)//指针的引用
//{
//    L = (DLinkNode *)malloc(sizeof(DLinkNode));// 创建头结点
//    L->prior = L->next = L;
//}
//
///*---------------------销毁线性表------------------------*/
//static void DestroyList(DLinkNode *&L)// 指针的引用
//{
//    DLinkNode *pre = L, *p = pre->next;
//    while(p != L)
//    {
//        free(pre);
//        // pre,p同步后移一个结点
//        pre = p;
//        p = pre->next;
//    }
//    // 此时p=L,pre指向尾结点,释放它
//    free(pre);
//}
//
//
///*---------------------判断线性表是否为空表------------------------*/
//static bool list_empty(DLinkNode *L)
//{
//    return (L->next == L);
//}
//
//
///*---------------------求线性表的长度------------------------*/
//static int list_length(DLinkNode *L)
//{
//    int i = 0;
//    DLinkNode *p = L;
//
//    while(p->next != L)
//    {
//        i++;
//        p = p->next;
//    }
//
//    // 循环结束,p指向尾结点,其序号i为结点个数
//    return i;
//}
//
//
///*---------------------输出线性表------------------------*/
//static void display_list(DLinkNode *L)
//{
//    DLinkNode *p = L->next;
//
//    while(p != L)
//    {
//        printf("%c ", p->data);
//        p = p->next;
//    }
//
//    printf("\n");
//}
///*---------------------求线性表中第i个元素值------------------------*/
//static bool get_elem(DLinkNode *L, int i, ElemType &e)
//{
//    int j = 1;
//    DLinkNode *p = L->next; // p指向第1个结点
//
//    // i错误或者L为空表返回假
//    if(i <= 0 || L->next == L)
//        return false;
//    // i = 1作为特殊情况处理
//    if(i == 1)
//    {
//        // 提取数据域
//        e = L->next->data;
//        return true;
//    }
//        // i不为1时
//    else
//    {
//        // 查找第i个结点p
//        while(j <= i - 1 && p != L)
//        {
//            j++;
//            p = p->next;
//        }
//        // 没有找到第i个结点,返回假
//        if(p == L)
//            return false;
//        else // 找到第i个结点,返回true
//        {
//            // 提取数据域
//            e = p->data;
//            return true;
//        }
//    }
//}
//
//
///*---------------------查找第一个值域为e的元素序号------------------------*/
//static int locate_elem(DLinkNode *L, ElemType e)
//{
//    int i = 1;
//    DLinkNode *p = L->next;
//
//    while(p != NULL && p->data != e)
//    {
//        i++;
//        p = p->next;
//    }
//    // 不存在值为e的结点,返回0
//    if(p == NULL)
//        return 0;
//        //存在值为e的结点,返回其逻辑序号i
//    else
//        return i;
//}
//
//
///*---------------------插入第i个元素------------------------*/
//static bool list_insert(DLinkNode *&L, int i, ElemType e)
//{
//    int j = 1;
//    DLinkNode *p = L, *s;
//
//    // i错误返回假
//    if(i <= 0)
//        return false;
//    // 原双链表为空表时
//    if(p->next == L)
//    {
//        // 创建新结点s
//        s = (DLinkNode *)malloc(sizeof(DLinkNode));
//        s->data = e;
//        p->next = s;
//        s->next = p;
//        p->prior = s;
//        s->prior = p;
//        return true;
//    }
//    else if(i == 1) // L不为空,i = 1作为特殊情况处理
//    {
//        // 创建新结点s
//        s = (DLinkNode *)malloc(sizeof(DLinkNode));
//        s->data = e;
//        // 将结点s插入到结点p之后
//        s->next = p->next;
//        p->next = s;
//        s->next->prior = s;
//        s->prior = p;
//        return true;
//    }
//    else // i不为1时
//    {
//        p = L->next;
//        // 查找第i-1个结点p
//        while(j <= i - 2 && p != L)
//        {
//            j++;
//            p = p->next;
//        }
//        // 未找到第i - 1个结点
//        if(p == L)
//            return false;
//        else
//        {
//            // 找到第i - 1个结点p
//            // 创建新结点s
//            s = (DLinkNode *)malloc(sizeof(DLinkNode));
//            s->data = e;
//            // 将结点s插入到结点p之后
//            s->next = p->next;
//            if(p->next != NULL)
//                p->next->prior = s;
//            s->prior = p;
//            p->next = s;
//            return true;
//        }
//    }
//}
//
///*---------------------删除第i个元素------------------------*/
//static bool list_delete(DLinkNode *&L, int i, ElemType &e)
//{
//    int j = 1;
//    DLinkNode *p = L, *q;
//
//    // i错误或者为空表返回假
//    if(i <= 0 || L->next == L)
//        return false;
//    // i = 1作为特殊情况处理
//    if(i == 1)
//    {
//        // 删除第1个结点
//        q = L->next;
//        e = q->data;
//        L->next = q->next;
//        q->next->prior = L;
//        free(q);
//        return true;
//    }
//    else // i不为1时
//    {
//        p = L->next;
//        // 查找到第i - 1个结点p
//        while(j <= i - 2 && p != NULL)
//        {
//            j++;
//            p = p->next;
//        }
//        // 未找到第i - 1个结点
//        if(p == NULL)
//            return false;
//        else // 找到第i - 1个结点p
//        {
//            // q指向要删除的结点
//            q = p->next;
//            // 不存在第i个结点
//            if(q == NULL)
//                return 0;
//            e = q->data;
//            // 从单链表中删除q结点
//            p->next = q->next;
//            if(p->next != NULL)
//                p->next->prior = p;
//            //释放q结点
//            free(q);
//        }
//    }
//}
