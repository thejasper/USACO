/*
ID: jasper_1
PROG: subset
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;

#define MAX 40
long long dp[MAX][(MAX * (MAX + 1)) / 4 + 1];
int n, goal;

long long count(int cons, int sum)
{
    if (sum == goal)
        return 1;

    if (cons > n || sum > goal)
        return 0;

    if (dp[cons][sum] != -1)
        return dp[cons][sum];

    return dp[cons][sum] = count(cons + 1, sum + cons) + count(cons + 1, sum);
}

int main()
{
    ofstream fout ("subset.out");
    ifstream fin ("subset.in");

    fin >> n;

    if ((n * (n + 1)) % 4 != 0)
        fout << '0' << endl;
    else {
        memset(dp, -1, sizeof(dp));
        goal = (n * (n + 1)) / 4;
        fout << count(1, 0) / 2 << endl;
    }

    return 0;
}
