#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void p1149()
{
	int N;
	scanf("%d", &N);
	vector<vector<int>> RGB(N, vector<int>(3, 0));

	for (int i = 0; i < N; i++)
	{
		scanf("%d %d %d", &RGB[i][0], &RGB[i][1], &RGB[i][2]);

		if (i == 0) continue;

		RGB[i][0] += min(RGB[i - 1][1], RGB[i - 1][2]);
		RGB[i][1] += min(RGB[i - 1][0], RGB[i - 1][2]);
		RGB[i][2] += min(RGB[i - 1][0], RGB[i - 1][1]);
	}

	printf("%d\n", min(min(RGB.back()[0], RGB.back()[1]), RGB.back()[2]));
}