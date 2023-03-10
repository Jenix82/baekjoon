#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <stdlib.h>
#define int long long
using namespace std;

void p20149()
{
	int answer = 0;
	double x, y;

	int x1, y1, x2, y2, x3, y3, x4, y4;
	scanf("%lld %lld %lld %lld", &x1, &y1, &x2, &y2);
	scanf("%lld %lld %lld %lld", &x3, &y3, &x4, &y4);

	int A = y2 - y1;
	int B = x1 - x2;
	int E = x2 * y1 - x1 * y2;

	int C = y4 - y3;
	int D = x3 - x4;
	int F = x4 * y3 - x3 * y4;

	int deno = A * D - B * C;

	if (abs(x1 - x2) + abs(y1 - y2) == 0) printf("0\n");
	else if (abs(x3 - x4) + abs(y3 - y4) == 0) printf("0\n");
	else if (deno != 0)
	{
		x = (B * F - E * D) / (double)deno;
		y = (E * C - A * F) / (double)deno;

		double t1 = (x - x1) / (x2 - x1);
		double t2 = (x - x3) / (x4 - x3);

		if (t1 >= 0 && t1 <= 1 && t2 >= 0 && t2 <= 1)
		{
			if (x - (int)x == 0 && y - (int)y == 0) printf("1\n%lld %lld\n", (int)x, (int)y);
			if (x - (int)x == 0 && y - (int)y != 0) printf("1\n%lld %.16f\n", (int)x, y);
			if (x - (int)x != 0 && y - (int)y == 0) printf("1\n%.16f %lld\n", x, (int)y);
			if (x - (int)x != 0 && y - (int)y != 0) printf("1\n%.16f %.16f\n", x, y);
		}
		else printf("0\n");
	}
	else
	{
		if (A * x3 + B * y3 + E == 0)
		{
			int d = max(x1, max(x2, max(x3, x4))) - min(x1, min(x2, min(x3, x4)));
			int l1 = max(x1, x2) - min(x1, x2);
			int l2 = max(x3, x4) - min(x3, x4);

			if (d < l1 + l2) printf("1\n");
			else if (d > l1 + l2) printf("0\n");
			else
			{
				if (x1 == x3) printf("1\n%lld %lld\n", x1, y1);
				if (x1 == x4) printf("1\n%lld %lld\n", x1, y1);
				if (x2 == x3) printf("1\n%lld %lld\n", x2, y2);
				if (x2 == x4) printf("1\n%lld %lld\n", x2, y2);
			}
		}
		else printf("0\n");
	}
}