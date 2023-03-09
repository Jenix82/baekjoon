#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

int main()
{
	int N, M, val, ans = 0;
	scanf("%d %d", &N, &M);
	val = ceil(9 * M / 10.0);
	vector<int> h(N, 0);
	map<int, int> save;
	for (auto& a : h) scanf("%d", &a);

	for (int i = 0; i < M; i++)
	{
		save[h[i]]++;
		if (save[h[i]] >= val) ans = 1;
	}

	for (int i = M; i < N; i++)
	{
		save[h[i - M]]--;
		save[h[i]]++;
		if (save[h[i]] >= val) ans = 1;
	}
	printf((ans == 1) ? "YES" : "NO");
}