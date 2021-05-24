#include <stdio.h>
#include <stdlib.h>

typedef struct LinkNode
{ // 链式队列结点
    int data;
    struct LinkNode *next;
} LinkNode;

typedef struct
{                           // 链式队列
    LinkNode *front, *rear; // 队列的队头和队尾指针
} LinkQueue;

// 带头结点的队列初始化
void InitQueue_head(LinkQueue &Q)
{
    // 初始化时，front、rear 都指向头结点
    Q.front = Q.rear = (LinkNode *)malloc(sizeof(LinkNode));
    Q.front->next = NULL;
}

// 不带头结点的队列初始化
void InitQueue(LinkQueue &Q)
{
    // 初始化时，front、rear 都指向 NULL
    Q.front = NULL;
    Q.rear = NULL;
}

// 带头结点的新元素入队
void Enqueue_head(LinkQueue &Q, int x)
{
    LinkNode *s = (LinkNode *)malloc(sizeof(LinkNode));
    s->data = x;
    s->next = NULL;
    Q.rear->next = s; // 新节点插入到 rear 之后
    Q.rear = s;       // 修改表尾指针
}

// 新元素入队（不带头结点）
void Enqueue(LinkQueue &Q, int x)
{
    LinkNode *s = (LinkNode *)malloc(sizeof(LinkNode));
    s->data = x;
    s->next = NULL;
    if (Q.rear == NULL)
    { // 在空队列中插入第一个元素
        // 修改队头队尾指针
        Q.front = s;
        Q.rear = s;
    }
    else
    { // 新节点插入到 rear 之后
        Q.rear->next = s;
        Q.rear = s;
    }
}

// 出队（带头节点）
bool Dequeue_head(LinkQueue &Q, int &x)
{
    if (Q.front->next == NULL)
        return false;
    LinkNode *p = Q.front->next;
    x = p->data;             // 用变量 x 返回队头元素
    Q.front->next = p->next; // 修改头结点的 next 指针
    if (Q.rear == p)         // 若此次是最后一个节点出队
        Q.rear = Q.front;    // 修改 rear 指针
    free(p);
    return true;
}

// 出队（不带头结点）
bool Dequeue(LinkQueue &Q, int &x)
{
    if (Q.front == NULL)
        return false;
    LinkNode *p = Q.front; // p 指向出队的节点
    x = p->data;           // 用变量 x 返回队头元素
    Q.front = p->next;     // 修改 front 指针
    if (Q.rear == p)       // 若此次是最后一个节点出队
    {
        // 队头、队尾指针指向空
        Q.front = NULL;
        Q.rear = NULL;
    }
    free(p);
    return true;
}

int main()
{
    LinkQueue Q, Q_head;
    InitQueue(Q);
    InitQueue_head(Q_head);
    Enqueue(Q, 7);
    Enqueue_head(Q_head, 7);
    int x;
    Dequeue(Q, x);
    Dequeue_head(Q_head, x);
    Enqueue(Q, 2);
    Enqueue_head(Q_head, 2);
    Enqueue(Q, 4);
    Enqueue_head(Q_head, 4);
    Enqueue(Q, 6);
    Enqueue_head(Q_head, 6);
    Enqueue(Q, 8);
    Enqueue_head(Q_head, 8);
    return 0;
}