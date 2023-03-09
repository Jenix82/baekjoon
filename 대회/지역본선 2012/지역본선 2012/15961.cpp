#define _CRT_SECURE_NO_WARNINGS
#include "problems.h"

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void p15961()
{
	int N, d, k, c;
	scanf("%d %d %d %d", &N, &d, &k, &c);

	vector<int> sushi;
	vector<int> number;
	sushi.resize(N, 0);
	number.resize(d + 1, 0);

	for (int i = 0; i < N; i++)
		scanf("%d", &sushi[i]);

	for (int i = 0; i < k - 1; i++)
		sushi.push_back(sushi[i]);

	int count = 1;
	for (int i = 0; i < k; i++)
	{
		number[sushi[i]]++;
		if (number[sushi[i]] == 1) count++;
	}

	if (number[c] > 0) count--;

	for (int j = 1; j <= d; j++)
		printf("%d ", number[j]);
	printf(": %d\n", count);

	if (count == k + 1)
	{
		printf("%d\n", count);
		return;
	}

	int M = count;
	for (int i = 0; i < N - 1; i++)
	{
		number[sushi[i]]--;
		if (number[sushi[i]] == 0 && sushi[i] != c) count--;

		number[sushi[i+k]]++;
		if (number[sushi[i+k]] == 1 && sushi[i+k] != c) count++;

		if (M < count) M = count;
		if (M == k + 1) break;
	}

	printf("%d\n", M);
}