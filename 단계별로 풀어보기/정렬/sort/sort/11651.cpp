#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compareY(pair<int, int>& a, pair<int, int>& b)
{
	if (a.second == b.second) return a.first > b.first;
	return a.second > b.second;
}

void p11651()
{
	int N;
	scanf("%d", &N);

	vector<pair<int, int>> pos(N);
	for (int i = 0; i < N; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		pos[i] = make_pair(x, y);
	}

	sort(pos.rbegin(), pos.rend(), compareY);

	for (auto& p : pos) printf("%d %d\n", p.first, p.second);
}

