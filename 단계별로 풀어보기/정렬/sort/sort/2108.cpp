#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <climits>
using namespace std;

bool cmpPair(pair<int, int>& p1, pair<int, int>& p2) {
	if (p1.second == p2.second) return p1.first < p2.first;
	return p1.second > p2.second;
}

void p2108()
{
	int N;
	scanf("%d", &N);
	
	vector<int> n(N);
	int M = -INT_MAX, m = INT_MAX;
	map<int, int> mp;
	
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &n[i]);
		M = max(M, n[i]);
		m = min(m, n[i]);
		mp[n[i]]++;
	}

	vector<pair<int, int>> v(mp.begin(), mp.end());

	double avg = accumulate(n.begin(), n.end(), 0) / (double)N;
	if (avg > -0.5 && avg <= 0) avg = 0;
	sort(n.begin(), n.end());
	sort(v.begin(), v.end(), cmpPair);

	printf("%.0f\n", avg);
	printf("%d\n", n[(N - 1) / 2]);
	if (v.size() > 1) printf("%d\n", (v[0].second == v[1].second) ? v[1].first : v[0].first);
	else printf("%d\n", v[0].first);
	printf("%d\n", M - m);
}