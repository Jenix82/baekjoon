#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <vector>
using namespace std;

int f[40] = { 0, };

void fibonacci()
{
    f[0] = 1;
    f[1] = 2;
    for (int i = 2; i < 40; i++)
        f[i] = f[i - 1] + f[i - 2];
}

void p24416()
{
    int N;
    scanf("%d", &N);
    fibonacci();
    printf("%d %d\n", f[N - 2], N - 2);
}