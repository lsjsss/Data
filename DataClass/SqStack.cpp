// Created by lsjss on 2020/4/1.

#include <iostream>
#include <malloc.h>
using namespace std;

#define MaxSize 50
typedef int ElemType;

typedef struct{
    ElemType data[MaxSize];
    int top;    //栈顶指针
} SqStack;

//初始化栈
void InitStack(SqStack *&s){
    s=(SqStack *)malloc(sizeof(SqStack));
    s->top=-1;
}

//销毁栈
void DestroyStack(SqStack *&s){
    free(s);
}

//判断栈是否为空
bool StackEmpty(SqStack *s){
    return(s->top==-1);
}

//进栈
bool Push(SqStack *&s, ElemType e){
    if (s->top==MaxSize-1){//栈满的情况，即栈上溢出
        return false;
    }
    s->top++;   //栈顶指针增1
    s->data[s->top]=e;	   	//元素e放在栈顶指针处
    return true;
}

//出栈
bool Pop(SqStack *&s, ElemType &e)
{  if (s->top==-1)	//栈为空的情况，即栈下溢出
        return false;
    e=s->data[s->top];	//取栈顶指针元素的元素
    s->top--;		//栈顶指针减1
    return true;
}

//取栈顶元素
bool GetTop(SqStack *s, ElemType &e){
    if (s->top==-1)	   //栈为空的情况，即栈下溢出
        return false;
    e=s->data[s->top];   //取栈顶指针元素的元素
    return true;
}
