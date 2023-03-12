#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>
using namespace std;

void p10773()
{
	stack<int> docu;
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		int tmp;
		scanf("%d", &tmp);
		if (tmp != 0) docu.push(tmp);
		else docu.pop();
	}

	int sum = 0;
	while (!docu.empty())
	{
		sum += docu.top();
		docu.pop();
	}

	printf("%d\n", sum);
}