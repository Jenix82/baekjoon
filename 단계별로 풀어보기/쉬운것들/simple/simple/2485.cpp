#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

inline int gcd2485(int a, int b)
{
	if (a < b) swap(a, b);
	if (b == 0) return a;
	return gcd2485(b, a % b);
}

void p2485()
{
	int N, m = 1000000001, M = 0, d;
	scanf("%d", &N);
	vector<int> lamp(N);

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &lamp[i]);
		m = min(m, lamp[i]);
		M = max(M, lamp[i]);
	}
	for (auto& h : lamp) h -= m;

	d = gcd2485(lamp[0], lamp[1]);
	for (int i = 2; i < N; i++) d = gcd2485(d, lamp[i]);

	printf("%d\n", (M - m) / d - N + 1);
}