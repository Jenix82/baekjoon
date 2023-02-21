#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
using namespace std;

void p2444()
{
	int N;
	scanf("%d", &N);

	for (int i = 1; i < 2 * N; i++)
	{
		for (int j = 1; j < 2 * N; j++)
			if (abs(i - N) + abs(j - N) < N) printf("*");
			else if (j < N) printf(" ");
			else break;
		printf("\n");
	}
}