#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

void p10828()
{
	int N;
	stack<int> st;
	vector<int> ans; 
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		string cmd;
		cin >> cmd;

		if (cmd == "push")
		{
			int tmp;
			cin >> tmp;
			st.push(tmp);
		}
		if (cmd == "top")
			if (!st.empty()) ans.emplace_back(st.top());
			else ans.emplace_back(-1);
		if (cmd == "size")
			ans.emplace_back(st.size());
		if (cmd == "pop")
			if (!st.empty())
			{
				ans.emplace_back(st.top());
				st.pop();
			}
			else ans.emplace_back(-1);
		if (cmd == "empty")
			ans.emplace_back(st.empty());
	}

	for (auto& a : ans) printf("%d\n", a);
}