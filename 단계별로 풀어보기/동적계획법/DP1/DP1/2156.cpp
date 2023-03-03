#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void p2156()
{
	int N;
	scanf("%d", &N);
	vector<int> wine(N, 0);
	for (auto& s : wine) scanf("%d", &s);

	int a, b, c, d, M = wine[0];
	for (int i = 1; i < N; i++)
	{
		if (i == 1)
		{
			a = wine[i];
			b = a + wine[i - 1];
		}
		else
		{
			c = wine[i - 2] + wine[i];
			d = a + wine[i];

			wine[i - 1] = max(a, b);
			M = max(M, wine[i - 1]);

			a = c;
			b = d;
		}
	}

	printf("%d\n", (N == 1) ? wine.front() : max(M, max(a, b)));
}