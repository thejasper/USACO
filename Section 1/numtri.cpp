/*
ID: jasper_1
PROG: numtri
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    ofstream fout ("numtri.out");
    ifstream fin ("numtri.in");

    int n;
    fin >> n;

    vector<int> a[n];
    for (int i = 0; i < n; ++i) {
        a[i].reserve(i + 1);
        for (int j = 0; j < i + 1; ++j)
            fin >> a[i][j];
    }

    for (int i = n - 2; i >= 0; --i)
        for (int j = 0; j < i + 1; ++j)
            a[i][j] += max(a[i + 1][j], a[i + 1][j + 1]);

    fout << a[0][0] << endl;

    return 0;
}
