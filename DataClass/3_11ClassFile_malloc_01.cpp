// Created by lsjss on 2020/3/21.

/**
 * C++中的内存分配
 * char *p; 中 p 为自动变量，其自身的空间系统自动分配和释放
 * 但是用 malloc 分配的存储空间，不会被系统自动释放，需要自己释放，使用 free 函数。
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//X
//#define malloc_01 main
int malloc_01() {
    //定义指向字符的指针 p
    char *p;
    //指针变量，转换为字符指针， 10:分配的字符个数， sizeof: 求每个字符占用的空间大小
    p = (char *)malloc(10 * sizeof(char));
    //将 China 存放到 p 所指向的空间
    strcpy(p, "China");
    //输出 C
    printf("%c\n", p);
    //输出 China
    printf("%s\n", p);
    //释放所指向的空间
    free(p);
    return 0;
}

