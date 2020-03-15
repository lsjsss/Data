// Created by lsj on 2020/3/10.
#include <stdio.h>      //编译预处理，标准输入输出头文件
#include <iostream>     //编译预处理，输入输出流
#include <string.h>     //编译预处理，用于处理字符数组

//#define book1 main

using namespace std;    //调用命名空间 std 中的标识符
//P11 语句1
struct Teacher {    //教师结构体类型
    int no;     //整型成员编号，占 4 个字节
    char name[8];       //字符型成员姓名，占 8 个字节
    int age;           //整型成员年龄，占 4 个直字节
};
//P11 语句3
union Tag{     //定义共用体类型 Tag
    short int n;    //短整型成员 n
    char ch[2];     //字符型成员 ch 数组
};

//P12 语句1
typedef char ElemType;  //使用typedef关键字指定新的数据类型名,使得 char 类型与 ElemType 的数据类型等同
//P12 语句2
typedef struct Student{     //学生结构体类型
    int no;     //整型成员学号，
    char name[10];      //字符型成员姓名
    char sex;       //字符型成员性别
    int cno;        //整型成员班号
} NewType;      //使用typedef关键字为学生结构体类型 Student 指定新的数据类型名 NewType

int book1(){     //程序执行
    //P9 语句1
    int i = 2, j = 5, k;    //定义整型自动变量 i，j，k，并分别为 i，j 赋初始值 2 和 5
    k = i + j;  //将 i+j 的值赋予 k
    cout << k << endl;  //输出显示计算后得出结果的 k 值

    //P9 语句2
//    int i2 = 999999999;    //超出 int 类型数据的取值范围
//    i2 **;  //语法错误，不存在此 c 运算符

    //P10 语句1
    int n = 10; //定义整型自动变量 n，并为 n 赋初始值为 10
    //P10 语句2
    int i3, *p; //定义整型变量 i3 ，指向整型变量的指针变量 p (用于存放地址)
    //P10 语句3
    int i4 = 2,*p2 = &i4;  //定义整型变量 i，指向整型变量的指针变量 p，同时取整型变量 i4 的地址赋予 p2
    printf("%d\n", *p2);    //格式化输出指针 p 所指向的整型变量 i 中的变量值 2

    //P11 语句2
    struct Teacher t;   //定义结构体类型 Teacher 的结构体变量 t
    t.no=85;    //结构体变量 t 引用 no，为结构体变量 t 中的成员编号 no 赋值 85
    strcpy(t.name,"张敏");    //使用标准库 <string.h> 函数 strcpy() 将字符串 "张敏" 赋值到结构体变量 t 引用的成员姓名 name 中
    t.age=42;   //结构体变量 t 引用 age ，为结构体变量 t 中的成员年龄 age 赋值 42

    cout << "struct t: " << t.no << " " << t.name << " " << t.age << endl;    //输出结构体变量 t 中的各项成员
    //P11 语句4
    union Tag u;    //定义共用体类型 Tag 的共用体变量u
    u.n = 0x4142;   //为共用体变量 u 中的成员 n 赋值，n 与 ch 成员共享相同内存

    cout << "union u: " << u.n << " " << u.ch << endl;   //输出共用体变量 u 中的各项成员

    //P12 语句3，4
    NewType s1, s2;
    struct Student s3, s4;  //与  NewType s1, s2;  定义的数据类型相同
    //P12 语句5
    int a[10];  //定义整型数组 a，并为数组 a 分配静态存储空间，数组的长度为 10
    //P12 语句6
    char *p3;   //定义指向字符变量的指针 p3
    p3 = (char * ) malloc (10 * sizeof(char));   //使用 malloc() 函数为指针变量 p3 动态分配 10 个连续的字符空间
    strcpy(p3,"China");     //将字符串 "China" 存放到 p 所指向的字符数组连续空间中
    printf("%c\n", *p3);        //指针 p3 指向字符串的第一个字符的地址，输出字符 "C"
    printf("%s\n", p3);     //自 p3 的首个字符开始输逐个出输出字符数组中的字符，输出字符串 "China"
    free(p3);       //释放指针 p3 所指向的空间

    return 0;       //程序结束
}
