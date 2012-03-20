/*
ID: jasper_1
PROG: beads
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <deque>

using namespace std;

int check_length(deque<char>& neck)
{
    int n = 0, m = 0;
    int sz = int(neck.size());

    int first = neck.front();
    for (; n < sz; ++n) {
        if (first == 'w' && neck[n] != 'w')
            first = neck[n];
        if (neck[n] != 'w' && neck[n] != first)
            break;
    }

    first = neck.back();
    for (int i = sz - 1; i >= 0; --i, ++m) {
        if (first == 'w' && neck[i] != 'w')
            first = neck[i];
        if (neck[i] != 'w' && neck[i] != neck.back())
            break;
    }

    return min(sz, n + m);
}

int main()
{
    ofstream fout ("beads.out");
    ifstream fin ("beads.in");

    int n;
    string s;
    fin >> n >> s;

    deque<char> neck(s.begin(), s.end());

    int max = 0;
    for (int i = 0; i < n; ++i) {
        int res = check_length(neck);
        if (res > max)
            max = res;
        int first = neck.front();
        neck.pop_front();
        neck.push_back(first);
    }

    if (!max) max = n;

    fout << max << endl;

    return 0;
}
