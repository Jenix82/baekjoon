#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void p9506()
{
	vector<string> answer;

	while (1)
	{
		int input;
		scanf("%d", &input);
		if (input == -1) break;

		vector<int> divisors;
		int sum = 0;
		for (int i = 1; i < input; i++)
			if (input % i == 0)
			{
				sum += i;
				divisors.push_back(i);
			}
		
		if (sum == input)
		{
			string tmp = to_string(input) + " = ";
			for (int i = 0; i < divisors.size() - 1; i++)
			{
				tmp += to_string(divisors[i]);
				tmp += " + ";
			}
			tmp += to_string(divisors.back());
			answer.push_back(tmp);
		}
		else
		{
			string tmp = to_string(input) + " is NOT perfect.";
			answer.push_back(tmp);
		}
	}

	for (auto& s : answer) cout << s << '\n';
}