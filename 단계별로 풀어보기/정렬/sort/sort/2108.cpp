#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <climits>
using namespace std;

// ¾ÆÁ÷ ¸ø Ç¯

bool compare(pair<int, int> p1, pair<int, int> p2) {
	if (p1.second == p2.second) return p1.first < p2.first;
	return p1.second > p2.second;
}

void p2108()
{
	int N;
	scanf("%d", &N);
	
	vector<int> n(N);
	int M = -INT_MAX, m = INT_MAX;
	vector<pair<int, int>> v(8001);
	for (int i = -4000; i <= 4000; i++)
		v[i + 4000] = make_pair(i, 0);

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &n[i]);
		M = max(M, n[i]);
		m = min(m, n[i]);
		v[n[i]+4000].second++;
	}

	sort(n.begin(), n.end());
	sort(v.begin(), v.end(), compare);

	printf("%d\n", accumulate(n.begin(), n.end(), 0) / N);
	printf("%d\n", n[N / 2 - 1]);
	printf("%d\n", (v[0].second == v[1].second) ? v[1].first : v[0].first);
	printf("%d\n", M - m);
}