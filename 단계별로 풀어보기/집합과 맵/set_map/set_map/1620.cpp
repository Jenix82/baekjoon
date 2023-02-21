#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

void p1620()
{
	int N, M;
	scanf("%d %d", &N, &M);
	map<string, int> pokemon;
	map<int, string> number;
	vector<string> ans(M);

	for (int i = 1; i <= N; i++)
	{
		string tmp;
		cin >> tmp;
		pokemon[tmp] = i;
		number[i] = tmp;
	}

	for (int i = 0; i < M; i++)
	{
		string tmp;
		cin >> tmp;
		if (atoi(tmp.c_str()) != 0) ans[i] = number[stoi(tmp)];
		else ans[i] = to_string(pokemon[tmp]);
	}

	for (auto& out : ans) cout << out << '\n';
}