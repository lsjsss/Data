// Created by lsjss on 2020/3/18.

#include <stdio.h>
#include "Sqlist.cpp"
#define sqlist02 main

int sqlist02() {
    SqList *L;
    int a[10]={2,55,43,88,91,3,4,5,6,73};
    int n = 10;

    printf("����˳���");
    CreateList(L, a, n);
    DispList(L);

    printf("�ڵ�2��λ�ò���Ԫ��88��");
    ListInsert(L, 2, 88);
    DispList(L);
    printf("˳�����%d��\n",ListLength(L));
    DispList(L);
}
