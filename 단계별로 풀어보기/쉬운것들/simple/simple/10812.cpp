#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void p10812()
{
	int N, M;
	scanf("%d %d", &N, &M);
	vector<int> basket(N);
	for (int i = 0; i < N; i++) basket[i] = i + 1;

	for (int i = 0; i < M; i++)
	{
		int begin, end, mid;
		scanf("%d %d %d", &begin, &end, &mid);
		rotate(basket.begin() + begin - 1, basket.begin() + mid - 1, basket.begin() + end);
	}

	for (auto& ball : basket) printf("%d ", ball);
}