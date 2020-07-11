//// Created by lsjss on 2020/3/19.
//
//#include <stdio.h>
//#include "Sqlist.cpp"
////#define sqlisth1 main
//
//int sqlisth1() {
//    SqList *L;
//    int a[10]={60,6,70,13,96,2,73,61,6,25};
//    int n = 10;
//
//    printf("初始化顺序表：");
//    InitList(L);//初始化顺序表
//    DispList(L);//输出顺序表
//
//    printf("顺序表是否为空：");
//    printf("%d\n", ListEmpty(L) );
//
//    printf("创建顺序表：");
//    CreateList(L, a, n);//创建顺序表
//    DispList(L);//输出顺序表
//
//    printf("顺序表是否为空：");
//    printf("%d\n", ListEmpty(L) );
//
//    printf("顺序表长度：");
//    printf("%d\n", ListLength(L) );
//
//    printf("顺序表中第 4 个元素：");
//    int numlocation1 = 4;//顺序表第四个元素
//    int num1 = 0;//顺序表第四个元素的值
//    GetElem(L, numlocation1, num1);//查找元素值
//    printf("%d\n", num1 );//返回元素值
//
//    printf("顺序表中元素 6 首次出现的位置：");
//    int num2 = 6;//顺序表元素值等于 6
//    printf("%d\n", LocateElem(L, num2));//查找位置
//
//    printf("顺序表中第 8 个位置插入元素 52 之后:");
//    int numlocation3 = 8;
//    int num3 = 52;
//    ListInsert(L, numlocation3, num3);//顺序表中第 8 个位置插入元素 52
//    DispList(L);//输出顺序表
//
//    printf("顺序表中删除第 5 个位置元素之后：");
//    int numlocation4 = 5;
//    int delnum4 = 0;
//    ListDelete(L, numlocation4, delnum4);
//    DispList(L);//输出顺序表
//
//    printf("被删除的元素：");
//    printf("%d\n", delnum4);
//
//    printf("顺序表中删除所有值为 6 的元素：");
//    int num4 = 6;
//    DelNodel(L, num4);
//    DispList(L);//输出顺序表
//
//    printf("执行销毁操作后的顺序表：");
//    DestroyList(L);
//    DispList(L);//输出线性表
//
////    printf("======================\n");
////    fun(L, 2);
////    DispList(L);
//
//    return 0;
//}
