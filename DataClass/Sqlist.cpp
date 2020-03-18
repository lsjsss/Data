// Created by lsjss on 2020/3/18.

#include <stdio.h>
#include <malloc.h>

#define MaxSize 50
typedef int ElemType;

//顺序表结构
typedef struct{
    ElemType data[MaxSize]; //存放顺序表元素
    int length; //存放顺序表的长度
} SqList;

//建立顺序表
void CreateList(SqList *&L, ElemType a[], int n) {
    L = (SqList *) malloc(sizeof(SqList));
    for ( int i = 0; i < n; i++ )
        L->data[i] = a[i];
    L->length = n;
}


//1 初始化线性表
void InitList(SqList * &L){
    //从总体的来说，这句是给指针分配空间。
    //赋值号左边L是一个SqList *指针，指向名为SqList的结构体；
    //赋值号右边，malloc(sizeof(SqList))是分配一块大小为sizeof(SqList)的内存，
    //并返回首地址并赋值给左边的L指针，
    //(SqList *)表示把这个地址强制转化为SqlList *的指针。
    L = (SqList *)malloc(sizeof(SqList));//分配存放线性表的空间
    L->length = 0;//置空线性表长度为0
}

//2 销毁线性表
void  DestroyList(SqList *&L) {
    free(L);
}

//3 判断线性表是否为空表
bool ListEmpty(SqList *L) {
    return (L -> length == 0);
}

//4 求线性表的长度
int ListLength(SqList *L) {
    return(L->length);
}

//5 输出线性表
void DispList(SqList *L) {
//    int i;
//    if (ListEmpty(L)) return;
    for (int i = 0; i < L->length; i++)//扫描顺序表输出各元素值
        printf("%d ", L->data[i]);
    printf("\n");
}

//6 求数据表中某个数据元素值
bool GetElem(SqList *L, int i, ElemType &e) {
    if ( i < 1 || i > L->length )
        return false;      //参数 i 错误时返回false
    e = L->data[i - 1];    //取元素值
    return true;           //成功找到元素时返回true
}

//7 顺序表中定位元素 e 首次出现的位置，按元素值顺序查找
int LocateElem(SqList *L, ElemType e) {
    int i = 0;
    while (i < L-> length && L->data[i] != e)
        i++;            //查找元素e
    if (i >= L->length) //未找到时返回0
        return 0;
    else
        return i + 1;    //找到后返回其逻辑序号
}

//8 在顺序表中第 i 个位置上插入元素 e 。插入数据元素
bool ListInsert(SqList *&L, int i, ElemType e) {
    int j;
    if (i<1 || i > L->length + 1)
        return false;//参数 i 错误时返回false
    i--;//将顺序表逻辑序号转换为物理序号
    for (j = L->length; j > i; j--) //将data[i]及后面元素后移一个位置
        L->data[j] = L->data[j - 1];
    L->data[i] = e;//插入元素e
    L->length++;//顺序表长度＋1
    return true;
}

//9 删除顺序表中第 i 个位置的元素，用参数 e 返回。删除数据元素
bool ListDelete(SqList *&L, int i, ElemType e) {
    int j;
    if (i<1 || i > L->length)
        return false;//参数错误时返回false
    i--;             //将顺序表逻辑序号转换为物理序号
    e = L->data[i];
    for (j = i; j < L->length - 1; j++)  //将data[i]之后的元素前移一个位置
        L->data[j] = L->data[j + 1];
    L->length--;//顺序表长度减1
    return true;//成功删除返回true;
}

//删除顺序表 L 中所有值为 x 的元素
//解决方案：重建方法，找见一个不等于 x 的元素即向前移动，覆盖 k 位置元素交换
void DelNodel(SqList *&L, ElemType x) {
    //k 记录不等于待删除元素 x 的元素数量
    int k = 0;
    for (int i = 0; i < L->length; ++i) {
        if (L->data[i] != x) {
            L->data[k] = L->data[i];
            k++;
        }
    }
    L->length = k;
}

//删除顺序表 L 中所有值 x 的元素
//解决方案：前移法
void DelNode2(SqList *&L, ElemType x) {
    //k 记录等于代删元素 x 的元素数量
    int k = 0, i = 0;
    while (i < L->length) {
        if (L->data[i]==x){
            k++;
        } else{
            L->data[i-k] = L->data[i];
        }
        i++;
    }
}