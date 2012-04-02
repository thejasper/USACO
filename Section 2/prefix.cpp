/*
ID: jasper_1
PROG: prefix
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <cstring>
using namespace std;

vector<string> prim;

void read_primitives(ifstream& fin)
{
    string s, u;
    while (getline(fin, s)) {
        istringstream inp(s);
        while (inp >> u) {
            if (u == ".")
                return;
            prim.push_back(u);
        }
    }
}

int main()
{
    ofstream fout ("prefix.out");
    ifstream fin ("prefix.in");

    read_primitives(fin);

    string seq, s;
    while (getline(fin, s))
        seq += s;

    int n = seq.size(), m = prim.size();
    int dp[n + 1]; //dp[i] is 1 als er een prefix met lengte i bestaat
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;

    for (int i = 0; i < n; ++i) {
        if (!dp[i]) continue;

        //uitbreiden
        for (int j = 0; j < m; ++j) {
            int prim_length = prim[j].size();
            if (prim_length + i - 1 >= n)
                continue;

            int ok = 1;
            for (int k = 0; k < prim_length; ++k) {
                if (seq[i + k] != prim[j][k]) {
                    ok = 0;
                    break;
                }
            }

            dp[i + prim_length] |= ok;
        }
    }

    for (int i = n; i >= 0; --i) {
        if (dp[i] == 1) {
            fout << i << endl;
            break;
        }
    }

    return 0;
}
