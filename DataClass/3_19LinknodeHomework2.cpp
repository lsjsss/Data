// Created by lsjss on 2020/3/19.
//�������Ļ������㣬����ɲ��Թ��������Խ���ο�ͼ�Ρ�
#include <stdio.h>
#include "Linknode.cpp"
//#define linknodeh1 main

int linknodeh1() {
    LinkNode *L;
    int a[9]={63,7,35,19,94,7,25,64,95};
    int n = 9;

    printf("��ʼ��������");
    InitList(L);//��ʼ��������
    Display(L);//���������

    printf("�������Ƿ�Ϊ�գ�");
    printf("%d\n", ListEmpty(L) );

    printf("����������");
    CreateListF(L, a, n);//ʹ��ͷ�巨����������
    Display(L);//���������

    printf("�������Ƿ�Ϊ�գ�");
    printf("%d\n", ListEmpty(L) );

    printf("�������ȣ�");
    printf("%d\n", ListLength(L) );

    printf("�������е� 5 ��Ԫ�أ�");
    int numlocation1 = 5;//˳�������Ԫ��
    int num1 = 0;//����������Ԫ�ص�ֵ
    GetData(L, numlocation1, num1);//����Ԫ��ֵ
    printf("%d\n", num1 );//����Ԫ��ֵ

    printf("��������Ԫ�� 7 �״γ��ֵ�λ�ã�");
    int num2 = 7;//������Ԫ��ֵ����7
    printf("%d\n", LocateData(L, num2));//����λ��

    printf("�������е� 3 ��λ�ò���Ԫ�� 91 ֮��:");
    int numlocation3 = 3;
    int num3 = 91;
    ListInsert(L, numlocation3, num3);//�������е� 3 ��λ�ò���Ԫ�� 91
    Display(L);//���������

    printf("��������ɾ���� 4 ��λ��Ԫ��֮��");
    int numlocation4 = 4;
    int delnum4 = 0;
    ListDelete(L, numlocation4, delnum4);
    Display(L);//���������

    printf("��ɾ����Ԫ�أ�");
    printf("%d\n", delnum4);

    printf("��������ɾ������ֵΪ 7 ��Ԫ�أ�");
    int num4 = 7;
    DelNodel(L, num4);
    Display(L);//���������

    return 0;
}
