#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

void p1764()
{
	int N, M;
	scanf("%d %d", &N, &M);
	map<string, int> noHeard;
	vector<string> inter;

	for (int i = 0; i < N; i++)
	{
		string tmp;
		cin >> tmp;
		noHeard[tmp]++;
	}

	for (int i = 0; i < M; i++)
	{
		string tmp;
		cin >> tmp;
		if (noHeard[tmp]) inter.push_back(tmp);
	}

	sort(inter.begin(), inter.end());

	printf("%zd\n", inter.size());
	for (auto& i : inter) cout << i << '\n';
}