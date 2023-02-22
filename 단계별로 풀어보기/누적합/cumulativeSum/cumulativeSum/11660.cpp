#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

// ¾ÆÁ÷ ¸ø Ç¯

void p11660()
{
	int N, M;
	scanf("%d %d", &N, &M);
	vector<vector<int>> seq(N, vector<int>(N, 0));
	vector<int> sum(N * N, 0);
	vector<int> ans(M, 0);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &seq[i][j]);
			if (i + j == 0) sum[i * N + j] = seq[i][j];
			else sum[i * N + j] = sum[i * N + j - 1] + seq[i][j];
		}

	for (int i = 0; i < M; i++)
	{
		int x1, y1, x2, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		if (x1 * y1 == 1) ans[i] = sum[(x2 - 1) * N + (y2 - 1)];
		else ans[i] = sum[(x2 - 1) * N + (y2 - 1)] - sum[(x1 - 1) * N + (y1 - 1) - 1];
	}

	for (auto& a : ans) printf("%d\n", a);
}