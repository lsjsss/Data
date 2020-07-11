//// Created by lsjss on 2020/6/1.
///** 基于 BTNode 的 SqStack */
//#include "BTNode.cpp"
//
//// 基于二叉树的顺序栈
//#define MaxSize 50
//typedef struct {
//    BTNode *data[MaxSize];
//    int top;
//} SqStack;
//
//// 初始化顺序栈
//void InitStack(SqStack *&s) {
//    s = (SqStack *) malloc(sizeof(SqStack));
//    s->top = -1;
//}
//
//// 销毁顺序栈
//void DestroyStack(SqStack *&s) {
//    free(s);
//}
//
//// 判断顺序栈是否为空
//bool StackEmpty(SqStack *s) {
//    return (s->top == -1);
//}
//
////进栈
//bool Push(SqStack *&s, BTNode *e) {
//    if (s->top == MaxSize - 1) {    //栈满的情况，即栈上溢出
//        return false;
//    }
//    s->top++;   //栈顶指针增1
//    s->data[s->top] = e;  //元素e放在栈顶指针处
//    return true;
//}
//
//// 出栈
//bool Pop(SqStack *&s, BTNode *&e) {
//    if (s->top == -1) {  //栈为空的情况，即栈下溢出
//        return false;
//    }
//    e = s->data[s->top];    //取栈顶指针元素的元素
//    s->top--;   //栈顶指针减1
//    return true;
//}
//
//// 获取顺序栈栈顶元素
//bool GetTop(SqStack *s, BTNode *&e) {
//    if (s->top == -1)
//        return false;
//    e = s->data[s->top];
//    return true;
//}
