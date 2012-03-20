/*
ID: jasper_1
PROG: barn1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    ofstream fout ("barn1.out");
    ifstream fin ("barn1.in");

    int num_boards, num_stalls, num_open;
    fin >> num_boards >> num_stalls >> num_open;
    vector<int> open(num_open);

    for (int i = 0; i < num_open; ++i)
        fin >> open[i];
    sort(open.begin(), open.end());

    vector<int> size_gaps;
    for (int i = 1; i < num_open; ++i) {
        int diff = open[i] - open[i - 1] - 1;
        if (diff) size_gaps.push_back(diff);
    }

    sort(size_gaps.rbegin(), size_gaps.rend());

    int covered = open.back() - open.front() + 1;
    for (int i = 0; i < num_boards - 1 && i < int(size_gaps.size()); ++i)
        covered -= size_gaps[i];
    fout << covered << endl;

    return 0;
}
