#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <map>
using namespace std;

void p1269()
{
	int N, M;
	scanf("%d %d", &N, &M);
	map<int, int> set;
	int count = 0;

	for (int i = 0; i < N; i++)
	{
		int tmp;
		scanf("%d", &tmp);
		set[tmp]++;
		count++;
	}

	for (int i = 0; i < M; i++)
	{
		int tmp;
		scanf("%d", &tmp);
		set[tmp]++;
		count = (set[tmp] == 2) ? count - 1 : count + 1;
	}

	printf("%d", count);
}