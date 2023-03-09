#define _CRT_SECURE_NO_WARNINGS
#include "problems.h"

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class student
{
public:
	student() {};
	student(int c, int s) : country(c), score(s) {};
	virtual ~student() {};
	bool operator>(const student& other) const
	{
		if (this->score > other.score)
			return true;
		else if (this->score < other.score)
			return false;

		return this->score < other.score;
	}
	void print()
	{
		printf("%d %d\n", country, number);
	}

	int country;
	int number;
	int score;
};

void p2535()
{
	int N;
	scanf("%d", &N);
	vector<student> Parti(N);

	for (int i = 0; i < N; i++)
	{
		int tmpC, tmpN, tmpS;
		scanf("%d %d %d", &tmpC, &tmpN, &tmpS);

		Parti[i].country = tmpC;
		Parti[i].number = tmpN;
		Parti[i].score = tmpS;
	}

	sort(Parti.begin(), Parti.end(), greater<student>());

	Parti[0].print();
	Parti[1].print();

	if (Parti[0].country == Parti[1].country)
	{
		for (int i = 2; i < Parti.size(); i++)
		{
			if (Parti[i].country == Parti[0].country) continue;
			else
			{
				Parti[i].print();
				break;
			}
		}
	}
	else
		Parti[2].print();
	
}