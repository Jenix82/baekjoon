#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void p2579()
{
	int N;
	scanf("%d", &N);
	vector<int> stair(N, 0);
	for (auto& s : stair) scanf("%d", &s);

	int a, b, c, d;
	for (int i = 1; i < N; i++)
		if (i == 1)
		{
			a = stair[i];
			b = a + stair[i - 1];
		}
		else
		{
			c = stair[i - 2] + stair[i];
			d = a + stair[i];

			stair[i - 1] = max(a, b);

			a = c;
			b = d;
		}
	
	printf("%d\n", (N == 1) ? stair.front() : max(a, b));
}