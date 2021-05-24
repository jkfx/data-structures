#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 32

typedef struct SqStack
{
    char data[MAXSIZE];
    int top;
} SqStack;

// 初始化栈
void InitStack(SqStack &S);

// 判断栈是否为空
bool StackEmpty(SqStack S);

// 新元素入栈
bool Push(SqStack &S, char x);

// 栈顶元素出栈，用 x 返回
bool Pop(SqStack &S, char &x);

bool bracketCheck(char str[], int length)
{
    SqStack S;
    InitStack(S);
    for (int i = 0; i < length; i++)
    {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{')
            Push(S, str[i]);
        else
        {
            // 多余右括号
            if (StackEmpty(S))
                return false;

            char topElem;
            Pop(S, topElem);
            // 左右符号不匹配
            if (str[i] == ')' && topElem != '(')
                return false;
            if (str[i] == ']' && topElem != '[')
                return false;
            if (str[i] == '}' && topElem != '{')
                return false;
        }
    }
    return StackEmpty(S); // 是否多余左括号
}

void InitStack(SqStack &S)
{
    S.top = -1;
}

bool StackEmpty(SqStack S)
{
    return S.top == -1;
}

bool Push(SqStack &S, char x)
{
    // 栈满
    if (S.top == MAXSIZE - 1)
        return false;
    S.data[++S.top] = x;
    return true;
}

bool Pop(SqStack &S, char &x)
{
    // 栈空
    if (StackEmpty(S))
        return false;
    x = S.data[S.top--];
    return true;
}

int main(){
    char str[] = "()[]{}";
    printf("%d\n", bracketCheck(str, strlen(str)));
    return 0;
}