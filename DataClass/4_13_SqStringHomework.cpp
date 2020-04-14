// Created by lsjss on 2020/4/14.
//完成顺序串的基础运算并完成测试，数组自己构造，要与自己的个人信息相关。参考截图
#include <stdio.h>
#include "SqString.cpp"
#define sequential main

void showLineStr(SqString s);
int sequential() {
    SqString s1, s2, substr, s4;

    printf("创建字符串 s1： ");
    StrAssign(s1, "What is your student number? ");
    DispStr(s1);

    printf("创建字符串 s2： ");
    StrAssign(s2, "My student number is 18141040117.");
    DispStr(s2);

    printf("比较字符串 s1 和 s2： %s\n", StrEqual(s1, s2) ? "相等" : "不相等");

    printf("字符串 s1 的长度： %d\n", StrLength(s1));

    int substrBegin = 14, substrLength = 14; //定义要截取子串的开始位置和截取长度
    printf("字符串 s1 的子串（由第 %d 个字符开始向后取 %d 个字符）： ", substrBegin, substrLength);
    DispStr(SubStr(s1, substrBegin, substrLength));

    int position = 28; //定义插入字串的位置
    SqString inStr; //定义要插入的字符串
    StrAssign(inStr, " and you name"); //设置要插入的字符串的内容
    SqString inStrLater; //定义获取插入子串操作后的字符串 (str)
    inStrLater = InsStr(s1, position, inStr); //将插入操作后的字符串赋值到 inStrLater
    printf("字符串后 s1 的位置 %d， 插入%s, 得到新字符串 inStrLater： ", position, inStr);
    DispStr(inStrLater);

    int deleteNumBegin = 32, deleteNumberLength = 4;; //定义要删除子串的开始位置和截取长度
    printf("字符串 inStrLater 中删除");
    showLineStr(SubStr(inStrLater, deleteNumBegin, deleteNumberLength));
    printf(": ");
    DispStr(DelStr(inStrLater, deleteNumBegin, deleteNumberLength));

    SqString concatLater = Concat(s1, s2);
    printf("字符串 s1 和 s2 连接, 得到新字符串 concatLater： ");
    DispStr(concatLater);

    StrCopy(s2, s1);
    printf("复制字符串 s1 后的 s2： ");
    DispStr(s2);

    int replaceNumBegin = 14, replaceNumEnd = 14;//替换字符串的起始位置和替换长度
    SqString replaceString; //定义要被替换的字符串
    StrAssign(replaceString, "name"); //设置要被替换的字符串的内容
    showLineStr(SubStr(s2, replaceNumBegin, replaceNumEnd));
    printf(" 替换为 ");
    showLineStr(replaceString);
    printf(" 之后的 s2: ");
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












































































































