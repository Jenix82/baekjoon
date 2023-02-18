#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class client
{
public:
	client() {}
	client(int a, string n) : age(a), name(n) {};
	~client() {}

	void printClient() { cout << age << " " << name << '\n'; }
	bool operator<(const client& other) const { return this->age < other.age; }

 	int age;
	string name;
};

void p10814()
{
	int N;
	scanf("%d", &N);
	vector<client> clients(N);

	for (auto& c: clients) cin >> c.age >> c.name;
	stable_sort(clients.begin(), clients.end(), less<client>());  
	for (auto& c: clients) c.printClient();
}

