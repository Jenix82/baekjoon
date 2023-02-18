#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <map>
using namespace std;

void p10815()
{
	int N, M;
	scanf("%d", &N);
	map<int, int> card; 
	vector<int> belong;

	for (int i = 0; i < N; i++)
	{
		int tmp;
		scanf("%d", &tmp);
		card[tmp] = 1;
	}

	scanf("%d", &M);
	belong.resize(M, 0);
	
	for (int i = 0; i < M; i++)
	{
		int tmp;
		scanf("%d", &tmp);
		belong[i] = card[tmp];
	}

	for (auto& b : belong) printf("%d ", b);
}