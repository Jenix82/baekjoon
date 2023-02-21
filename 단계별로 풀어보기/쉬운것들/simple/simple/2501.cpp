#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

void p2501()
{
	int N, K;
	scanf("%d %d", &N, &K);
	int count = 0, i = 1;

	for (; i <= N; i++)
	{
		if (N % i == 0) count++;
		if (count == K) break;
	}
	if (count < K) printf("0\n");
	else printf("%d\n", i);
}