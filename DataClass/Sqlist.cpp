// Created by lsjss on 2020/3/18.

#include <stdio.h>
#include <malloc.h>
//顺序表
#define MaxSize 50
typedef int ElemType;

//顺序表结构
typedef struct{
    ElemType data[MaxSize]; //存放顺序表元素
    int length; //存放顺序表的长度
} SqList;   //顺序表的节点类型

//建立顺序表
void CreateList(SqList *&L, ElemType a[], int n) {
    L = (SqList *) malloc(sizeof(SqList));
    for ( int i = 0; i < n; i++ )
        L->data[i] = a[i];
    L->length = n;
}

//1 初始化线性表
void InitList(SqList * &L){
    L = (SqList *)malloc(sizeof(SqList));   //分配存放线性表的空间
    L->length = 0;  //置空线性表长度为 0
}

//2 销毁线性表
void  DestroyList(SqList *&L) {
    free(L);    //释放 L 所指的顺序表空间
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
    for (int i = 0; i < L->length; i++) //扫描顺序表输出各元素值
        printf("%d ", L->data[i]);
    printf("\n");
}

//6 求数据表中某个数据元素值
bool GetElem(SqList *L, int i, ElemType &e) {
    if ( i < 1 || i > L->length )
        return false;   //参数 i 错误时返回false
    e = L->data[i - 1]; //取元素值
    return true;    //成功找到元素时返回true
}

//7 按元素值顺序查找
int LocateElem(SqList *L, ElemType e) {
    int i = 0;
    while (i < L-> length && L->data[i] != e)
        i++;    //查找元素 e
    if (i >= L->length) //未找到时返回 0
        return 0;
    else
        return i + 1;   //找到后返回其逻辑序号
}

//8 插入数据元素
bool ListInsert(SqList *&L, int i, ElemType e) {
    int j;
    if (i<1 || i > L->length + 1)
        return false;   //参数 i 错误时返回false
    i--;    //将顺序表逻辑序号转换为物理序号
    for (j = L->length; j > i; j--) //将 data[i] 及后面元素后移一个位置
        L->data[j] = L->data[j - 1];
    L->data[i] = e; //插入元素 e
    L->length++;    //顺序表长度 ＋1
    return true;    //成功返回 true
}

//9 删除顺序表中第 i 个位置的元素，用参数 e 返回。删除数据元素
bool ListDelete(SqList *&L, int i, ElemType &e) {
    int j;
    if (i<1 || i > L->length)
        return false;   //参数 i 错误时返回 false
    i--;    //将顺序表逻辑序号转换为物理序号
    e = L->data[i];
    for (j = i; j < L->length - 1; j++) //将 data[i] 之后的元素前移一个位置
        L->data[j] = L->data[j + 1];
    L->length--;    //顺序表长度减 1
    return true;    //成功删除返回 true
}

//删除顺序表 L 中所有值为 x 的元素
void DelNodel(SqList *&L, ElemType x) {
    int k = 0;
    for (int i = 0; i < L->length; ++i) {
        if (L->data[i] != x) {
            L->data[k] = L->data[i];
            k++;
        }
    }
    L->length = k;
}

//在列表中最小的数字前插入指定的数值 x
void fun ( SqList *& L , ElemType x ) { //传入 顺序表 L, 指定数据 x
    int i ,j=0;
    for (i=1; i < L->length ; i++) {    //将顺序表由第二个元素开始，到最后一个元素结束 遍历
        if (L->data[i] <= L->data[j]) { //如果后面的元素小于等于第一个元素，就将被比较元素替换为这个比较小的元素，否则就转到下一个数字继续比较
            j = i;  // j 与 i 相同
        }
    }

    for (i = L->length; i > j; i--) {   //从后往前遍历，从顺序表+1的位置开始，直到 j 结束
        L->data[i] = L->data[i - 1];    //将前一个元素的值赋给后一个元素
    }
    L->data[j] = x; //将指定的 x 值赋给 j 所在的位置
    L->length++;    //顺序表增加一个元素
}
