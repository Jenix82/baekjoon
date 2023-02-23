#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void p1912()
{
	int N, M, ansM;
	scanf("%d", &N);
	vector<int> save(N); 

	for (int i = 0; i < N; i++)
	{
		if (i == 0)
		{
			scanf("%d", &save[i]);
			M = save[i];
			ansM = M;
		}
		else
		{
			int tmp;
			scanf("%d", &tmp);
			M = max(tmp, M + tmp);
			save[i] = M;
			ansM = max(ansM, M);
		}
	}
		
	printf("%d\n", ansM);
}