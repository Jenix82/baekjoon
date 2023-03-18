#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <map>
typedef long long ll;
using namespace std;

ll sum[1000001];
map<ll, ll> r;

void p10986()
{
	int N, M;
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++)
	{
		scanf("%lld", &sum[i]);
		sum[i] = (sum[i] + sum[i - 1]) % M;
		r[sum[i]]++;
	}

	ll count = r[0]; 
	for (int i = 0; i < M; i++)
		count += r[i] * (r[i] - 1) / 2;

	printf("%lld\n", count);
}