#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> answer;

vector<int> merge_sort(vector<int> A)
{
	if (A.size() <= 1) return A;

	int q = (A.size()-1) / 2;
	vector<int> left(A.begin(), A.begin() + q + 1);
	left = merge_sort(left);
	vector<int> right(A.begin() + q + 1, A.end());
	right = merge_sort(right);

	int i = 0, j = 0;
	vector<int> B;

	while (i < left.size() && j < right.size())
	{
		if (left[i] < right[j])
		{
			B.push_back(left[i++]);
			answer.push_back(B.back());
		}
		else
		{
			B.push_back(right[j++]);
			answer.push_back(B.back());
		}
	}
	while (i < left.size())
	{
		B.push_back(left[i++]);
		answer.push_back(B.back());
	}
	while (j < right.size())
	{
		B.push_back(right[j++]);
		answer.push_back(B.back());
	}

	return B;
}

void p24060()
{
	int A, K;
	scanf("%d %d", &A, &K);
	vector<int> v(A);
	for (int i = 0; i < A; i++) scanf("%d", &v[i]);

	merge_sort(v);
	if (answer.size() >= K) printf("%d\n", answer[K - 1]);
	else printf("-1\n");
}