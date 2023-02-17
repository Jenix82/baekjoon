#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, int>& a, pair<int, int>& b)
{
	if (a.first == b.first) return a.second > b.second;
	return a.first > b.first;
}

void p11650()
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

	sort(pos.begin(), pos.end());

	for (auto& p : pos) printf("%d %d\n", p.first, p.second);
}

