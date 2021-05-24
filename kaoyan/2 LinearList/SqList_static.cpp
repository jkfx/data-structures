#include <stdio.h>
#define MaxSize 10 // 定义最大长度

typedef struct
{
    int data[MaxSize]; // 静态“数组”存放数据元素
    int length;        // 顺序表的当前长度
} SqList;              // 顺序表的类型定义

// 基本操作——初始化一个顺序表
void InitList(SqList &L)
{
    for (int i = 0; i < MaxSize; i++)
        L.data[i] = 0;
    L.length = 0;
}

bool ListInsert(SqList &L, int i, int e)
{
    if (i < 1 || i > L.length + 1) // 判断 i 的范围是否有效
        return false;
    if (L.length >= MaxSize) // 当前存储空间已满
        return false;
    for (int j = L.length; j >= i; j--) // 将第 i 个元素以及之后的元素后移
        L.data[j] = L.data[j - 1];
    L.data[i - 1] = e; // 在位置 i 处放入 e
    L.length++;        // 长度加 1
    return true;
}

bool ListDelete(SqList &L, int i, int &e)
{
    if (i < 1 || i > L.length) // 判断 i 的范围是否合法
        return false;
    e = L.data[i - 1];                 // 将被删除的元素赋值给 e
    for (int j = i; j < L.length; j++) // 将第 i 个元素后的元素前移
        L.data[j - 1] = L.data[j];
    L.length--; // 线性表长度减 1
    return true;
}

int GetElem(SqList L, int i)
{
    return L.data[i - 1];
}

// 在顺序表中查找第一个元素等于 e 的值，返回其位序
int LocateElem(SqList L, int e)
{
    for (int i = 0; i < L.length; i++)
    {
        if (L.data[i] == e)
            return i + 1;
    }
    return 0;
}

int main()
{
    SqList L;
    InitList(L);
    ListInsert(L, 1, 1);
    ListInsert(L, 2, 3);
    ListInsert(L, 3, 5);
    ListInsert(L, 4, 7);
    ListInsert(L, 5, 9);
    int e = -1;
    ListDelete(L, 3, e);
    return 0;
}