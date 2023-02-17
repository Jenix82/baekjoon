#define _CRT_SECURE_NO_WARNINGS
#include "problems.h"

#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> getRange(vector<vector<int>> ladder, int t)
{

}

void p2529()
{
	int N, L;
	scanf("%d %d", &N, &L);
	vector<vector<int>> ladder(N, vector<int>(2, 0));

	for (int i = 0; i < N; i++)
		scanf("%d %d", &ladder[i][0], &ladder[i][1]);


}