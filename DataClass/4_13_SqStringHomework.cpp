// Created by lsjss on 2020/4/14.
//���˳�򴮵Ļ������㲢��ɲ��ԣ������Լ����죬Ҫ���Լ��ĸ�����Ϣ��ء��ο���ͼ
#include <stdio.h>
#include "SqString.cpp"
#define sequential main

void showLineStr(SqString s);
int sequential() {
    SqString s1, s2, substr, s4;

    printf("�����ַ��� s1�� ");
    StrAssign(s1, "What is your student number? ");
    DispStr(s1);

    printf("�����ַ��� s2�� ");
    StrAssign(s2, "My student number is 18141040117.");
    DispStr(s2);

    printf("�Ƚ��ַ��� s1 �� s2�� %s\n", StrEqual(s1, s2) ? "���" : "�����");

    printf("�ַ��� s1 �ĳ��ȣ� %d\n", StrLength(s1));

    int substrBegin = 14, substrLength = 14; //����Ҫ��ȡ�Ӵ��Ŀ�ʼλ�úͽ�ȡ����
    printf("�ַ��� s1 ���Ӵ����ɵ� %d ���ַ���ʼ���ȡ %d ���ַ����� ", substrBegin, substrLength);
    DispStr(SubStr(s1, substrBegin, substrLength));

    int position = 28; //��������ִ���λ��
    SqString inStr; //����Ҫ������ַ���
    StrAssign(inStr, " and you name"); //����Ҫ������ַ���������
    SqString inStrLater; //�����ȡ�����Ӵ���������ַ��� (str)
    inStrLater = InsStr(s1, position, inStr); //�������������ַ�����ֵ�� inStrLater
    printf("�ַ����� s1 ��λ�� %d�� ����%s, �õ����ַ��� inStrLater�� ", position, inStr);
    DispStr(inStrLater);

    int deleteNumBegin = 32, deleteNumberLength = 4;; //����Ҫɾ���Ӵ��Ŀ�ʼλ�úͽ�ȡ����
    printf("�ַ��� inStrLater ��ɾ��");
    showLineStr(SubStr(inStrLater, deleteNumBegin, deleteNumberLength));
    printf(": ");
    DispStr(DelStr(inStrLater, deleteNumBegin, deleteNumberLength));

    SqString concatLater = Concat(s1, s2);
    printf("�ַ��� s1 �� s2 ����, �õ����ַ��� concatLater�� ");
    DispStr(concatLater);

    StrCopy(s2, s1);
    printf("�����ַ��� s1 ��� s2�� ");
    DispStr(s2);

    int replaceNumBegin = 14, replaceNumEnd = 14;//�滻�ַ�������ʼλ�ú��滻����
    SqString replaceString; //����Ҫ���滻���ַ���
    StrAssign(replaceString, "name"); //����Ҫ���滻���ַ���������
    showLineStr(SubStr(s2, replaceNumBegin, replaceNumEnd));
    printf(" �滻Ϊ ");
    showLineStr(replaceString);
    printf(" ֮��� s2: ");
    DispStr(RepStr(s1, replaceNumBegin, replaceNumEnd, replaceString));

    return 0;
}

void showLineStr(SqString s) {
    if(s.length>0) {
        for(int i=0; i<s.length; i++) {
            printf("%c",s.data[i]);
        }
    }
}












































































































