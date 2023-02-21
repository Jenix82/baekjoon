#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void p10798()
{
	vector<string> BB(5);
	int M = 0;

	for (int i = 0; i < 5; i++)
	{
		cin >> BB[i];
		M = max(M, (int)BB[i].length());
	}

	for (int i = 0; i < M; i++)
		for (int j = 0; j < 5; j++)
		{
			if (i >= BB[j].length()) continue;
			cout << BB[j][i];
		}
}