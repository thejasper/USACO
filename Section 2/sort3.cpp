/*
ID: jasper_1
PROG: sort3
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;

int main()
{
    ofstream fout ("sort3.out");
    ifstream fin ("sort3.in");

    int n;
    fin >> n;

    int nums[n];
    int cnt[] = {0, 0, 0};
    for (int i = 0; i < n; ++i)  {
        fin >> nums[i];
        --nums[i];
        ++cnt[nums[i]];
    }

    int a[3][3];
    memset(a, 0, sizeof(a));
    int stop = 0;
    int start = stop;
    for (int i = 0; i < 3; ++i)  {
        stop += cnt[i];
        for (int j = start; j < stop; ++j)
            ++a[i][nums[j]];
        start = stop;
    }

    int num_swaps = 0;

    //2 goedzetten in 1 swap
    for (int i = 0; i < 3; ++i) {
        int from = i;
        int to = (i + 1) % 3;
        int moved = min(a[from][to], a[to][from]);
        a[from][to] -= moved;
        a[to][from] -= moved;
        num_swaps += moved;
    }

    //3 goedzetten in 2 swaps (2, 3, 1)
    int moved = min(a[0][1], min(a[1][2], a[2][0]));
    a[0][1] -= moved;
    a[1][2] -= moved;
    a[2][0] -= moved;
    num_swaps += moved * 2;
    // (3, 1, 2)
    moved = min(a[0][2], min(a[1][0], a[2][1]));
    a[0][2] -= moved;
    a[1][0] -= moved;
    a[2][1] -= moved;
    num_swaps += moved * 2;

    fout << num_swaps << endl;

    return 0;
}
