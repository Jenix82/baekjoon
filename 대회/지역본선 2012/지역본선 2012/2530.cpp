#define _CRT_SECURE_NO_WARNINGS
#include "problems.h"

#include <iostream>

void p2530()
{
	int h, m, s;
	int time;
	scanf("%d %d %d", &h, &m, &s);
	scanf("%d", &time);

	s += time;
	m += s / 60;
	s %= 60;
	h += m / 60;
	m %= 60;
	h %= 24;

	printf("%d %d %d\n", h, m, s);
}