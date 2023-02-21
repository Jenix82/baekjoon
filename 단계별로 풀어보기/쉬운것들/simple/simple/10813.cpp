#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

void p10813()
{
	int N, M;
	scanf("%d %d", &N, &M);
	vector<int> basket(N);
	for (int i = 0; i < N; i++) basket[i] = i + 1;

	for (int i = 0; i < M; i++)
	{
		int n1, n2;
		scanf("%d %d", &n1, &n2);

		int tmp = basket[n2 - 1];
		basket[n2 - 1] = basket[n1 - 1];
		basket[n1 - 1] = tmp;
	}

	for (auto& ball : basket) printf("%d ", ball);
}