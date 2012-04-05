/*
ID: jasper_1
PROG: cowtour
LANG: C++
*/
#include <algorithm>
#include <assert.h>
#include <cmath>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>
using namespace std;

#define MAX 160
#define MAX_DIST 150000

int n;
int xCord[MAX], yCord[MAX];
double D[MAX][MAX];
string a[MAX];

double dist(int i, int j)
{
    return sqrt(pow(xCord[i] - xCord[j], 2) + pow(yCord[i]- yCord[j], 2));
}

int main()
{
    ofstream fout ("cowtour.out");
    ifstream fin ("cowtour.in");

    fin >> n;
    for (int i = 0; i < n; ++i)
        fin >> xCord[i] >> yCord[i];
    for (int i = 0; i < n; ++i) {
        fin >> a[i];
        a[i][i] = '1';
    }

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            D[i][j] = (a[i][j] == '0' ? MAX_DIST : dist(i, j));

    for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                D[i][j] = min(D[i][j], D[i][k] + D[k][j]);

    double smallest = MAX_DIST;
    double internal = 0;
    for (int i = 0; i < n; ++i) {
        double d = 0;
        for (int j = 0; j < n; ++j)
            if (D[i][j] < MAX_DIST && D[i][j] > d)
                d = D[i][j];

        for (int j = 0; j < n; ++j) {
            if (D[i][j] < MAX_DIST) {
                internal = max(internal, D[i][j]);
                continue;
            }

            double e = 0;
            for (int k = 0; k < n; ++k)
                if (D[j][k] < MAX_DIST && D[j][k] > e)
                    e = D[j][k];
            smallest = min(smallest, d + dist(i, j) + e);
        }
    }

    fout << fixed << setprecision(6) << max(smallest, internal) << endl;

    return 0;
}
