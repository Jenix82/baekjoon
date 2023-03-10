#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <map>
using namespace std;

void p17386()
{
	int answer;
	double x, y;

	long long int x1, y1, x2, y2, x3, y3, x4, y4;
	scanf("%lld %lld %lld %lld", &x1, &y1, &x2, &y2);
	scanf("%lld %lld %lld %lld", &x3, &y3, &x4, &y4); 

	long long int A = y2 - y1;
	long long int B = x1 - x2;
	long long int E = x2 * y1 - x1 * y2;

	long long int C = y4 - y3;
	long long int D = x3 - x4;
	long long int F = x4 * y3 - x3 * y4;
	
	long long int deno = A * D - B * C;
	if (deno != 0)
	{
		x = (B * F - E * D) / (double)deno;
		y = (E * C - A * F) / (double)deno;

		bool case1 = x1 <= x && x <= x2;
		bool case2 = x2 <= x && x <= x1;
		bool case3 = x3 <= x && x <= x4;
		bool case4 = x4 <= x && x <= x3;

		if (case1 && case3) answer = 1;
		else if (case1 && case4) answer = 1;
		else if (case2 && case3) answer = 1;
		else if (case2 && case4) answer = 1;
		else answer = 0;

		if (answer == 1)
		{
			if ((B * F - E * D) % deno == 0 && (E * C - A * F) % deno == 0) printf("%d\n%d %d\n", answer, (B * F - E * D) / deno, (E * C - A * F) / deno);
			if ((B * F - E * D) % deno == 0 && (E * C - A * F) % deno != 0) printf("%d\n%d %f\n", answer, (B * F - E * D) / deno, (E * C - A * F) / (double)deno);
			if ((B * F - E * D) % deno != 0 && (E * C - A * F) % deno == 0) printf("%d\n%f %d\n", answer, (B * F - E * D) / (double)deno, (E * C - A * F) / deno);
			if ((B * F - E * D) % deno != 0 && (E * C - A * F) % deno != 0) printf("%d\n%f %f\n", answer, (B * F - E * D) / (double)deno, (E * C - A * F) / (double)deno);
		}
		else printf("%d\n", answer);
	}
	else
	{
		if (A * x3 + B * y3 + E == 0)
		{
			map<long long int, int> srt;
			srt[x1]++;
			srt[x2]++;
			srt[x3]++;
			srt[x4]++;

			if (srt.size() == 4)
			{
				answer = 0;
				printf("%d\n", answer);
			}
			else
			{
				answer = 1;
				if (x1 == x3) printf("%d\n%d %d\n", answer, x1, y1);
				if (x1 == x4) printf("%d\n%d %d\n", answer, x1, y1);
				if (x2 == x3) printf("%d\n%d %d\n", answer, x2, y2);
				if (x2 == x4) printf("%d\n%d %d\n", answer, x2, y2);
			}
		}
		else
		{
			answer = 0;
			printf("%d\n", answer);
		}
	}
}