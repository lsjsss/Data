// Created by lsjss on 2020/4/9.
#include <stdio.h>
#define MaxSize 100
//顺序串
typedef struct {
    char data[MaxSize]; //存放串字符
    int length; //存放串长
} SqString; //顺序串类型

//1 生成串
void StrAssign(SqString &s, char cstr[]) {//s 为引用型参数
	int i;
    for(i=0; cstr[i]!='\0'; i++) {
        s.data[i]=cstr[i];
    }
    s.length=i;  //设置串 s 的长度
}

//2 销毁串
void DestroyStr(SqString &s) {
    //由系统自动释放
}

//3 串的复制
void StrCopy(SqString &s, SqString t) { //s 为引用型参数
    for(int i=0; i<t.length; i++) {
        s.data[i]=t.data[i]; //复制 t 的所有字符
    }
    s.length=t.length; //设置串 s 的长度
}

//4 判断串相等
bool StrEqual(SqString s, SqString t) {
    bool same=true;
    if(s.length!=t.length) { //长度不相等时返回 0
        same=false;
    }
    else
        for(int i=0; i<s.length; i++) {
            if(s.data[i]!=t.data[i]) { //有一个对应字符不相同时返回假
                same=false;
                break;
            }
        }
    return same;
}

//5 求串长
int StrLength(SqString s) {
    return s.length;
}

//6 串的连接
SqString Concat(SqString s, SqString t) {
    SqString str;
    int i;
    str.length=s.length+t.length;
    for(i=0; i<s.length; i++) {
        str.data[i]=s.data[i];
    }
    for(i=0; i<t.length; i++) {
        str.data[s.length+i]=t.data[i];
    }
    return str;
}

//7 求子串
SqString SubStr(SqString s,int i,int j) {
    int k;
    SqString str;
    str.length=0;
    if(i<=0||i>s.length||j<0||i+j-1>s.length) {
        return str;
    }
    for(k=i-1; k<i+j-1; k++) {
        str.data[k-i+1]=s.data[k];
    }
    str.length=j;
    return str;
}

//8 子串的插入
SqString InsStr(SqString s1,int i,SqString s2) {
    int j;
    SqString str; //定义结果串
    str.length=0;  //设置 str 为空串
    if(i<=0||i>s1.length+1)  //参数不正确时返回空串
        return str;
    for(j=0; j<i-1; j++)  //将 s1.data[0..i-2] 复制到 str
        str.data[j]=s1.data[j];
    for(j=0; j<s2.length; j++)  //将 s1.data[0..s2.length-1] 复制到 str
        str.data[i+j-1]=s2.data[j];
    for(j=i-1; j<s1.length; j++)  //将 s1.data[i-1..s1.length-1] 复制到 str
        str.data[s2.length+j]=s1.data[j];
    str.length=s1.length+s2.length;
    return str;
}

//9 子串的删除
SqString DelStr(SqString s,int i,int j) {
    int k;
    SqString str;  //定义结果串
    str.length=0;  //设置 str 为空串
    if(i<=0||i>s.length||i+j>s.length+1)
        return str;  //参数不正确时返回空串
    for(k=0; k<i-1; k++)  //将 s.data[0..i-2] 复制到 str
        str.data[k]=s.data[k];
    for(k=i+j-1; k<s.length; k++)  //将 s.data[i+j-1..s.length-1] 复制到str
        str.data[k-j]=s.data[k];
    str.length=s.length-j;
    return str;
}

//10 子串的替换
SqString RepStr(SqString s,int i,int j,SqString t) {
    int k;
    SqString str;  //定义结果串
    str.length=0;  //设置 str 为空串
    if(i<=0||i>s.length||i+j-1>s.length)
        return str;  //参数不正确时返回空串
    for(k=0; k<i-1; k++)  //将 s.data[0..i-2] 复制到 str
        str.data[k]=s.data[k];
    for(k=0; k<t.length; k++)  //将 t.data[0..t.length-1] 复制到 str
        str.data[i+k-1]=t.data[k];
    for(k=i+j-1; k<s.length; k++)  //将 s.data[i+j-1..s.length-1] 复制到 str
        str.data[t.length+k-j]=s.data[k];
    str.length=s.length-j+t.length;
    return str;
}

//11 输出串
void DispStr(SqString s) {
    if(s.length>0) {
        for(int i=0; i<s.length; i++)
            printf("%c",s.data[i]);
        printf("\n");
    }
}

//对字符串 s 和 t 进行比较
int  Strcmp(SqString s, SqString t) {
    int i, comlen;  //comlen 用于存储
    if (s.length<t.length) {
        comlen=s.length;  //求s和t的共同长度
    } else {
        comlen=t.length;
    }
    for (i=0;i<comlen;i++)  {  //在共同长度内逐个字符比较
        if (s.data[i]>t.data[i]) {
            return 1;
        } else if (s.data[i]<t.data[i]) {
            return -1;
        }
    }
    if (s.length==t.length)	{  //s==t
        return 0;
    } else if (s.length>t.length) {  //s>t
        return 1;
    } else {
        return -1;		//s<t
    }
}

