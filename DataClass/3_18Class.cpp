//
// Created by lsjss on 2020/3/18.
//
#include <stdio.h>
#include "sqlist.cpp"
#define sqllist02 main
int sqlist02() {
    SqList *L;
    int a[10]={2,55,43,88,91,3,4,5,6,73};
    int n = 0;

    printf("创建顺序表");
    CreateList(L,a,n);
    DispList(L);

    printf("在第2个位置插入元素88：");
    ListInsert(L, 2, 88);
    DispList(L);
    printf("顺序表长度%d：\n",ListLength(L))
}
