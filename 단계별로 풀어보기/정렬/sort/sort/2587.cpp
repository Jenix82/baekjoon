#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

void p2587()
{
	vector<int> score(5);
	for (int i = 0; i < 5; i++)
		scanf("%d", &score[i]);

	sort(score.begin(), score.end());
	printf("%d\n%d", accumulate(score.begin(), score.end(), 0) / 5, score[2]);
}