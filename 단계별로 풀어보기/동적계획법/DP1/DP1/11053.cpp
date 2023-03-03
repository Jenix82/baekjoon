#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void p11053()
{
	int N;
	scanf("%d", &N);
	vector<int> A(N, 0);
	for (auto& a : A) scanf("%d", &a);

	vector<int> length(N, 1);
	int M = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < i; j++)
			if (A[j] < A[i])
				length[i] = max(length[i], length[j] + 1);
		M = max(M, length[i]);
	}
		
	printf("%d\n", M);
}