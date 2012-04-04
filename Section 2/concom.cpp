/*
ID: jasper_1
PROG: concom
LANG: C++
*/
#include <algorithm>
#include <cstring>
#include <fstream>
#include <iostream>
#include <set>
#include <string>
#include <utility>
#include <vector>
using namespace std;

#define MAX 101

int perc[MAX][MAX];
int a[MAX][MAX];

int main()
{
    ofstream fout ("concom.out");
    ifstream fin ("concom.in");

    int n;
    fin >> n;

    for (int i = 0; i < n; ++i) {
        int comp1, comp2, owns;
        fin >> comp1 >> comp2 >> owns;
        perc[comp1][comp2] = owns;
        a[comp1][comp2] = owns > 50;
    }

    for (int i=0; i<MAX; ++i)
        a[i][i] = 1;

    int updated = 1;
    while (updated) {
        updated = 0;

        for (int i = 0; i < MAX; ++i)
        for (int j = 0; j < MAX; ++j) {
            if (a[i][j]) continue;

            //proberen uitvissen of i company j op een andere manier kan ownen (door som)
            int som = 0;
            for (int k = 0; k < MAX; ++k)
                if (a[i][k])
                    som += perc[k][j];

            if (som > 50) {
                a[i][j] = 1;
                updated = 1;
            }
        }
    }

    for (int i = 0; i < MAX; ++i)
    for (int j = 0; j < MAX; ++j)
        if (i != j && a[i][j])
            fout << i << ' ' << j << endl;

    return 0;
}
