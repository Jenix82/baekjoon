#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void p9251()
{
	string s1, s2;
	cin >> s1; 
	cin >> s2; 
	vector<vector<int>> lcs(s1.length() + 1, vector<int>(s2.length() + 1, 0));
	int M = 0;

	for (int i = 0; i <= s1.length(); i++)
		for (int j = 0; j <= s2.length(); j++)
		{
			if (i == 0 || j == 0) lcs[i][j] = 0;
			else if (s1[i - 1] == s2[j - 1]) lcs[i][j] = lcs[i - 1][j - 1] + 1;
			else lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);

			M = max(M, lcs[i][j]);
		}

	printf("%d\n", M); 
}