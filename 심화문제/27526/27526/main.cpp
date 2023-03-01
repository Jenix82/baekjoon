#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<vector<int>> slide;

void printSlide()
{
	for (int i = 0; i < N; i++)\
	{
		for (int j = 0; j < M; j++)
			if (slide[i][j] == N * M) printf("#");
			else printf("%d", slide[i][j]);
		printf("\n");
	}
}

int main()
{
	scanf("%d %d", &N, &M);
	slide.resize(N, vector<int>(M, 0));

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			slide[i-1][j-1] = (i - 1) * M + j;

	int count = 1;
	for (int i = 1; i <= N * M; i++) count *= i;

	for (int i = 0; i < count; i++)
	{
		printSlide();

	}
}