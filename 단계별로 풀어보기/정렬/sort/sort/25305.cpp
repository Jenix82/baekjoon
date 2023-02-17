#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void p25305()
{
	int N, k;
	scanf("%d %d", &N, &k);

	vector<int> score(N);
	for (int i = 0; i < N; i++) scanf("%d", &score[i]);

	sort(score.rbegin(), score.rend());
	printf("%d\n", score[k-1]);
}