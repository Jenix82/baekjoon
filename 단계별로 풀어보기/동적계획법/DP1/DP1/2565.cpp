#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

constexpr int M = 101;
struct line { int from, to; };
bool cmp(line A, line B)
{
	if (A.from == B.from) return A.to < B.to;
	else return A.from < B.from;
}

void p2565()
{
	int N, dp[M];
	line l[M];
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		dp[i] = 1;
		scanf("%d %d", &l[i].from, &l[i].to);
	}
	
	sort(l, l + N, cmp);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < i; j++)
			if (l[j].to < l[i].to)
				dp[i] = max(dp[i], dp[j] + 1);

	printf("%d\n", N - *max_element(dp, dp + N));
}