#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

inline bool check(string& s)
{
	stack<char> Pt;
	for (auto& c : s)
	{
		if (c == '(') Pt.push(c);
		else
		{
			if (Pt.empty()) return false;
			if (Pt.top() == ')') return false;
			Pt.pop();
		}
	}
	if (Pt.empty()) return true;
	else return false;
}

void p9012()
{
	int N;
	vector<string> ans;
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		string PS;
		cin >> PS;
		ans.emplace_back(check(PS) ? "YES" : "NO");
	}

	for (auto& a : ans) cout << a << '\n';
}