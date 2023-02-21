#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

void p10810()
{
	int N, M;
	scanf("%d %d", &N, &M);
	vector<int> basket(N);

	for (int i = 0; i < M; i++)
	{
		int start, end, num;
		scanf("%d %d %d", &start, &end, &num);
		for (int j = start; j <= end; j++)
			basket[j - 1] = num;
	}

	for (auto& ball : basket) printf("%d ", ball);
}