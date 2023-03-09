#define _CRT_SECURE_NO_WARNINGS
#include "problems.h"

#include <iostream>
#include <vector>
using namespace std;

void p2526()
{
	int N, P;
	scanf("%d %d", &N, &P);

	vector<int> r;
	r.resize(P, 0);

	int tmp = N;
	while (1)
	{
		tmp = (tmp * N) % P;
		r[tmp]++;
		if (r[tmp] == 3) break;
	}
	
	int count = 0;
	for (int i = 0; i < r.size(); i++)
		if (r[i] > 1) count++;
	printf("%d", count);
}