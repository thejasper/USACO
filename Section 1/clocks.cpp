/*
ID: jasper_1
PROG: clocks
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <queue>
using namespace std;

#define N 9
int clocks[N];

string moves[] = {"abde", "abc", "bcef", "adg", "bdefh", "cfi", "degh", "ghi", "efhi"};

int check(string n)
{
    vector<int> c(clocks, clocks + N);
    for (int i = 1; i < int(n.size()); i += 2) {
        int m = n[i] - '1';
        for (int i = 0; i < int(moves[m].size()); ++i)
            c[moves[m][i] - 'a'] += 3;

        for (int i = 0; i < N; ++i)
            if (c[i] > 12) c[i] = 3; //cycle
    }
    for (int i = 0; i < N; ++i) if (c[i] != 12) return 0;
    return 1;
}

string solve()
{
    int cnt[N];
    for (cnt[0] = 0; cnt[0] < 4; ++cnt[0])
    for (cnt[1] = 0; cnt[1] < 4; ++cnt[1])
    for (cnt[2] = 0; cnt[2] < 4; ++cnt[2])
    for (cnt[3] = 0; cnt[3] < 4; ++cnt[3])
    for (cnt[4] = 0; cnt[4] < 4; ++cnt[4])
    for (cnt[5] = 0; cnt[5] < 4; ++cnt[5])
    for (cnt[6] = 0; cnt[6] < 4; ++cnt[6])
    for (cnt[7] = 0; cnt[7] < 4; ++cnt[7])
    for (cnt[8] = 0; cnt[8] < 4; ++cnt[8]) {
        string s;
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < cnt[i]; ++j)
                s += ' ', s += char(i + '1');
        if (check(s))
            return s.substr(1);
    }
    return "";
}

int main()
{
    ofstream fout ("clocks.out");
    ifstream fin ("clocks.in");

    for (int i = 0; i < N; ++i)
        fin >> clocks[i];
    fout << solve() << endl;

    return 0;
}
