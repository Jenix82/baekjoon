#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

// Á» ¸ÚÀÖ°Ô Ç¬ µí?

void p11660()
{
	int N, M;
	scanf("%d %d", &N, &M);
	vector<vector<int>> seq(N+1, vector<int>(N+1, 0));
	vector<vector<int>> sum(N+1, vector<int>(N+1, 0));
	vector<int> ans(M, 0);

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
		{
			scanf("%d", &seq[i][j]);
			sum[i][j] = sum[i - 1][j] + sum[i][j - 1] + seq[i][j] - sum[i - 1][j - 1];
		}

	for (int i = 0; i < M; i++)
	{
		int x1, y1, x2, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		ans[i] = sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1];
	}

	for (auto& a : ans) printf("%d\n", a);
}