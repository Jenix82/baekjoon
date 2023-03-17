#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct meeting { int start, end; };

bool cmp(meeting& A, meeting& B)
{
	if (A.end == B.end) return A.start < B.start;
	return A.end < B.end;
}

void p1931()
{
	int N;
	scanf("%d", &N);
	vector<meeting> m(N);

	for (int i = 0; i < N; i++)
		scanf("%d %d", &m[i].start, &m[i].end);

	sort(m.begin(), m.end(), cmp);

	int last = -1, count = 0;
	for (int i = 0; i < N; i++)
		if (last <= m[i].start)
		{
			count++;
			last = m[i].end;
		}
	
	printf("%d\n", count);
}
