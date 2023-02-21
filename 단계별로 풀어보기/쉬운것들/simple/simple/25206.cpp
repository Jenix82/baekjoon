#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

void p25206()
{
	double total = 0, count = 0;
	for (int i = 0; i < 20; i++)
	{
		string name, grade;
		double credit;
		cin >> name >> credit >> grade;
		
		if (grade.compare("A+") == 0) total += credit * 4.5;
		if (grade.compare("A0") == 0) total += credit * 4.0;
		if (grade.compare("B+") == 0) total += credit * 3.5;
		if (grade.compare("B0") == 0) total += credit * 3.0;
		if (grade.compare("C+") == 0) total += credit * 2.5;
		if (grade.compare("C0") == 0) total += credit * 2.0;
		if (grade.compare("D+") == 0) total += credit * 1.5;
		if (grade.compare("D0") == 0) total += credit * 1.0;

		if (grade.compare("P") != 0) count += credit;
	}
	printf("%f", total / count);
}