#include <stdio.h>
#include <stdlib.h>

typedef struct DNode
{
    int data;
    struct DNode *prior, *next;
} DNode, *RDLinkList;

// 初始化空的循环双链表
bool InitList(RDLinkList &L)
{
    L = (DNode *)malloc(sizeof(DNode));
    if (L == NULL)
        return false;
    L->prior = L; // 头节点的 prior 指向头节点
    L->next = L;  // 头节点的 next 指向头节点
    return true;
}

// 判断循环双链表是否为空
bool Empty(RDLinkList L)
{
    if (L->next == L)
        return true;
    else
        return false;
}

// 判断节点 p 是否为循环双链表的表尾节点
bool isTail(RDLinkList L, DNode *p)
{
    if (p->next == L)
        return true;
    else
        return false;
}

// 在 p 节点之后插入 s 节点
bool InsertNextDNode(DNode *p, DNode *s)
{
    s->next = p->next;
    p->next->prior = s;
    s->prior = p;
    p->next = s;
    return true;
}

// 删除 p 的后继节点
bool DeleteNextDNode(DNode *p)
{
    DNode *q = p->next;
    p->next = q->next;
    q->next->prior = p;
    free(q);
    return true;
}

int main()
{
    RDLinkList L;
    InitList(L);
    DNode *p;
    InitList(p);
    p->data = 1;
    InsertNextDNode(L, p);
    InitList(p);
    p->data = 3;
    InsertNextDNode(L, p);
    InitList(p);
    p->data = 5;
    InsertNextDNode(L, p);
    InitList(p);
    p->data = 7;
    InsertNextDNode(L, p);
    DeleteNextDNode(L);
    return 0;
}