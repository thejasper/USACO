/*
ID: jasper_1
PROG: hamming
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int n, b, d, lim;
int seq[64];

int compatible(int num_found, int n)
{
    for (int i = 0; i < num_found; ++i) {
        int dist = 0;
        for (int j = 0; j < b; ++j)
            if ((seq[i] & (1 << j)) != (n & (1 << j)))
                ++dist;
        if (dist < d)
            return 0;
    }
    return 1;
}

int find_seq(int start, int curr)
{
    if (curr == n)
        return 1;

    for (int i = start + 1; i < lim; ++i) {
        if (compatible(curr, i)) {
            seq[curr] = i;
            return find_seq(i, curr + 1);
        }
    }
    return 0;
}

int main()
{
    ofstream fout ("hamming.out");
    ifstream fin ("hamming.in");

    fin >> n >> b >> d;

    lim = 1 << b;
    for (int i = 0; i < lim; ++i) {
        seq[0] = i;
        if (find_seq(i, 1))
            break;
    }

    for (int i = 1; i <= n; ++i) {
        fout << seq[i-1];
        if (i % 10 == 0 || i == n)
            fout << endl;
        else
            fout << ' ';
    }

    return 0;
}
