#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void p2559()
{
	int N, K;
	scanf("%d %d", &N, &K);
	vector<int> seq(N), sum(N, 0);

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &seq[i]);
		if (i == 0) sum[i] = seq[i];
		else sum[i] = seq[i] + sum[i - 1];
	}

	int M = sum[K-1];
	for (int i = K; i < N; i++)
		M = max(M, sum[i] - sum[i - K]);

	printf("%d\n", M);
}