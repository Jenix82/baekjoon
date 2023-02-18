#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <map>
using namespace std;

void p14425()
{
	int N, M;
	scanf("%d %d", &N, &M);
	map<string, int> set;

	for (int i = 0; i < N; i++)
	{
		string tmp;
		cin >> tmp;
		set[tmp] = 1;
	}

	int count = 0;
	for (int i = 0; i < M; i++)
	{
		string tmp;
		cin >> tmp;
		count += set[tmp];
	}
	
	printf("%d", count);
}