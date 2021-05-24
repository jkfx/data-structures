#include <stdio.h>
#include <stdlib.h>

typedef struct LNode
{                       // 定义单链表结点类型
    int data;           // 每个节点存放一个数据元素
    struct LNode *next; // 指针指向下一个节点
} LNode, *LinkList;

// 初始化一个单链表（带头结点）
bool InitList(LinkList &L)
{
    L = (LNode *)malloc(sizeof(LNode)); // 分配一个头节点
    if (L == NULL)
        return false;
    L->next = NULL; // 头节点之后暂时还没有节点
    return true;
}

// 在第 i 个位置上插入元素 e（带头结点）
bool ListInsert(LinkList &L, int i, int e)
{
    if (i < 1)
        return false;
    LNode *p;  // 指针 p 指向当前扫描到的节点
    int j = 0; // 当前 p 指向的是第几个节点
    p = L;     // L 指向头节点，头节点算作第 0 个节点
    while (p != NULL && j < i - 1)
    {
        p = p->next;
        j++;
    }
    if (p == NULL) // i 值不合法
        return false;
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s; // 将节点 s 连到 p 之后
    return true;
}

// 后插操作：在 p 节点之后插入元素 e
bool InsertNextNode(LNode *p, int e)
{
    if (p == NULL)
        return false;
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data = e; // 用节点 s 保存数据元素 e
    s->next = p->next;
    p->next = s; // 将节点 s 连到 p 之后
    return true;
}

// 前插操作：在 p 节点之前插入元素 e
bool InsertPriorNode(LNode *p, int e)
{
    if (p == NULL)
        return false;
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->next = p->next;
    p->next = s;       // 新节点 s 连到 p 之后
    s->data = p->data; // 将 p 中元素复制到 s 中
    p->data = e;       // p 中元素覆盖为 e
    return true;
}

// 删除第 i 个位置的元素
bool ListDelete(LinkList &L, int i, int &e)
{
    if (i < 1)
        return false;
    LNode *p;  // p 指针指向当前扫描到的节点
    int j = 0; // 当前 p 指向的是第几个节点
    p = L;     // L 指向头节点，头节点当作第 0 个节点
    while (p != NULL && j < i - 1)
    {
        p = p->next;
        j++;
    }
    if (p == NULL) // i 值不合法
        return false;
    if (p->next == NULL) // 第 i-1 个节点之后已无其他节点
        return false;
    LNode *q = p->next; // 令 q 指向被删除节点
    e = q->data;        // 用 e 返回元素的值
    p->next = q->next;  // 将 q 从链表中断开
    free(q);            // 释放节点的存储空间
    return true;
}

// 删除指定节点 p
bool DeleteNode(LNode *p)
{
    if (p == NULL)
        return false;
    LNode *q = p->next;      // 令 q 指向 p 的后继节点
    p->data = p->next->data; // 和后继节点交换数据域
    p->next = q->next;       // 将 q 节点从链表中断开
    free(q);                 // 释放后继节点的存储空间
    return true;
}

// 按位查找，返回第 i 个元素（带头结点）
LNode *GetElem(LinkList L, int i)
{
    if (i < 0)
        return NULL;
    LNode *p;                  // 指针 p 指向当前扫描到的节点
    int j = 0;                 // 当前 p 指向的是第几个节点
    p = L;                     // L 指向头节点，头节点当作第 0 个节点
    while (p != NULL && j < i) // 循环找到第 i 个节点
    {
        p = p->next;
        j++;
    }
    return p;
}

// 按置查找，找到数据域 == e 的节点
LNode *LocateElem(LinkList L, int e)
{
    LNode *p = L->next;
    // 从第 1 个节点开始查找数据域为 e 的节点
    while (p != NULL && p->data != e)
        p = p->next;
    return p; // 找到后返回该指针，否则返回 NULL
}

// 求表的长度
int Length(LinkList L)
{
    int len = 0; // 统计表长
    LNode *p = L;
    while (p->next != NULL)
    {
        p = p->next;
        len++;
    }
    return len;
}

// 正向建立单链表
LinkList List_TailInsert(LinkList &L)
{
    int x;                               // 数据元素类型
    L = (LinkList)malloc(sizeof(LNode)); // 建立头节点
    LNode *s, *r = L;                    // r 为尾指针
    scanf("%d", &x);
    while (x != 9999)
    {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        s->next = NULL; // 尾节点指针置空
        r->next = s;
        r = s; // r 指向新的表尾节点
        scanf("%d", &x);
    }
    return L;
}

// 逆向建立单链表
LinkList List_HeadInsert(LinkList &L)
{
    LNode *s;
    int x;
    L = (LinkList)malloc(sizeof(LNode)); // 创建头节点
    L->next = NULL;                      // 初始链表为空
    scanf("%d", &x);                     // 输入节点的值
    while (x != 9999)
    {
        s = (LNode *)malloc(sizeof(LNode)); // 创建新节点
        s->data = x;
        s->next = L->next;
        L->next = s; // 将新节点插入表中，L 为头指针
        scanf("%d", &x);
    }
    return L;
}

int main()
{
    LinkList L; // 声明一个指向单链表的指针
    // List_TailInsert(L);
    List_HeadInsert(L);
    return 0;
}