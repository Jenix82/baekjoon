#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void p1932()
{
	int N;
	scanf("%d", &N);
	vector<vector<int>> save(N, vector<int>(N, 0));

	for (int i = 0; i < N; i++)
		for (int j = 0; j <= i; j++)
		{
			scanf("%d", &save[i][j]);

			if (i == 0) continue;
			if (j == 0) save[i][j] += save[i - 1][j];
			if (j == i) save[i][j] += save[i - 1][j - 1];
			if (j == 0 || j == i) continue;
			save[i][j] += max(save[i - 1][j - 1], save[i - 1][j]);
		}

	int M = save.back().front();
	for (int i = 1; i < N; i++)
		M = max(M, save.back()[i]);

	printf("%d\n", M);
}