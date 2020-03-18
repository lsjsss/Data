//
// Created by lsjss on 2020/3/16.
//
//线性表-顺序存储-顺序表

#include <stdio.h>
#include <malloc.h>
using namespace std;
//#define Class316 main

#define MaxSize 50
typedef int ElemType;//给某一个变量类型起别名
typedef struct {
    ElemType data[MaxSize];//数据域
    int legnth;//线性表长度
}SqList;//200字节

int Class316(){
    SqList sqlist;
    int i=1;
    char ch='a';
    ElemType ch1='C';
}

//初始化一个线性表
//分配空间
void InitList(SqList *&L){//整数 *&num,使用引用类型的参数
    //(带分配类型)malloc(10 * sizeof(int,double,char,SqList));
    L = (SqList *) malloc(sizeof(SqList)); //malloc分配存储空间,使用include头文件
    L -> legnth = 0;
}


//销毁一个线性表(回收空间)
void DestroyList(SqList *&L){
    free(L);
}

//判断一个线性表是否为空（长度为0）
bool ListEmpty(SqList *L){
    return L->legnth==0;
}

//求线性表的长度
int ListLegnth(SqList *L){
    return L->legnth;
}

//输出线性表1
void DispList(SqList *L){
    if(ListEmpty(L)) {
        return;
    }
    for (int i = 0; i < L->legnth ; ++i) {
        printf("%d %d", L->data[i]);
    }
    printf("\n");
}

//求线性表中指定位置　ｉ　的元素值，用参数e待带回
bool GetElem(SqList *L, int i, int &e){
    if( i<1 || i > L->legnth){
        return false;
    }else{
        e = L->data[i];
        return true;
    }
}

//定位线性表中指定元素 e 的第一个位置信息，i值
int Location(SqList *L, int e){
    int i=0;
//    while( i<L->length && L->data[i]!=e){
//
//    }

}




