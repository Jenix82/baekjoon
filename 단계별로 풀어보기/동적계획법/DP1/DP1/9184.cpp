#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<vector<vector<int>>> save(101, vector<vector<int>>(101, vector<int>(101, 0)));

inline int w(int a, int b, int c)
{
    if (a <= 0 || b <= 0 || c <= 0)
        return save[a + 50][b + 50][c + 50] = 1;
    if (a > 20 || b > 20 || c > 20)
        if (save[a + 50][b + 50][c + 50] != 0) return save[a + 50][b + 50][c + 50];
        else return save[a + 50][b + 50][c + 50] = w(20, 20, 20);
    if (a < b && b < c)
        if (save[a + 50][b + 50][c + 50] != 0) return save[a + 50][b + 50][c + 50];
        else return save[a + 50][b + 50][c + 50] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
    
    if (save[a + 50][b + 50][c + 50] != 0) return save[a + 50][b + 50][c + 50];
    else return save[a + 50][b + 50][c + 50] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
}

void p9184()
{
    vector<string> output;

    while (1)
    {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        if (a == -1 && b == -1 && c == -1) break;

        int value = w(a, b, c);
        string ans = "w(" + to_string(a) + ", " + to_string(b) + ", " + to_string(c) + ") = " + to_string(value);
        output.push_back(ans);
    }
    
    for (auto& a : output) cout << a << '\n';
}