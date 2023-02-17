#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

void p18870()
{
	int N;
	scanf("%d", &N);

	vector<int> coord(N), sorted;
	for (int i = 0; i < N; i++) scanf("%d", &coord[i]);
	sorted = coord;
	sort(sorted.begin(), sorted.end());

	vector<int> cmp(N);
	cmp[0] = 0;
	for (int i = 1; i < N; i++)
	{
		if (sorted[i] == sorted[i - 1]) cmp[i] = cmp[i - 1];
		else cmp[i] = cmp[i - 1] + 1;
	}

	map<int, int> rank;
	for (int i = 1; i < N; i++) rank[sorted[i]] = cmp[i];

	for (auto& c : coord) printf("%d ", rank[c]);
	printf("\n");
}