#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <vector> 
#include <utility>
#include <algorithm>
using namespace std;

int main()
{
	int N, M, count = 1;
	vector<vector<int>> slide;
	vector<int*> ptr;

	scanf("%d %d", &N, &M);
	slide.resize(N, vector<int>(M, 0));
	ptr.resize(N * M, nullptr);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			slide[i][j] = i * M + j + 1;
		for (int j = 0; j < M; j++)
			ptr[i * M + j] = (i % 2 == 0) ? &slide[i][j] : &slide[i][M - 1 - j];
	}	

	for (int i = 1; i <= N * M; i++) count *= i;

	vector<vector<int>> save(max(4, N * M + 1), vector<int>(0, 0));
	save[2].emplace_back(0);
	save[3].emplace_back(1);
	save[3].emplace_back(0);

	for (int i = 4; i <= N * M; i++)
	{
		int idx = 0;
		save[i].resize(save[i - 1].size() * i, 0);

		for (int j = 0; j < save[i - 1].size();)
		{
			for (int k = i - 2; k >= 0; k--) save[i][idx++] = k;
			save[i][idx++] = save[i - 1][j++] + 1;
			for (int k = 0; k <= i - 2; k++) save[i][idx++] = k;
			save[i][idx++] = save[i - 1][j++];
		}
	}

	for (int i = 0; i < count; i++)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
				if (slide[i][j] == N * M) printf("#");
				else printf("%d", slide[i][j]);
			printf("\n");
		}

		int cur = save[N * M][i % save[N * M].size()];
		swap(*ptr[cur], *ptr[cur++]);
	}
}