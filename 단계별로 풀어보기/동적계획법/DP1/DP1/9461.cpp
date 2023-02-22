#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <vector>
using namespace std;

long long s9461[101] = { 0, };

long long f9461(int n)
{
    if (n <= 3) return 1;
    if (s9461[n] != 0) return s9461[n];
    return s9461[n] = (f9461(n - 2) + f9461(n - 3));
}

void p9461()
{
    int T;
    scanf("%d", &T);
    vector<long long> answer(T);

    for (int i = 0; i < T; i++)
    {
        int N;
        scanf("%d", &N);
        answer[i] = f9461(N);
    }
    
    for (auto& ans : answer) printf("%lld\n", ans);
}