#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void p1463()
{
	int N;
	scanf("%d", &N);
	vector<int> save(N + 1, 1000001);
	save[N] = 0;

	for (int i = N; i > 0; i--)
	{
		if (i % 3 == 0) save[i / 3] = min(save[i] + 1, save[i / 3]);
		if (i % 2 == 0) save[i / 2] = min(save[i] + 1, save[i / 2]);
		save[i - 1] = min(save[i] + 1, save[i - 1]);
	}
	printf("%d\n", save[1]);
}