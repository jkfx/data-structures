#include <stdio.h>
#include <stdlib.h>

typedef struct BiTNode
{
    char data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

void ConstructTree(BiTree &T)
{
    char data;
    T = (BiTNode *)malloc(sizeof(BiTNode));
    T->lchild = T->rchild = NULL;
    scanf("%c", &data);
    if (data == '^')
    {
        T = NULL;
        return;
    }
    T->data = data;
    // 构造左子树
    ConstructTree(T->lchild);
    // 构造右子树
    ConstructTree(T->rchild);
}

void PreOrder(BiTree T)
{
    if (T != NULL)
    {
        printf("%c", T->data);
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}

void InOrder(BiTree T)
{
    if (T != NULL)
    {
        InOrder(T->lchild);
        printf("%c", T->data);
        InOrder(T->rchild);
    }
}

void PostOrder(BiTree T)
{
    if (T != NULL)
    {
        PostOrder(T->lchild);
        PostOrder(T->rchild);
        printf("%c", T->data);
    }
}

#define MAXSIZE 8

typedef struct Queue
{
    BiTree data[MAXSIZE];
    int top, tail;
} Queue;

void InitQueue(Queue &Q)
{
    Q.top = Q.tail = 0;
}

bool EnQueue(Queue &Q, BiTree T)
{
    if ((Q.tail + 1) % MAXSIZE == Q.top)
        return false;
    Q.data[Q.tail++] = T;
    Q.tail %= MAXSIZE;
    return true;
}

bool DeQueue(Queue &Q, BiTree &T)
{
    if (Q.top == Q.tail) // 队空报错
        return false;
    T = Q.data[Q.top++];
    Q.top %= MAXSIZE;
    return true;
}

bool IsEmpty(Queue Q)
{
    return Q.top == Q.tail;
}

// 层次遍历
void LevelOrder(BiTree T)
{
    Queue Q;
    BiTree p;
    InitQueue(Q);
    EnQueue(Q, T);
    while (!IsEmpty(Q))
    {
        DeQueue(Q, p);
        printf("%c", p->data);
        if (p->lchild != NULL)
            EnQueue(Q, p->lchild);
        if (p->rchild != NULL)
            EnQueue(Q, p->rchild);
    }
}

int main()
{
    BiTree T;
    printf("Input tree node: ");
    ConstructTree(T);
    printf("\nPreOrder:\n");
    PreOrder(T);
    printf("\nInOrder:\n");
    InOrder(T);
    printf("\nPostOrder:\n");
    PostOrder(T);
    printf("\nLevelOrder:\n");
    LevelOrder(T);
    return 0;
}