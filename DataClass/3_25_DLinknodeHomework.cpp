// Created by lsjss on 2020/3/25.
#include "DLinknode.cpp"

int main() {
    DLinkNode* L;
    Initalize(L);
    Push_Back(L, 1);
    Push_Back(L, 2);
    Push_Back(L, 3);
    Push_Back(L, 4);
    Push_Head(L, 5);
    Push_Head(L, 6);
    Push_Head(L, 7);
    Push_Head(L, 8);
    Print(L);
    Delete(L, 3);
    Print(L);
    Pop_Head(L);
    Print(L);
    return 0;
}

