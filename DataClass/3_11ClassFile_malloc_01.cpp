// Created by lsjss on 2020/3/21.

/**
 * C++�е��ڴ����
 * char *p; �� p Ϊ�Զ�������������Ŀռ�ϵͳ�Զ�������ͷ�
 * ������ malloc ����Ĵ洢�ռ䣬���ᱻϵͳ�Զ��ͷţ���Ҫ�Լ��ͷţ�ʹ�� free ������
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//X
//#define malloc_01 main
int malloc_01() {
    //����ָ���ַ���ָ�� p
    char *p;
    //ָ�������ת��Ϊ�ַ�ָ�룬 10:������ַ������� sizeof: ��ÿ���ַ�ռ�õĿռ��С
    p = (char *)malloc(10 * sizeof(char));
    //�� China ��ŵ� p ��ָ��Ŀռ�
    strcpy(p, "China");
    //��� C
    printf("%c\n", p);
    //��� China
    printf("%s\n", p);
    //�ͷ���ָ��Ŀռ�
    free(p);
    return 0;
}

