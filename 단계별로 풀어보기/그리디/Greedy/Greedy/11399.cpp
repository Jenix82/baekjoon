#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void p11399()
{
	int N, time = 0;
	scanf("%d", &N);
	vector<int> t(N);
	for (auto& i : t) scanf("%d", &i);
	sort(t.rbegin(), t.rend());
	for (int i = 0; i < N; i++) time += (i + 1) * t[i];
	printf("%d\n", time);
}