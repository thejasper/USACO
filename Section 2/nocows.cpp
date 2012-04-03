/*
ID: jasper_1
PROG: nocows
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

#define DIV 9901

struct state {
    int down, half;
    state() : down(-1), half(-1) {}
    state(int d, int h) : down(d), half(h) {}
    int valid() {
        return down != -1 && half != -1;
    }
};

state mem[200][100];

state cnt(int n, int k)
{
    if (mem[n][k].valid())
        return mem[n][k];
    if (k == 0 || n > pow(2, k) - 1)
        return state(-1, -1);
    if (n == 1)
        return state(k == 1, k != 1);

    state total(0, 0);
    for (int i = 1; i < n - 1; ++i) {
        state left = cnt(i, k - 1);
        state right = cnt(n - i - 1, k - 1);

        if (left.valid() && right.valid()) {
            total.down += (left.down * right.down) % DIV +
                          (left.down * right.half) % DIV +
                          (left.half * right.down) % DIV;
            total.half += (left.half * right.half) % DIV;
        }
    }

    return mem[n][k] = state(total.down % DIV, total.half % DIV);
}

int main()
{
    ofstream fout ("nocows.out");
    ifstream fin ("nocows.in");

    int n, k;
    fin >> n >> k;

    fout << cnt(n, k).down << endl;

    return 0;
}

