//// Created by lsjss on 2020/4/1.
//#include <iostream>
//using namespace std;
////顺序栈
//#define MaxSize 50
//typedef int ElemType;
//
//typedef struct{
//    ElemType data[MaxSize];
//    int top;    //顺序栈栈顶指针
//} SqStack;
//
//////初始化顺序栈
////void InitStack(SqStack *&s) {
////    s=(SqStack *)malloc(sizeof(SqStack));
////    s->top=-1;
////}
////
//////创建顺序栈
////void CreateStack(SqStack *&s, int a[], int n) {
////    s = (SqStack *)malloc(sizeof(SqStack));
////    s->top = -1;
////    for (int i = 0; i < n; ++i) {
////        s->data[i] = a[i];
////    }
////    s->top = n-1;
////}
////
//////销毁顺序栈
////void DestroyStack(SqStack *&s) {
////    free(s);
////}
////
//////判断顺序栈是否为空
////bool StackEmpty(SqStack *s) {
////    return (s->top == -1);
////}
////
//////进栈
////bool Push(SqStack *&s, ElemType e) {
////    if (s->top == MaxSize - 1) {    //栈满的情况，即栈上溢出
////        return false;
////    }
////    s->top++;   //栈顶指针增1
////    s->data[s->top]=e;  //元素e放在栈顶指针处
////    return true;
////}
////
//////出栈
////bool Pop(SqStack *&s, ElemType &e) {
////    if (s->top == -1){  //栈为空的情况，即栈下溢出
////        return false;
////    }
////    e = s->data[s->top];    //取栈顶指针元素的元素
////    s->top--;   //栈顶指针减1
////    return true;
////}
////
//////获取顺序栈栈顶元素
////bool Peer(SqStack *s, ElemType &e) {
////    if (s->top == -1) {
////        return false;
////    }
////    e = s->data[s->top];
////    return true;
////}
////
////bool GetTop(SqStack *s, ElemType &e) {
////    if(s->top==-1)
////        return false;
////    e = s->data[s->top];
////    return true;
////}
////
//////获取顺序栈的长度
////int StackLength(SqStack *s) {
////    return s->top + 1;
////}
////
//////输出顺序栈的内容
////void ShowStack(SqStack *s) {
////    if (s->top == -1) {
////        printf("\n");
////        return;
////    }
////    for (int i = 0; i <= s->top; ++i) {
////        printf("%d ", s->data[i]);
////    }
////    printf("\n");
////}
