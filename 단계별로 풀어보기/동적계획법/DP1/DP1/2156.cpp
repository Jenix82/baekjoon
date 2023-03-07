#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void p2156()
{
	int N;
	scanf("%d", &N);
	vector<int> wine(N+1, 0);
	vector<int> DP(N+1, 0);
	for (int i = 1; i <= N; i++) scanf("%d", &wine[i]);

	DP[1] = wine[1];
	DP[2] = DP[1] + wine[2];
	for (int i = 3; i <= N; i++)
	{
		DP[i] = max(DP[i - 3] + wine[i - 1] + wine[i], DP[i - 2] + wine[i]);
		DP[i] = max(DP[i - 1], DP[i]);
	}

	printf("%d\n", DP.back());
}