#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

void p11659()
{
	int N, M;
	scanf("%d %d", &N, &M);
	vector<int> seq(N), sum(N, 0);
	vector<int> ans(M, 0);

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &seq[i]);
		if (i == 0) sum[i] = seq[i];
		else sum[i] = seq[i] + sum[i - 1];
	}

	for (int i = 0; i < M; i++)
	{
		int s, e;
		scanf("%d %d", &s, &e);
		if (s == 1) ans[i] = sum[e - 1];
		else ans[i] = sum[e - 1] - sum[s - 2];
	}

	for (auto& a : ans) printf("%d\n", a);
}