# 数据结构复习
# 第一章 绪论
# 第二章 线性表
# 第三章 栈和队列
# 第四章 串

# 第五章 递归
## 5.1 什么是递归

### 5.1.1递归定义
- 前(i+1)元素的平均值
- 定义是递归的
- 数据结构是递归的
- 问题的求解方法是递归的
### 5.1.3 递归模型
一般地，一个递归模型是由递归出口和递归体两部分组成。
- 递归出口确定递归到何时结束。
- 递归体确定递归求解时的递推关系。

## 5.2 递归和栈
### 5.2.1 函数调用栈
- 函数执行是通过系统栈实现的。系统栈分为若干个栈帧。
- 一次函数调用相关的数据保存在栈帧中。体现先进后出的特点！

## 5.3 递归算法设计
掌握阶乘，斐波那契数列，汉诺塔三个算法

## 5.4 习题

1. 分析调用 fun(5)的输出结果。

    ```c++
    void fun(int n) { 
        if (n==1)
            printf("a:%d\n",n);
        else{ 
            printf("b:%d\n #数据结构复习
# 第一章 绪论
# 第二章 线性表
# 第三章 栈和队列
# 第四章 串

# 第五章 递归
## 5.1 什么是递归

### 5.1.1递归定义
- 前(i+1)元素的平均值
- 定义是递归的
- 数据结构是递归的
- 问题的求解方法是递归的
### 5.1.3 递归模型
一般地，一个递归模型是由递归出口和递归体两部分组成。
- 递归出口确定递归到何时结束。
- 递归体确定递归求解时的递推关系。

## 5.2 递归和栈
### 5.2.1 函数调用栈
- 函数执行是通过系统栈实现的。系统栈分为若干个栈帧。
- 一次函数调用相关的数据保存在栈帧中。体现先进后出的特点！

## 5.3 递归算法设计
掌握阶乘，斐波那契数列，汉诺塔三个算法

## 5.4 习题

1. 分析调用 fun(5)的输出结果。

    ```c++
    void fun(int n) { 
        if (n==1)
            printf("a:%d\n",n);
        else{ 
            printf("b:%d\n",n);
            fun(n-1);
            printf("c:%d\n",n);
        } 
    }
    ```
2. 已知 `A[0...n-1]` 为整数数组，设计一个递归算法求这 n 个元素的平均值。
    ```c++
    float avg(int A[],int i)
    {	
       if (i==0) 
           return(A[0]);    
       else
           return((avg(A,i-1)*i+A[i])/(i+1));    
    }
    ```
3. 设计一个算法求正整数 n 的位数。
    ```c++
   int fun(int n)
   {	
       if (n<10) 
           return 1;   
       else
           return fun(n/10)+1;   
   }
    ```
4. 上楼可以一步上一阶，也可以一步上两阶。设计一个递归算法，计算共有多少种不同的走法。
    ```c++
    int fun(int n)
    {	
       if (n==1 || n==2)
           return n;    
        else
           return fun(n-1)+fun(n-2);
    }
    ```
5. 设计一个递归算法，利用顺序串的基本运算求串 s 的逆串
    ```c++
    #include "sqstring.cpp"	    
    SqString invert(SqString s)
    {	
       SqString s1,s2;
       if (StrLength(s)>0){
           s1=invert(SubStr(s,2,StrLength(s)-1)); 
           s2=Concat(s1,SubStr(s,1,1));
       }else
           StrCopy(s2,s);
       return s2;
    }
    ```
6. 设有一个不带表头结点的单链表 L，设计两个递归算法，del(L，x)删除单链表 L 中第一个值为 x 的结点，delall(L，x)删除单链表 L 中所有值为 x 的结点。
    ```c++
   //删除一个
   void del(LinkNode *&L,ElemType x){
       LinkNode *t;
       if (L==NULL) return; if (L->data==x){
           t=L; L=L->next; free(t); 
           return;
       }
       del(L->next,x);
   }
   
   //删除多个
   void delall(LinkNode *&L,ElemType x){
       LinkNode *t;
       if (L==NULL) 
           return; 
       if (L->data==x){
           t=L; 
           L=L->next; 
           free(t);
       }
       delall(L->next,x);
   } 
   ```
7. 设有一个不带表头结点的单链表 L，设计两个递归算法，maxnode(L)返回单链表L中最大结点值，minnodel(L)返回单链表 L 中最小结点值。
    ```c++
   //最大节点
   ElemType maxnode(LinkNode *L) {
       ElemType max;
       if (L->next == NULL) 
           return L->data;
       max = maxnode(L->next);
       if (max > L->data) 
           return max; 
       else 
           return L->data;
   }
   //最小节点
   ElemType minnode(LinkNode *L) {
       ElemType min;
       if (L->next == NULL) 
           return L->data;
       min = minnode(L->next);
       if (min > L->data) 
           return L->data; 
       else return min;
   } 
   ```",n);
            fun(n-1);
            printf("c:%d\n",n);
        } 
    }
    ```
2. 已知 `A[0...n-1]` 为整数数组，设计一个递归算法求这 n 个元素的平均值。
    ```c++
    float avg(int A[],int i)
    {	
       if (i==0) 
           return(A[0]);    
       else
           return((avg(A,i-1)*i+A[i])/(i+1));    
    }
    ```
3. 设计一个算法求正整数 n 的位数。
    ```c++
   int fun(int n)
   {	
       if (n<10) 
           return 1;   
       else
           return fun(n/10)+1;   
   }
    ```
4. 上楼可以一步上一阶，也可以一步上两阶。设计一个递归算法，计算共有多少种不同的走法。
    ```c++
    int fun(int n)
    {	
       if (n==1 || n==2)
           return n;    
        else
           return fun(n-1)+fun(n-2);
    }
    ```
5. 设计一个递归算法，利用顺序串的基本运算求串 s 的逆串
    ```c++
    #include "sqstring.cpp"	    
    SqString invert(SqString s)
    {	
       SqString s1,s2;
       if (StrLength(s)>0){
           s1=invert(SubStr(s,2,StrLength(s)-1)); 
           s2=Concat(s1,SubStr(s,1,1));
       }else
           StrCopy(s2,s);
       return s2;
    }
    ```
6. 设有一个不带表头结点的单链表 L，设计两个递归算法，del(L，x)删除单链表 L 中第一个值为 x 的结点，delall(L，x)删除单链表 L 中所有值为 x 的结点。
    ```c++
   //删除一个
   void del(LinkNode *&L,ElemType x){
       LinkNode *t;
       if (L==NULL) return; if (L->data==x){
           t=L; L=L->next; free(t); 
           return;
       }
       del(L->next,x);
   }
   
   //删除多个
   void delall(LinkNode *&L,ElemType x){
       LinkNode *t;
       if (L==NULL) 
           return; 
       if (L->data==x){
           t=L; 
           L=L->next; 
           free(t);
       }
       delall(L->next,x);
   } 
   ```
7. 设有一个不带表头结点的单链表 L，设计两个递归算法，maxnode(L)返回单链表L中最大结点值，minnodel(L)返回单链表 L 中最小结点值。
    ```c++
   //最大节点
   ElemType maxnode(LinkNode *L) {
       ElemType max;
       if (L->next == NULL) 
           return L->data;
       max = maxnode(L->next);
       if (max > L->data) 
           return max; 
       else 
           return L->data;
   }
   //最小节点
   ElemType minnode(LinkNode *L) {
       ElemType min;
       if (L->next == NULL) 
           return L->data;
       min = minnode(L->next);
       if (min > L->data) 
           return L->data; 
       else return min;
   } 
   ```