/*
ID: jasper_1
PROG: calfflac
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

int main()
{
    ofstream fout ("calfflac.out");
    ifstream fin ("calfflac.in");

    string inp, s;
    while (getline(fin, s)) {
        inp += s;
        inp += '\n';
    }

    int sz = int(inp.size());
    int n = 2 * sz - 1;

    int beststart = 0, beststop = 0;
    int bestcnt = 0;
    for (int i = 0; i < n; ++i) {
        int start, stop, realstart, realstop;
        int cnt = 0;
        if (i % 2 == 0) {
            start = i / 2 - 1;
            stop = i / 2 + 1;
            if (!isalpha(inp[i / 2]))
                continue;
            ++cnt;
        } else {
            start = i / 2;
            stop = i / 2 + 1;
        }

        realstart = start;
        realstop = stop;
        while (true) {
            while (start >= 0 && !isalpha(inp[start])) --start;
            while (stop < sz && !isalpha(inp[stop])) ++stop;

            if (start < 0 || stop >= sz || tolower(inp[start]) != tolower(inp[stop]))
                break;
            realstart = start;
            realstop = stop;

            --start;
            ++stop;
            cnt += 2;
        }

        if (cnt > bestcnt) {
            beststop = realstop;
            beststart = realstart;
            bestcnt = cnt;
        }
    }

    fout << bestcnt << endl;
    for (int i = beststart; i <= beststop; ++i)
        fout << inp[i];
    fout << endl;

    return 0;
}
