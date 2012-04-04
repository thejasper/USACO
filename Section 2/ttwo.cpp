/*
ID: jasper_1
PROG: ttwo
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#define N 10
#define MAX 100000 //should be enough

string a[N];

void move(int& r, int& c, int& dr, int& dc)
{
    int nr = r + dr;
    int nc = c + dc;

    if (nr < 0 || nr >= N || nc < 0 || nc >= N || a[nr][nc] == '*') {
        swap(dr, dc);
        dc = -dc;
    } else {
        a[nr][nc] = a[r][c];
        a[r][c] = '.';
        r = nr;
        c = nc;
        //cout << a[nr][nc] << ' ' << nr << ' ' << nc << endl;
    }
}

int main()
{
    ofstream fout ("ttwo.out");
    ifstream fin ("ttwo.in");

    int rF, cF, rC, cC, dirRF = -1, dirCF = 0, dirRC = -1, dirCC = 0;
    for (int i = 0; i < N; ++i) {
        fin >> a[i];
        for (int j = 0; j < N; ++j) {
            if (a[i][j] == 'F')
                rF = i, cF = j;
            if (a[i][j] == 'C')
                rC = i, cC = j;
        }
    }

    int time = 0, ok = 0;
    while (time < MAX) {
        if (rF == rC && cF == cC) {
            ok = 1;
            break;
        }
        move(rF, cF, dirRF, dirCF);
        move(rC, cC, dirRC, dirCC);
        ++time;
    }

    if (!ok) time = 0;

    fout << time << endl;

    return 0;
}
