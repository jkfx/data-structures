#include <stdio.h>
#include <stdlib.h>

typedef struct RNode
{
    int data;
    RNode *next;
} RNode, *RLinkList;

// 初始化一个循环单链表
bool InitList(RLinkList &L)
{
    L = (RNode *)malloc(sizeof(RNode)); // 分配一个头节点
    if (L == NULL)
        return false;
    L->next = L; // 头节点 next 指向头节点
    return true;
}

// 判断循环链表是否为空
bool Empty(RLinkList L)
{
    if (L->next == L)
        return true;
    else
        return false;
}

// 判断节点 p 是否为循环单链表的表尾节点
bool isTail(RLinkList L, RNode *p)
{
    if (p->next == L)
        return true;
    else
        return false;
}

