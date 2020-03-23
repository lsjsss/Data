// Created by lsjss on 2020/3/19.
//完成链表的基础运算，并完成测试工作，测试结果参考图形。
#include <stdio.h>
#include "Linknode.cpp"
//#define linknodeh1 main

int linknodeh1() {
    LinkNode *L;
    int a[9]={63,7,35,19,94,7,25,64,95};
    int n = 9;

    printf("初始化单链表：");
    InitList(L);//初始化单链表
    Display(L);//输出单链表

    printf("单链表是否为空：");
    printf("%d\n", ListEmpty(L) );

    printf("创建单链表：");
    CreateListF(L, a, n);//使用头插法创建单链表
    Display(L);//输出单链表

    printf("单链表是否为空：");
    printf("%d\n", ListEmpty(L) );

    printf("单链表长度：");
    printf("%d\n", ListLength(L) );

    printf("单链表中第 5 个元素：");
    int numlocation1 = 5;//顺序表第五个元素
    int num1 = 0;//单链表第五个元素的值
    GetData(L, numlocation1, num1);//查找元素值
    printf("%d\n", num1 );//返回元素值

    printf("单链表中元素 7 首次出现的位置：");
    int num2 = 7;//单链表元素值等于7
    printf("%d\n", LocateData(L, num2));//查找位置

    printf("单链表中第 3 个位置插入元素 91 之后:");
    int numlocation3 = 3;
    int num3 = 91;
    ListInsert(L, numlocation3, num3);//单链表中第 3 个位置插入元素 91
    Display(L);//输出单链表

    printf("单链表中删除第 4 个位置元素之后：");
    int numlocation4 = 4;
    int delnum4 = 0;
    ListDelete(L, numlocation4, delnum4);
    Display(L);//输出单链表

    printf("被删除的元素：");
    printf("%d\n", delnum4);

    printf("单链表中删除所有值为 7 的元素：");
    int num4 = 7;
    DelNodel(L, num4);
    Display(L);//输出单链表

    return 0;
}
