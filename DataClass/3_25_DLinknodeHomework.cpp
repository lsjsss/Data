// Created by lsjss on 2020/3/25.
#include "DLinknode.cpp"
//#define dlinknodeh1 main

int dlinknodeh1() {
    DLinkNode *L;
    int a[11]={63, 58, 7, 35, 19, 94, 7, 55, 25, 64, 95};
    int n = 11;

    printf("��ʼ��˫���� ");
    InitList(L);//��ʼ��˫����
    DispList(L);//���˫����

    printf("˫�����Ƿ�Ϊ�գ� ");
    printf("%d\n", ListEmpty(L) );

    printf("ʹ��ͷ�巨����˫���� ");
    CreateListF(L, a, n);//ʹ��ͷ�巨����˫����
    DispList(L);

    printf("ʹ��β�巨����˫���� ");
    CreateListR(L, a, n);
    DispList(L);//���˫����

    printf("�ж�˫�����Ƿ�Ϊ��: %d\n", ListEmpty(L));

    printf("˫�����ȣ� ");
    printf("%d\n", ListLength(L));

    printf("˫�����е� 9 ��Ԫ�أ� ");
    int numlocation1 = 9;//˫����� 9 ��Ԫ��
    int num1 = 0;//˫��������Ԫ�ص�ֵ,Ĭ��Ϊ0
    GetElem(L, numlocation1, num1);//����Ԫ��ֵ
    printf("%d\n", num1 );//����Ԫ��ֵ

    printf("˫������Ԫ�� 7 �״γ��ֵ�λ�ã� ");
    int num2 = 7;//˫����Ԫ��ֵ����7
    printf("%d\n", LocateElem(L, num2));//����λ��

    printf("˫�����е� 4 ��λ�ò���Ԫ�� 11 ֮��: ");
    int numlocation3 = 4;
    int num3 = 11;
    ListInsert(L, numlocation3, num3);//˫�����е� 4 ��λ�ò���Ԫ�� 11
    DispList(L);//���˫����

    printf("˫������ɾ���� 6 ��λ��Ԫ��֮�� ");
    int numlocation4 = 6;//Ҫɾ��Ԫ�ص�λ��
    int delnum4 = 0;//Ҫɾ��Ԫ�ص�ֵ,Ĭ��Ϊ0
    ListDelete(L, numlocation4, delnum4);
    DispList(L);//���˫����

    printf("��ɾ����Ԫ�أ� ");
    printf("%d\n", delnum4);

    printf("����˫����");
    DestroyList(L);

    return 0;
}
