//
// Created by lsjss on 2020/3/18.
//

#include "pch.h"
#include <stdio.h>
#include <malloc.h>
#define MaxSize 50
typedef char ElemType;
typedef struct
{
    ElemType data[MaxSize];
    int length;
}SqList;
void InitList(SqList * &L)//初始化线性表
{   //从总体的来说，这句是给指针分配空间。
    //赋值号左边L是一个SqList *指针，指向名为SqList的结构体；
    //赋值号右边，malloc(sizeof(SqList))是分配一块大小为sizeof(SqList)的内存，
    //并返回首地址并赋值给左边的L指针，
    //(SqList *)表示把这个地址强制转化为SqlList *的指针。
    L = (SqList *)malloc(sizeof(SqList));
    L->length = 0;//分配存放线性表的空间//置空线性表长度为0
}
void  DestroyList(SqList *L) //销毁线性表
{
    free(L);
}
bool ListEmpty(SqList *L)//判断线性表是否为空表
{
    return (L->length == 0);
}
int ListLength(SqList *L)//求线性表的长度
{
    return(L->length);
}
void DispList(SqList *L)//输出线性表
{
    int i;
    if (ListEmpty(L)) return;
    for (i = 0; i < L->length; i++)
        printf("%c", L->data[i]);
    printf("\n");
}
bool GetElem(SqList *L, int i, ElemType e)//求数据表中某个数据元素值
{
    if (i<1 || i>L->length)
        return false;      //参数错误时返回false
    e = L->data[i - 1];    //取元素值
    return true;           //成功找到元素时返回true
}
int LocateElem(SqList *L, ElemType e)
{
    int i = 0;
    while (i < L->length && L->data[i] != e)
        i++;            //查找元素e
    if (i >= L->length) //未找到时返回0
        return 0;
    else
        return i + 1;    //找到后返回其逻辑序号
}
bool ListInsert(SqList *&L, int i, ElemType e)//插入数据元素
{
    int j;
    if (i<1 || i>L->length + 1)
        return false;//参数错误时返回false
    i--;//将顺序表逻辑序号转换为物理序号
    for (j = L->length; j > i; j--) //将data[i]及后面元素后移一个位置
        L->data[j] = L->data[j - 1];
    L->data[i] = e;//插入元素e
    L->length++;//顺序表长度＋1
    return true;
}
bool ListDelete(SqList *&L, int i, ElemType e)//删除数据元素
{
    int j;
    if (i<1 || i>L->length)
        return false;//参数错误时返回false
    i--;             //将顺序表逻辑序号转换为物理序号
    e = L->data[i];
    for (j = i; j < L->length - 1; j++)  //将data[i]之后的元素前移一个位置
        L->data[j] = L->data[j + 1];
    L->length--;//顺序表长度减1
    return true;//成功删除返回true;
}
extern void InitList(SqList *&L);
extern void DestroyList(SqList *L);
extern bool ListEmpty(SqList *L);
extern int ListLength(SqList *L);
extern void DispList(SqList *L);
extern bool GetElem(SqList *L, int i, ElemType &e);
extern int  LocateElem(SqList *L, ElemType e);
extern bool ListInsert(SqList *&L, int i, ElemType e);
extern bool ListDelete(SqList *&L, int i, ElemType &e);
int main()
{
    SqList *L;
    printf("顺序表的基本运算如下：\n");
    printf("(1)初始化顺序表L\n");
    InitList(L);
    printf("(2)依次采用尾插法插入a,b,c,d,e元素\n");
    ListInsert(L, 1, 'a');
    ListInsert(L, 2, 'b');
    ListInsert(L, 3, 'c');
    ListInsert(L, 4, 'd');
    ListInsert(L, 5, 'e');
    printf("(3)输出顺序表L：");
    DispList(L);
    printf("(4)顺序表L的长度=%d\n", ListLength(L));
    printf("(5)顺序表L为%s\n", (ListEmpty(L) ? "空" : "非空"));
    printf("(6)顺序表L的第3个元素=%c\n", GetElem(L, 3, 'e'));
    printf("(7)元素a的位置=%d\n",LocateElem(L,'a'));
    ListInsert(L, 4, 'f');
    printf("(8)在第4个元素位置上插入f元素\n");
    ListInsert(L, 4, 'f');
    printf("(9)输出顺序表L:");
    DispList(L);
    printf("(10)删除L的第三个元素\n");
    ListDelete(L, 3, 'e');
    printf("(11)输出顺序表L:");
    DispList(L);
    printf("(12)释放顺序表L\n");
    DestroyList(L);
}