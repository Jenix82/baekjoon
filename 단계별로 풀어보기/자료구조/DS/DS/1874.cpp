#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void p1874()
{
	int N;
	stack<int> A, B; 
	vector<char> pm;
	scanf("%d", &N);
	vector<int> in(N);

	B.push(0);
	for (int i = 0; i < N; i++) A.push(N - i);
	for (int i = 0; i < N; i++) scanf("%d", &in[i]);

	for (int i = 0; i < N; i++)
	{
		if (B.top() > in[i])
		{
			pm.clear();
			break;
		}

		while (B.top() != in[i])
		{
			B.push(A.top());
			A.pop();
			pm.emplace_back('+');
		}

		B.pop();
		pm.emplace_back('-');
	}

	if (pm.empty()) printf("NO\n");
	else for (auto& c : pm) printf("%c\n", c);
}