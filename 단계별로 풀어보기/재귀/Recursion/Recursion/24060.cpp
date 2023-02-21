#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// ?????

void merge(vector<int>& A, int p, int q, int r)
{
	vector<int> tmp;
	int i = p;
	int j = q;
	int t = 0;

	while (i <= q && j <= r)
	{
		if (A[i] <= A[j]) tmp.push_back(A[i++]);
		else tmp.push_back(A[j++]);
	}

	while (i <= q) tmp.push_back(A[i++]);
	while (j <= r) tmp.push_back(A[j++]);
	
	i = p;
	t = 0;

	while (i <= r) A[i++] = tmp[t++];

	for (auto a : A) printf("%d ", a);
	printf("\n");
}

void merge_sort(vector<int>& A, int p, int r)
{
	if (p < r)
	{
		int q = floor((p + r) / (double)2);
		merge_sort(A, p, q);
		merge_sort(A, q + 1, r);
		merge(A, p, q, r);
	}
}

void p24060()
{
	int A, K;
	scanf("%d %d", &A, &K);
	vector<int> v(A);
	for (int i = 0; i < A; i++) scanf("%d", &v[i]);

	merge_sort(v, 0, A - 1);
	for (auto a : v) printf("%d ", a);
	printf("\n");
}