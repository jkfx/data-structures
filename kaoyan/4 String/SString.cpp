#include <stdio.h>
#include <stdlib.h>

#define MAXLEN 255

typedef struct
{
    char ch[MAXLEN];
} SString;

// 赋值操作
void StrAssign(SString &T, char *S)
{
    T.ch[0] = 0;
    char ch = S[0];
    while (ch != '\0')
    {
        T.ch[0]++;
        T.ch[T.ch[0]] = ch;
        ch = S[T.ch[0]];
    }
}

// 比较操纵；若 S > T 返回值 > 0；若 S = T 返回值 = 0；若 S < T 返回值 < 0
int StrCompare(SString S, SString T)
{
    for (int i = 1, j = 1; i <= S.ch[0] && j <= T.ch[0]; i++, j++)
    {
        if (S.ch[i] != T.ch[j])
            return S.ch[i] - T.ch[j];
    }
    return S.ch[0] - T.ch[0];
}

// 求串长
int StrLength(SString S)
{
    return S.ch[0];
}

// 串联接
void Concat(SString &T, SString S1, SString S2)
{
    T.ch[0] = 0;
    for (int i = 1; i <= S1.ch[0]; i++)
    {
        T.ch[i] = S1.ch[i];
        T.ch[0]++;
    }
    for (int i = 1; i <= S2.ch[0]; i++)
    {
        T.ch[S1.ch[0] + i] = S2.ch[i];
        T.ch[0]++;
    }
}

// 求子串
void SubString(SString &Sub, SString S, int pos, int len)
{
    for (int i = 1; i <= len; i++)
        Sub.ch[i] = S.ch[pos + i - 1];
    Sub.ch[0] = len;
}

// 定位操作
int Index(SString S, SString T)
{
    SString Sub;
    int i = 1, n = StrLength(S), m = StrLength(T);
    while (i <= n - m + 1)
    {
        SubString(Sub, S, i, m);
        if (StrCompare(Sub, T) != 0)
            ++i;
        else
            return i;
    }
    return 0;
}

// 朴素模式匹配
int Index_simple(SString S, SString T)
{
    int i = 1, j = 1;
    while (i <= S.ch[0] && j <= T.ch[0])
    {
        if (S.ch[i] == T.ch[j])
        {
            ++i;
            ++j;
        }
        else
        {
            i = i - j + 2;
            j = 1;
        }
    }
    if (j > T.ch[0])
        return i - T.ch[0];
    else
        return 0;
}

int main()
{
    SString S, T;
    StrAssign(S, "EEKFXQWERTYUGEEKFX");
    StrAssign(T, "GEEKFX");
    printf("%d\n", Index_simple(S, T));
    return 0;
}