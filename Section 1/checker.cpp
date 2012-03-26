/*
ID: jasper_1
PROG: checker
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;

#define MAX 13

int n, sols = 0;
int a[MAX];
int ans[3][MAX];
int col_occup[MAX];
int diag1_occup[2 * MAX - 1]; // '/'
int diag2_occup[2 * MAX - 1]; // '\'

void place_in_row(int r)
{
    if (r == n) {
        if (sols < 3) {
            for (int i = 0; i < n; ++i)
                ans[sols][i] = a[i] + 1;
        }
        ++sols;
        return;
    }
    for (int i = 0; i < n; ++i) {
        int diag1 = r + i;
        int diag2 = r + n - i;
        if (!col_occup[i] && !diag1_occup[diag1] && !diag2_occup[diag2]) {
            a[r] = i;
            col_occup[i] = 1;
            diag1_occup[diag1] = 1;
            diag2_occup[diag2] = 1;
            place_in_row(r + 1);
            col_occup[i] = 0;
            diag1_occup[diag1] = 0;
            diag2_occup[diag2] = 0;
        }
    }
}

int main()
{
    ofstream fout ("checker.out");
    ifstream fin ("checker.in");

    fin >> n;

    place_in_row(0);
    for (int i = 0; i < 3; ++i) {
        fout << ans[i][0];
        for (int j = 1; j < n; ++j)
            fout << ' ' << ans[i][j];
        fout << endl;
    }
    fout << sols << endl;

    return 0;
}
