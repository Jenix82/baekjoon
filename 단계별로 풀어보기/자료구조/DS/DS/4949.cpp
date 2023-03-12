#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

inline int check1(string& s)
{
	stack<char> Pt;
	for (auto& c : s)
	{
		if (c != '(' && c != ')' &&
			c != '[' && c != ']') continue;

		if (c == '(') Pt.push(c);
		else if (c == ')')
		{
			if (Pt.empty()) return 0;
			if (Pt.top() != '(') return 0;
			Pt.pop();
		}

		if (c == '[') Pt.push(c);
		else if (c == ']')
		{
			if (Pt.empty()) return 0;
			if (Pt.top() != '[') return 0;
			Pt.pop();
		}
	}
	if (Pt.empty()) return 1;
	else return 0;
}

void p4949()
{
	vector<int> ans;
	string str;
	while (1)
	{
		getline(cin, str); 
		if (str == ".") break;
		ans.emplace_back(check1(str));
	}

	for (auto a : ans) printf(a ? "yes\n" : "no\n");
}