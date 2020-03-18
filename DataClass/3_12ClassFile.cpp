//
// Created by lsjss on 2020/3/12.
//
#include <iostream>
//#define c0312 main
void swap1(int x, int y);
void swap2(int *x, int *y);
void swap(int &x, int &y);
//&a  :取a的地址
int c0312(){
    int a=1,b=2;

    printf("before:a=%d,b=%d\n",a,b);
    swap1(a,b); //引用
    printf("after1:a=%d,b=%d\n",a,b);
    swap2(&a,&b);   //取地址
    printf("after2:a=%d,b=%d\n",a,b);
    swap(a,b);
    printf("after3:a=%d,b=%d\n",a,b);

    return 0;
}

//形式参数的变化不会引起实际参数的变化，起不到交换作用
void swap1(int x, int y){
    int temp = x;
    x=y;
    y=temp;
}

//可以 -- 取地址
void swap2(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

// -- 引用
void swap(int &x, int &y){//-> &x=a
    int temp = x;
    x=y;
    y=temp;
}