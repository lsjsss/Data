// Created by lsjss on 2020/6/25.

#include <stdio.h>
#include <malloc.h>
#define sybg2_6_24 main


// 顺序表
#define MaxSize 50
typedef int ElemType;

// 顺序表结构
typedef struct {
    ElemType data[MaxSize]; //存放顺序表元素
    int length; //存放顺序表的长度
} SqList;   //顺序表的节点类型

// 建立顺序表
void CreateList(SqList *&L, ElemType a[], int n) {
    L = (SqList *) malloc(sizeof(SqList));
    for (int i = 0; i < n; i++)
        L->data[i] = a[i];
    L->length = n;
}

//1 初始化线性表
void InitList(SqList *&L) {
    L = (SqList *) malloc(sizeof(SqList));   //分配存放线性表的空间
    L->length = 0;  //置空线性表长度为 0
}

//2 销毁线性表
void DestroyList(SqList *&L) {
    free(L);    //释放 L 所指的顺序表空间
}

//3 判断线性表是否为空表
bool ListEmpty(SqList *L) {
    return (L->length == 0);
}

//4 求线性表的长度
int ListLength(SqList *L) {
    return (L->length);
}

//5 输出线性表
void DispList(SqList *L) {
    for (int i = 0; i < L->length; i++) //扫描顺序表输出各元素值
        printf("%d ", L->data[i]);
    printf("\n");
}


// 查找
// 顺序查找
int SeqSearch(SqList *&R, int n, int k) {
    int i = 0;
    while (i < n && R->data[i] != k)    //从表头往后找
        i++;
    if (i >= n)            //未找到返回0
        return 0;
    else
        return i + 1;        //找到返回逻辑序号i+1
}

// 折半查找
int BinSearch(SqList *&R, int n, int k) {
    int low = 0, high = n - 1, mid;
    while (low <= high) {        //当前区间存在元素时循环
        mid = (low + high) / 2;
        if (R->data[mid] == k)    //查找成功返回其逻辑序号mid+1
            return mid + 1;
        if (k < R->data[mid])    //继续在R[low..mid-1]中查找
            high = mid - 1;
        else
            low = mid + 1;        //继续在R[mid+1..high]中查找
    }
    return 0;
}


int sybg2_6_24() {
    SqList *L;
    int a[10] = {11, 15, 22, 25, 33, 44, 55, 66, 77, 88};
    int n = 10;
    int findnumber;

    printf("创建顺序表：");
    CreateList(L, a, n);//创建顺序表
    DispList(L);//输出顺序表

    // 顺序查找
    findnumber = 55;
    printf("顺序查找关键字 %d 所在的位置： %d\n", findnumber, SeqSearch(L, n, findnumber));

    // 折半查找 1
    findnumber = 66;
    printf("%顺序查找关键字 %d 所在的位置： %d\n", findnumber, BinSearch(L, n, findnumber));

    // 折半查找 2
    findnumber = 52;
    printf("顺序查找关键字 %d 所在的位置： %d\n", findnumber, BinSearch(L, n, findnumber));

    return 0;
}
