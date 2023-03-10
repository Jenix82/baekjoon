#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void p11054()
{
	int N;
	scanf("%d", &N);
	vector<int> A(N, 0);
	for (auto& a : A) scanf("%d", &a);

	vector<int> length1(N, 1);
	vector<int> length2(N, 1);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < i; j++)
			if (A[j] < A[i])
				length1[i] = max(length1[i], length1[j] + 1);

	for (int i = N - 1; i >= 0; i--)
		for (int j = N - 1; j > i; j--)
			if (A[j] < A[i])
				length2[i] = max(length2[i], length2[j] + 1);
	
	int M = 0;
	for (int i = 0; i < N; i++)
		M = max(M, length1[i] + length2[i] - 1);

	printf("%d\n", M);
}