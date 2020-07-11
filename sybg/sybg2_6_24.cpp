// Created by lsjss on 2020/6/25.

#include <stdio.h>
#include <malloc.h>
#define sybg2_6_24 main


// ˳���
#define MaxSize 50
typedef int ElemType;

// ˳���ṹ
typedef struct {
    ElemType data[MaxSize]; //���˳���Ԫ��
    int length; //���˳���ĳ���
} SqList;   //˳���Ľڵ�����

// ����˳���
void CreateList(SqList *&L, ElemType a[], int n) {
    L = (SqList *) malloc(sizeof(SqList));
    for (int i = 0; i < n; i++)
        L->data[i] = a[i];
    L->length = n;
}

//1 ��ʼ�����Ա�
void InitList(SqList *&L) {
    L = (SqList *) malloc(sizeof(SqList));   //���������Ա�Ŀռ�
    L->length = 0;  //�ÿ����Ա���Ϊ 0
}

//2 �������Ա�
void DestroyList(SqList *&L) {
    free(L);    //�ͷ� L ��ָ��˳���ռ�
}

//3 �ж����Ա��Ƿ�Ϊ�ձ�
bool ListEmpty(SqList *L) {
    return (L->length == 0);
}

//4 �����Ա�ĳ���
int ListLength(SqList *L) {
    return (L->length);
}

//5 ������Ա�
void DispList(SqList *L) {
    for (int i = 0; i < L->length; i++) //ɨ��˳��������Ԫ��ֵ
        printf("%d ", L->data[i]);
    printf("\n");
}


// ����
// ˳�����
int SeqSearch(SqList *&R, int n, int k) {
    int i = 0;
    while (i < n && R->data[i] != k)    //�ӱ�ͷ������
        i++;
    if (i >= n)            //δ�ҵ�����0
        return 0;
    else
        return i + 1;        //�ҵ������߼����i+1
}

// �۰����
int BinSearch(SqList *&R, int n, int k) {
    int low = 0, high = n - 1, mid;
    while (low <= high) {        //��ǰ�������Ԫ��ʱѭ��
        mid = (low + high) / 2;
        if (R->data[mid] == k)    //���ҳɹ��������߼����mid+1
            return mid + 1;
        if (k < R->data[mid])    //������R[low..mid-1]�в���
            high = mid - 1;
        else
            low = mid + 1;        //������R[mid+1..high]�в���
    }
    return 0;
}


int sybg2_6_24() {
    SqList *L;
    int a[10] = {11, 15, 22, 25, 33, 44, 55, 66, 77, 88};
    int n = 10;
    int findnumber;

    printf("����˳���");
    CreateList(L, a, n);//����˳���
    DispList(L);//���˳���

    // ˳�����
    findnumber = 55;
    printf("˳����ҹؼ��� %d ���ڵ�λ�ã� %d\n", findnumber, SeqSearch(L, n, findnumber));

    // �۰���� 1
    findnumber = 66;
    printf("%˳����ҹؼ��� %d ���ڵ�λ�ã� %d\n", findnumber, BinSearch(L, n, findnumber));

    // �۰���� 2
    findnumber = 52;
    printf("˳����ҹؼ��� %d ���ڵ�λ�ã� %d\n", findnumber, BinSearch(L, n, findnumber));

    return 0;
}
