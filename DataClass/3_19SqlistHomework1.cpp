// Created by lsjss on 2020/3/19.

#include <stdio.h>
#include "Sqlist.cpp"
//#define sqlisth1 main

int sqlisth1() {
    SqList *L;
    int a[10]={60,9,36,13,96,52,73,61,9,25};
    int n = 10;

    printf("��ʼ��˳���");
    InitList(L);//��ʼ��˳���
    DispList(L);//���˳���

    printf("˳����Ƿ�Ϊ�գ�");
    printf("%d\n", ListEmpty(L) );

    printf("����˳���");
    CreateList(L, a, n);//����˳���
    DispList(L);//���˳���

    printf("˳����Ƿ�Ϊ�գ�");
    printf("%d\n", ListEmpty(L) );

    printf("˳����ȣ�");
    printf("%d\n", ListLength(L) );

    printf("˳����е� 3 ��Ԫ�أ�");
    int numlocation1 = 3;//˳��������Ԫ��
    int num1 = 0;//˳��������Ԫ�ص�ֵ
    GetElem(L, numlocation1, num1);//����Ԫ��ֵ
    printf("%d\n", num1 );//����Ԫ��ֵ

    printf("˳�����Ԫ�� 9 �״γ��ֵ�λ�ã�");
    int num2 = 9;//˳���Ԫ��ֵ����9
    printf("%d\n", LocateElem(L, num2));//����λ��

    printf("˳����е� 7 ��λ�ò���Ԫ�� 41 ֮��:");
    int numlocation3 = 7;
    int num3 = 41;
    ListInsert(L, numlocation3, num3);//˳����е� 7 ��λ�ò���Ԫ�� 41
    DispList(L);//���˳���

    printf("˳�����ɾ���� 3 ��λ��Ԫ��֮��");
    int numlocation4 = 3;
    int delnum4 = 0;
    ListDelete(L, numlocation4, delnum4);
    DispList(L);//���˳���

    printf("��ɾ����Ԫ�أ�");
    printf("%d\n", delnum4);

    printf("˳�����ɾ������ֵΪ 9 ��Ԫ�أ�");
    int num4 = 9;
    DelNodel(L, num4);
    DispList(L);//���˳���

    printf("ִ�����ٲ������˳���");
    DestroyList(L);
    DispList(L);//������Ա�

    return 0;
}
