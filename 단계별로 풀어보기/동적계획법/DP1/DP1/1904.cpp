#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
using namespace std;

int f1904[1000001] = { 0, };

int fibo1904(int n)
{
    if (n <= 3) return n;
    if (f1904[n] != 0) return f1904[n];
    return f1904[n] = (fibo1904(n - 1) + fibo1904(n - 2)) % 15746;
}

void p1904()
{
    int N;
    scanf("%d", &N);
    printf("%d\n", fibo1904(N));
}