#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

void p10844()
{
	int N;
	scanf("%d", &N);
	
	vector<map<int, long long int>> dp(2);

	for (int i = 1; i <= N; i++)
	{
		if (i == 1)
			for (int j = 1; j <= 9; j++)
				dp[0][j]++;
		else
		{
			int cur = 1 - i % 2, pre = 1 - cur;

			for (int j = 0; j <= 9; j++)
				dp[cur][j] = 0;

			dp[cur][0] = dp[pre][1] % 1000000000;
			for (int j = 1; j <= 8; j++)
				dp[cur][j] = (dp[pre][j - 1] + dp[pre][j + 1]) % 1000000000;
			dp[cur][9] = dp[pre][8] % 1000000000;
		}
	}

	long long int count = 0;
	for (int i = 0; i <= 9; i++) count += dp[1 - N % 2][i] % 1000000000;
	printf("%lld\n", count % 1000000000);
}