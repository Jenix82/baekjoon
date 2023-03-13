#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

constexpr int M = 1000001;

void p17103()
{
	int N;
	scanf("%d", &N);

	bool prime[M] = { false, };
	prime[1] = true;
	for (int i = 2; i <= M; i++)
		if (!prime[i])
			for (int j = 2 * i; j <= M; j += i)
				prime[j] = true;

	for (int i = 0; i < N; i++)
	{
		int T, count = 0;
		scanf("%d", &T);
		if (T == 4) count = 1;
		else
			for (int j = 3; j <= T / 2; j += 2)
				if (!prime[j] && !prime[T - j])
					count++;
		printf("%d\n", count);
	}
}