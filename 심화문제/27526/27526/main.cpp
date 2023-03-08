#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <vector>
#include <utility>
#include <map>
using namespace std;

int N, M;
vector<vector<int>> slide;
vector<int*> ptr;

inline void run(int i)
{
	int n = N * M;
	if (i % n == 0)
	{
		if ((i / n) % 2 == 0) swap(*ptr[0], *ptr[1]);
		else swap(*ptr[n - 1], *ptr[n - 2]);
	}
	else
	{
		int r = i % n;
		if ((i / n) % 2 == 0) swap(*ptr[n - r], *ptr[n - r - 1]);
		else swap(*ptr[r], *ptr[r - 1]);
	}
}

int main()
{
	scanf("%d %d", &N, &M);
	slide.resize(N, vector<int>(M, 0));
	ptr.resize(N * M, nullptr);
	map<vector<vector<int>>, int> check;

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			slide[i-1][j-1] = (i - 1) * M + j;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			ptr[i * M + j] = (i % 2 == 0) ? &slide[i][j] : &slide[i][M - 1 - j];

	int count = 1;
	for (int i = 1; i <= N * M; i++) count *= i;

	for (int i = 0; i < count; i++)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
				if (slide[i][j] == N * M) printf("#");
				else printf("%d", slide[i][j]);
			printf("\n");
		}
		check[slide]++;
		run(i);
	}
	printf("%d / %zd\n", count, check.size());
}