#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#define int	long long int
using namespace std;

inline int gcd13241(int a, int b)
{
	if (b == 0) return a;
	return gcd13241(b, a % b);
}

void p13241()
{
	int N, M;
	scanf("%lld %lld", &N, &M);
	printf("%lld", N * M / gcd13241(max(N, M), min(N, M)));
}