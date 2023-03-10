#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define int		long long
#define double	long double

void p17386()
{
	int x1, y1, x2, y2, x3, y3, x4, y4;
	scanf("%lld %lld %lld %lld", &x1, &y1, &x2, &y2);
	scanf("%lld %lld %lld %lld", &x3, &y3, &x4, &y4);

	int A = y2 - y1, B = x2 - x1, C = y4 - y3, D = x4 - x3;
	double d1 = A * (x3 - x1) - B * (y3 - y1);
	double d2 = A * (x4 - x1) - B * (y4 - y1);
	double d3 = C * (x1 - x3) - D * (y1 - y3);
	double d4 = C * (x2 - x3) - D * (y2 - y3);

	printf((d1 * d2 <= 0 && d3 * d4 <= 0) ? "1\n" : "0\n");
}