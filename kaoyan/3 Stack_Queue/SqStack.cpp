#include <stdio.h>
#include <stdlib.h>

#define MaxSize 10

typedef struct
{
    int data[MaxSize]; // 静态数组存放栈中元素
    int top;           // 栈顶指针
} SqStack;

// 初始化栈
void InitStack(SqStack &S)
{
    S.top = -1; // 初始化栈顶指针
}

// 判断栈空
bool StackEmpty(SqStack S)
{
    if (S.top == -1) // 栈空
        return true;
    else // 不空
        return false;
}

// 新元素入栈
bool Push(SqStack &S, int x)
{
    if (S.top == MaxSize - 1) // 栈满
        return false;
    S.top = S.top + 1; // 指针先加 1
    S.data[S.top] = x; // 新元素入栈
    return true;
}

// 出栈操作
bool Pop(SqStack &S, int &x)
{
    if (S.top == -1) // 栈空
        return false;
    x = S.data[S.top]; // 栈顶元素先出栈
    S.top = S.top - 1; // 指针再减 1
    return true;
}

// 读栈顶元素
bool GetTop(SqStack S, int &x)
{
    if (S.top == -1) // 栈空
        return false;
    x = S.data[S.top]; // x 记录栈顶元素
    return true;
}

int main()
{
    SqStack S;
    InitStack(S);
    Push(S, 1);
    Push(S, 3);
    Push(S, 5);
    Push(S, 7);
    while (!StackEmpty(S))
    {
        int x;
        Pop(S, x);
        printf("%d\n", x);
    }
    return 0;
}