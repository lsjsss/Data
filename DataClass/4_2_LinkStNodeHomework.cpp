// Created by lsjss on 2020/4/2.
//完成链栈的基础预算，并测试程序，请各处基础算法程序和测试程序以及运行结果。
#include <stdio.h>
#include "LinkStackNode.cpp"
#define linkstacknode1 main

int linkstacknode1() {
    LinkStackNode *S;//链栈的初始定义
    int a[9]={45, 66, 21, 34, 82, 19, 5, 79, 57};
    int n = 9;//元素个数

    printf("初始化链栈： ");
    InitLinkStack(S);//初始化链栈
    ShowLinkStack(S);//输出链栈

    printf("链栈是否为空： ");
    printf("%d\n", LinkStackEmpty(S));//判断链栈是否为空

    printf("创建链栈： ");
    CreateLinkStack(S, a, n);//创建链栈
    ShowLinkStack(S);//输出链栈

    printf("链栈是否为空： ");
    printf("%d\n", LinkStackEmpty(S));//判断链栈是否为空

    printf("链栈长度： ");
    printf("%d\n", LinkStackLength(S));//获取链栈的长度

    ElemType e;//出栈元素
    Pop(S, e);//出栈
    printf("元素%d出栈: ", e);
    ShowLinkStack(S);//输出链栈

    ElemType elem = 20;//入栈元素
    Push(S, elem);//入栈
    printf("元素%d入栈: ", elem);
    ShowLinkStack(S);//输出链栈

    printf("销毁链栈： ");
    DestroyLinkStack(S);//销毁链栈

    return 0;
}
