#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool inline isPrime(unsigned int n)
{
	if (n == 2) return true;
	if (n % 2 == 0) return false;

	unsigned int c = ceil(sqrt(n));
	for (unsigned int i = 2; i <= c; i++)
		if (n % i == 0) return false;

	return true;
}

void p4134()
{
	int N;
	scanf("%d", &N);
	vector<unsigned int> ans(N);
	for (int i = 0; i < N; i++)
	{
		unsigned int tmp;
		scanf("%u", &tmp);

		for (unsigned int n = tmp;; n++)
		{
			if (n <= 2)
			{
				ans[i] = 2;
				break;
			}
			
			if (isPrime(n))
			{
				ans[i] = n;
				break;
			}
		}
	}
	for (auto& p : ans) printf("%u\n", p);
}