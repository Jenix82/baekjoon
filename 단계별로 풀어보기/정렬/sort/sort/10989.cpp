#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

void p10989()
{
	int N;
	scanf("%d", &N);
	map<int, int> count;
	int M = 0;

	for (int i = 0; i < N; i++)
	{
		int tmp;
		scanf("%d", &tmp);
		count[tmp]++;

		M = max(M, tmp);
	}

	for (int i = 1; i <= M; i++)
		for (int j = 0; j < count[i]; j++)
			printf("%d\n", i);
}

