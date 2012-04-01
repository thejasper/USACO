/*
ID: jasper_1
PROG: runround
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;

int runround(string s)
{
    int n = s.size();
    int i = 0;
    int vis[n];
    memset(vis, 0, sizeof(vis));

    int ok = 1;
    while (1) {
        if (i == 0 && vis[0])
            break;
        if (vis[i] == 1) {
            ok = 0;
            break;
        }
        vis[i] = 1;

        int curr = s[i] - '0';
        i = (i + curr) % n;
    }

    for (int j = 0; j < n; ++j)
        if (!vis[j])
            ok = 0;
    return ok;
}

int unique(string s)
{
    int dig[10];
    memset(dig, 0, sizeof(dig));
    for (int i = 0; i < int(s.size()); ++i)
        if (++dig[s[i] - '0'] > 1)
            return 0;
    return 1;
}

int main()
{
    ofstream fout ("runround.out");
    ifstream fin ("runround.in");

    unsigned long num;
    fin >> num;

    while (1) {
        ++num;
        unsigned long n = num;
        string s = "";
        while (n > 0) {
            s = char(n % 10 + '0') + s;
            n /= 10;
        }

        if (!unique(s))
            continue;

        if (runround(s))
            break;
    }

    fout << num << endl;

    return 0;
}
