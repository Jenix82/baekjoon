#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

void p11047()
{
	int value[10], N, K, coin = 0;
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++) scanf("%d", &value[i]);

	for (int i = N - 1; i >= 0; i--)
	{
		coin += K / value[i];
		K %= value[i];
	}
	printf("%d\n", coin);
}
