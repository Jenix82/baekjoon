#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

inline int gcd1735(int a, int b)
{
	if (b == 0) return a;
	return gcd1735(b, a % b);
}

void p1735()
{
	int A1, B1, A2, B2;
	scanf("%d %d", &A1, &B1);
	scanf("%d %d", &A2, &B2);
	int gcd = gcd1735(max(A1 * B2 + A2 * B1, B1 * B2), min(A1 * B2 + A2 * B1, B1 * B2));
	printf("%d %d", (A1 * B2 + A2 * B1) / gcd, B1 * B2 / gcd);
}