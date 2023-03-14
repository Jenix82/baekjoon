#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
int w[10000001], v[10000001], dp[10000001];

void p12865()
{
	int N, K;
	scanf("%d %d", &N, &K);

	for (int i = 1; i <= N; i++)
		scanf("%d %d", &w[i], &v[i]); 

	for (int i = 1; i <= N; i++)
		for (int j = K; j > 0; j--)
			if (w[i] <= j)
				dp[j] = std::max(dp[j], dp[j - w[i]] + v[i]); 
	
	printf("%d\n", dp[K]);
}