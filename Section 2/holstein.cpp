/*
ID: jasper_1
PROG: holstein
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;

int main()
{
    ofstream fout ("holstein.out");
    ifstream fin ("holstein.in");

    int n; //#vitaminen
    int m; //#feed types

    fin >> n;
    int goals[n];
    for (int i = 0; i < n; ++i)
        fin >> goals[i];

    fin >> m;
    int food[m][n];
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            fin >> food[i][j];

    int sz = m ;
    vector<int> answer(m, 10000);
    for (int i = 1; i < pow(2, m); ++i) {
        vector<int> pick;
        for (int j = 0; j < m; ++j)
            if (i & (1 << j))
                pick.push_back(j);
        int chosen = int(pick.size());
        if (chosen > sz)
            continue;

        int vitamines[n];
        memset(vitamines, 0, sizeof(vitamines));
        for (int j = 0; j < chosen; ++j)
            for (int k = 0; k < n; ++k)
                vitamines[k] += food[pick[j]][k];

        int ok = 1;
        for (int k = 0; k < n; ++k) {
            if (vitamines[k] < goals[k]) {
                ok = 0;
                break;
            }
        }
        if (!ok)
            continue;

        if (answer.empty() || sz > chosen) {
            copy(pick.begin(), pick.end(), answer.begin());
            sz = chosen;
        } else { //grootte gelijk
            for (int i = 0; i < chosen; ++i) {
                if (answer[i] > pick[i]) {
                    copy(pick.begin(), pick.end(), answer.begin());
                    sz = chosen;
                    break;
                }
            }
        }
    }

    fout << sz;
    for (int i = 0; i < sz; ++i)
        fout << ' ' << answer[i] + 1;
    fout << endl;

    return 0;
}
