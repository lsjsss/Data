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
//    printf("��ʼ��˳���");
//    InitList(L);//��ʼ��˳���
//    DispList(L);//���˳���
//
//    printf("˳����Ƿ�Ϊ�գ�");
//    printf("%d\n", ListEmpty(L) );
//
//    printf("����˳���");
//    CreateList(L, a, n);//����˳���
//    DispList(L);//���˳���
//
//    printf("˳����Ƿ�Ϊ�գ�");
//    printf("%d\n", ListEmpty(L) );
//
//    printf("˳����ȣ�");
//    printf("%d\n", ListLength(L) );
//
//    printf("˳����е� 4 ��Ԫ�أ�");
//    int numlocation1 = 4;//˳�����ĸ�Ԫ��
//    int num1 = 0;//˳�����ĸ�Ԫ�ص�ֵ
//    GetElem(L, numlocation1, num1);//����Ԫ��ֵ
//    printf("%d\n", num1 );//����Ԫ��ֵ
//
//    printf("˳�����Ԫ�� 6 �״γ��ֵ�λ�ã�");
//    int num2 = 6;//˳���Ԫ��ֵ���� 6
//    printf("%d\n", LocateElem(L, num2));//����λ��
//
//    printf("˳����е� 8 ��λ�ò���Ԫ�� 52 ֮��:");
//    int numlocation3 = 8;
//    int num3 = 52;
//    ListInsert(L, numlocation3, num3);//˳����е� 8 ��λ�ò���Ԫ�� 52
//    DispList(L);//���˳���
//
//    printf("˳�����ɾ���� 5 ��λ��Ԫ��֮��");
//    int numlocation4 = 5;
//    int delnum4 = 0;
//    ListDelete(L, numlocation4, delnum4);
//    DispList(L);//���˳���
//
//    printf("��ɾ����Ԫ�أ�");
//    printf("%d\n", delnum4);
//
//    printf("˳�����ɾ������ֵΪ 6 ��Ԫ�أ�");
//    int num4 = 6;
//    DelNodel(L, num4);
//    DispList(L);//���˳���
//
//    printf("ִ�����ٲ������˳���");
//    DestroyList(L);
//    DispList(L);//������Ա�
//
////    printf("======================\n");
////    fun(L, 2);
////    DispList(L);
//
//    return 0;
//}
