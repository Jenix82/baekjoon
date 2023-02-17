#define _CRT_SECURE_NO_WARNINGS
#include "problems.h"

#include <iostream>
#include <vector>
using namespace std;

void p2527()
{
	int x1, y1, p1, q1;
	int x2, y2, p2, q2;
	vector<string> answer;
	for (int i = 0; i < 4; i++)
	{
		scanf("%d %d %d %d %d %d %d %d", &x1, &y1, &p1, &q1, &x2, &y2, &p2, &q2);
		
		int dx = max(p1, p2) - min(x1, x2);
		int dy = max(q1, q2) - min(y1, y2);
		int sx = p1 - x1 + p2 - x2;
		int sy = q1 - y1 + q2 - y2;

		if (dx > sx || dy > sy) answer.push_back("d"); 
		else if (dx < sx)
		{
			if (dy < sy) answer.push_back("a"); 
			else answer.push_back("b");
		}
		else
		{
			if (dy < sy) answer.push_back("b");
			else answer.push_back("c");
		}
	}
	for (int i = 0; i < 4; i++)
		cout << answer[i] << '\n';
}