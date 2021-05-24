#include <stdio.h>
#include <stdlib.h>

typedef struct DNode
{
    int data;
    struct DNode *prior, *next;
} DNode, *DLinkList;

bool InitList(DLinkList &L)
{
    L = (DLinkList)malloc(sizeof(DNode));
    if (L == NULL)
        return false;
    L->prior = NULL;
    L->next = NULL;
    return true;
}

// 在 p 结点之后插入 s 节点
bool InsertNextDNode(DNode *p, DNode *s)
{
    if (p == NULL || s == NULL) // 非法参数
        return false;
    s->next = p->next;
    if (p->next != NULL) // 若 p 节点之后没有后继节点
        p->next->prior = s;
    s->prior = p;
    p->next = s;
    return true;
}

// 删除 p 节点的后继节点
bool DeleteNextDNode(DNode *p)
{
    if (p == NULL)
        return false;
    DNode *q = p->next; // 找到 p 的后继节点
    if (q == NULL)      // p 没有后继节点
        return false;
    p->next = q->next;
    if (q->next != NULL)
        q->next->prior = p;
    free(q);
    return true;
}

void DestroyList(DLinkList &L)
{
    // 循环释放每个数据节点
    while (L->next != NULL)
        DeleteNextDNode(L);
    free(L);
    L = NULL;
}

int main()
{
    DLinkList L;
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