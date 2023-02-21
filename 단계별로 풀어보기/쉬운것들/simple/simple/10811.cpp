#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void p10811()
{
	int N, M;
	scanf("%d %d", &N, &M);
	vector<int> basket(N);
	for (int i = 0; i < N; i++) basket[i] = i + 1;

	for (int i = 0; i < M; i++)
	{
		int n1, n2;
		scanf("%d %d", &n1, &n2);
		reverse(basket.begin() + n1 - 1, basket.begin() + n2);
	}

	for (auto& ball : basket) printf("%d ", ball);
}