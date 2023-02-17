#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void p1427()
{
	int N;
	scanf("%d", &N);

	vector<int> digit;
	while (N > 0)
	{
		digit.push_back(N % 10);
		N /= 10;
	}

	sort(digit.rbegin(), digit.rend());
	for (auto& d : digit) printf("%d", d);
}