// Created by lsjss on 2020/4/2.
//�����ջ�Ļ���Ԥ�㣬�����Գ�������������㷨����Ͳ��Գ����Լ����н����
#include <stdio.h>
#include "LinkStackNode.cpp"
#define linkstacknode1 main

int linkstacknode1() {
    LinkStackNode *S;//��ջ�ĳ�ʼ����
    int a[9]={45, 66, 21, 34, 82, 19, 5, 79, 57};
    int n = 9;//Ԫ�ظ���

    printf("��ʼ����ջ�� ");
    InitLinkStack(S);//��ʼ����ջ
    ShowLinkStack(S);//�����ջ

    printf("��ջ�Ƿ�Ϊ�գ� ");
    printf("%d\n", LinkStackEmpty(S));//�ж���ջ�Ƿ�Ϊ��

    printf("������ջ�� ");
    CreateLinkStack(S, a, n);//������ջ
    ShowLinkStack(S);//�����ջ

    printf("��ջ�Ƿ�Ϊ�գ� ");
    printf("%d\n", LinkStackEmpty(S));//�ж���ջ�Ƿ�Ϊ��

    printf("��ջ���ȣ� ");
    printf("%d\n", LinkStackLength(S));//��ȡ��ջ�ĳ���

    ElemType e;//��ջԪ��
    Pop(S, e);//��ջ
    printf("Ԫ��%d��ջ: ", e);
    ShowLinkStack(S);//�����ջ

    ElemType elem = 20;//��ջԪ��
    Push(S, elem);//��ջ
    printf("Ԫ��%d��ջ: ", elem);
    ShowLinkStack(S);//�����ջ

    printf("������ջ�� ");
    DestroyLinkStack(S);//������ջ

    return 0;
}
