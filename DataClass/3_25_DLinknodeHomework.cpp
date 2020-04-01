// Created by lsjss on 2020/3/25.
#include "DLinknode.cpp"
//#define dlinknodeh1 main

int dlinknodeh1() {
    DLinkNode *L;
    int a[11]={63, 58, 7, 35, 19, 94, 7, 55, 25, 64, 95};
    int n = 11;

    printf("初始化双链表： ");
    InitList(L);//初始化双链表
    DispList(L);//输出双链表

    printf("双链表是否为空： ");
    printf("%d\n", ListEmpty(L) );

    printf("使用头插法创建双链表： ");
    CreateListF(L, a, n);//使用头插法创建双链表
    DispList(L);

    printf("使用尾插法创建双链表： ");
    CreateListR(L, a, n);
    DispList(L);//输出双链表

    printf("判断双链表是否为空: %d\n", ListEmpty(L));

    printf("双链表长度： ");
    printf("%d\n", ListLength(L));

    printf("双链表中第 9 个元素： ");
    int numlocation1 = 9;//双链表第 9 个元素
    int num1 = 0;//双链表第五个元素的值,默认为0
    GetElem(L, numlocation1, num1);//查找元素值
    printf("%d\n", num1 );//返回元素值

    printf("双链表中元素 7 首次出现的位置： ");
    int num2 = 7;//双链表元素值等于7
    printf("%d\n", LocateElem(L, num2));//查找位置

    printf("双链表中第 4 个位置插入元素 11 之后: ");
    int numlocation3 = 4;
    int num3 = 11;
    ListInsert(L, numlocation3, num3);//双链表中第 4 个位置插入元素 11
    DispList(L);//输出双链表

    printf("双链表中删除第 6 个位置元素之后： ");
    int numlocation4 = 6;//要删除元素的位置
    int delnum4 = 0;//要删除元素的值,默认为0
    ListDelete(L, numlocation4, delnum4);
    DispList(L);//输出双链表

    printf("被删除的元素： ");
    printf("%d\n", delnum4);

    printf("销毁双链表");
    DestroyList(L);

    return 0;
}
