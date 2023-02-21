#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

void p11478()
{
	string s;
	cin >> s;
	map<string, int> save;
	int count = 0;

	for (int i = 0; i < s.length(); i++)
		for (int l = 1; l <= s.length(); l++)
		{
			if (i + l > s.length()) continue;
			save[s.substr(i, l)]++;
			if (save[s.substr(i, l)] == 1) count++;
			//cout << s.substr(i, l) << "\tlength: " << s.substr(i, l).length() << '\n';
		}
	printf("%d\n", count);
}