/*
ID: jasper_1
PROG: inflate
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

#define MAX 10000
int dp[MAX + 1];

int main()
{
    ofstream fout ("inflate.out");
    ifstream fin ("inflate.in");

    int T, N;
    fin >> T >> N;

    int points[N], time[N];
    for (int i = 0; i < N; ++i)
        fin >> points[i] >> time[i];

    for (int i = 0; i < N; ++i) //items
        for (int j = 0; j <= T; ++j) //time
            if (time[i] <= j)
                dp[j] = max(dp[j], dp[j - time[i]] + points[i]);

    fout << dp[T] << endl;

    return 0;
}
