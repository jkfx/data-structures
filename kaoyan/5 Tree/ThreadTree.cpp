#include <stdio.h>
#include <stdlib.h>

typedef struct ThreadNode
{
    char data;
    struct ThreadNode *lchild, *rchild;
    int ltag, rtag;
} ThreadNode, *ThreadTree;

// 中序线索化
void InThread(ThreadTree &p, ThreadTree &pre)
{
    if (p != NULL)
    {
        InThread(p->lchild, pre); // 线索化左子树
        if (p->lchild == NULL)
        { // 若左子树为空，建立前驱线索
            p->lchild = pre;
            p->ltag = 1;
        }
        if (pre != NULL && pre->rchild == NULL)
        { // 建立前驱节点的后继线索
            pre->rchild = p;
            pre->rtag = 1;
        }
        pre = p;
        InThread(p->rchild, pre); // 线索化右子树
    }
}

// 通过中序遍历建立中序线索二叉树
void CreateInThread(ThreadTree T)
{
    ThreadTree pre = NULL;
    if (T != NULL)
    {
        InThread(T, pre);
        pre->rchild = NULL;
        pre->rtag = 1;
    }
}

// 中序线索二叉树第一个节点
ThreadNode *Firstnode(ThreadNode *p)
{
    while (p->ltag == 0)
        p = p->lchild; // 最左下结点
    return p;
}

// 求线索二叉树结点的后继
ThreadNode *Nextnode(ThreadNode *p)
{
    if (p->rtag == 0)
        return Firstnode(p->rchild);
    else
        return p->rchild;
}

void Inorder(ThreadNode *T)
{
    for (ThreadNode *p = Firstnode(T); p != NULL; p = Nextnode(p))
    {
        printf("%c ", p->data);
    }
}

void BiTree(ThreadTree &T)
{
    T = (ThreadNode *)malloc(sizeof(ThreadNode));
    T->lchild = T->rchild = NULL;
    T->rtag = T->ltag = 0;
    char data;
    scanf("%c", &data);
    if (data == '^')
    {
        T = NULL;
        return;
    }
    T->data = data;
    BiTree(T->lchild);
    BiTree(T->rchild);
}

int main()
{
    ThreadTree T;
    BiTree(T);
    printf("Input BiTree:\n");
    CreateInThread(T);
    Inorder(T);
    printf("\n");
    return 0;
}