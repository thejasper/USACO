/*
ID: jasper_1
PROG: lamps
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main()
{
    ofstream fout ("lamps.out");
    ifstream fin ("lamps.in");

    int n, c, t;
    vector<int> on, off;
    fin >> n >> c;

    while (fin >> t) {
        if (t == -1) break;
        on.push_back(t - 1);
    }

    while (fin >> t) {
        if (t == -1) break;
        off.push_back(t - 1);
    }

    c = min(4, c);

    set<string> res;
    for (int j = 0; j < 16; ++j) {
        //aantal bits gelijk aan button presses
        if (((j & 1) >> 0) + ((j & 2) >> 1) + ((j & 4) >> 2) + ((j & 8) >> 3) > c)
            continue;
        vector<int> state(n, 1);

        if (j & 1) for (int i = 0; i < n; ++i)
                state[i] ^= 1;
        if (j & 2) for (int i = 1; i < n; i += 2)
                state[i] ^= 1;
        if (j & 4) for (int i = 0; i < n; i += 2)
                state[i] ^= 1;
        if (j & 8) for (int i = 0; i < n; i += 3)
                state[i] ^= 1;

        int ok = 1;
        for (int i = 0; i < int(on.size()); ++i)
            if (!state[on[i]]) ok = 0;
        for (int i = 0; i < int(off.size()); ++i)
            if (state[off[i]]) ok = 0;

        if (!ok) continue;

        string sol = "";
        for (int i = 0; i < n; ++i)
            sol += (state[i] + '0');
        res.insert(sol);
    }

    if (!res.empty()) for (set<string>::iterator it = res.begin(); it != res.end(); ++it)
        fout << *it << endl;
    else
        fout << "IMPOSSIBLE" << endl;

    return 0;
}
