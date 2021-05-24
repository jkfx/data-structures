#include <stdio.h>
#include <stdlib.h>

#define MaxSize 8

typedef struct
{
    int data[MaxSize]; // 用静态数组存放队列元素
    int front, rear;   // 队头指针和队尾指针
} SqQueue;

void InitQueue(SqQueue &Q)
{
    // 初始化时队头、队尾指针都指向 0
    Q.rear = Q.front = 0;
}

// 判断队列是否为空
bool QueueEmpty(SqQueue Q)
{
    return Q.rear == Q.front;
}

// 入队
bool EnQueue(SqQueue &Q, int x)
{
    if ((Q.rear + 1) % MaxSize == Q.front)
        return false;                // 队满报错
    Q.data[Q.rear] = x;              // 新元素插入队尾
    Q.rear = (Q.rear + 1) % MaxSize; // 队尾指针加 1 取模
}

// 出队
bool DeQueue(SqQueue &Q, int &x)
{
    if (Q.rear == Q.front)
        return false; // 队空报错
    x = Q.data[Q.front];
    Q.front = (Q.front + 1) % MaxSize;
    return true;
}

// 获得队头元素
bool GetHead(SqQueue Q, int &x)
{
    if (Q.rear == Q.front)
        return false; // 队空报错
    x = Q.data[Q.front];
    return true;
}

// 获得队列长度
int QueueLength(SqQueue Q)
{
    return (Q.rear + MaxSize - Q.front) % MaxSize;
}

int main(){
    SqQueue Q;
    InitQueue(Q);
    EnQueue(Q, 1);
    EnQueue(Q, 3);
    EnQueue(Q, 5);
    EnQueue(Q, 7);
    EnQueue(Q, 9);
    EnQueue(Q, 11);
    EnQueue(Q, 13);
    EnQueue(Q, 15);
    printf("%d\n", EnQueue(Q, 17));
    printf("Length: %d\n", QueueLength(Q));
    int x;
    while(!QueueEmpty(Q)){
        DeQueue(Q, x);
        printf("%d\n", x);
    }
    printf("Length: %d\n", QueueLength(Q));
    return 0;
}