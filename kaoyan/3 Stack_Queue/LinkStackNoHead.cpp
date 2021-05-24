#include <stdio.h>
#include <stdlib.h>

// 不带头结点的链栈实现
typedef struct SNode
{
    int data;
    struct SNode *next;
} SNode, *LinkStack;

bool InitStack(LinkStack &S)
{
    S = NULL;
    return true;
}

bool EmptyStack(LinkStack S)
{
    return S == NULL;
}

bool Push(LinkStack &S, int x)
{
    SNode *node = (SNode *)malloc(sizeof(SNode));
    node->data = x;
    node->next = S;
    S = node;
    return true;
}

bool Pop(LinkStack &S, int &x)
{
    if (S == NULL)
        return false;
    x = S->data;
    S = S->next;
    return true;
}

bool GetTop(LinkStack S, int &x)
{
    if (S == NULL)
        return false;
    x = S->data;
    return true;
}

int main()
{
    LinkStack S;
    InitStack(S);
    Push(S, 1);
    Push(S, 3);
    Push(S, 5);
    Push(S, 7);
    while (!EmptyStack(S))
    {
        int x;
        Pop(S, x);
        printf("%d\n", x);
    }
    return 0;
}