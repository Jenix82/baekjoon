#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void merge(vector<int>& A, int p, int q, int r)
{
	vector<int> tmp(r - p);
	int i = p;
	int j = q;
	int t = 0;

	while (i <= q && j <= r)
	{
		if (A[i] <= A[j]) tmp[t++] = A[i++];
		else tmp[i++] = A[j++];
	}

	while (i <= q) tmp[t++] = A[i++];
	while (j <= r) tmp[i++] = A[j++];
	
	i = p;
	t = 0;

	while (i <= r) A[i++] = tmp[t++];
}

void merge_sort(vector<int>& A, int p, int r)
{
	if (p < r)
	{
		int q = floor((p + r) / (double)2);
		merge_sort(A, p, q);
		merge_sort(A, q + 1, r);
		merge(A, p, q, r);

		for (auto& i : A) printf("%d", i);
	}
}

void p24060()
{
	int A, K;
	scanf("%d %d", &A, &K);
	vector<int> v(A);
	for (auto i : v) scanf("%d", &i);

	merge_sort(v, 0, A - 1);
}