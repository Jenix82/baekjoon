#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmpStr(string& a, string& b)
{
	if (a.length() == b.length()) return a > b;
	return a.length() > b.length();
}

void p1181()
{
	int N;
	scanf("%d", &N);

	vector<string> words(N);
	for (int i = 0; i < N; i++)
	{
		string tmp;
		cin >> tmp;
		words[i] = tmp;
	}

	sort(words.rbegin(), words.rend(), cmpStr);
	words.erase(unique(words.begin(), words.end()), words.end());

	for (auto& w : words) cout << w << endl;
}

