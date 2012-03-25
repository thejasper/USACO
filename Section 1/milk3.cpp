/*
ID: jasper_1
PROG: milk3
LANG: C++
*/
#include <algorithm>
#include <fstream>
#include <iostream>
#include <set>
#include <string>
#include <utility>
#include <vector>
using namespace std;

vector<int> cvals;
set< pair<int, int> > mem;
int capA, capB, capC;

void rec(int a, int b, int c)
{
    if (mem.find(make_pair(a, b)) != mem.end())
        return;
    mem.insert(make_pair(a, b));

    if (!a) cvals.push_back(c);

    if (a) { //from a
        int toB = min(capB - b, a);
        rec(a - toB, b + toB, c);
        int toC = min(capC - c, a);
        rec(a - toC, b, c + toC);
    }
    if (b) { //from b
        int toA = min(capA - a, b);
        rec(a + toA, b - toA, c);
        int toC = min(capC - c, b);
        rec(a, b - toC, c + toC);
    }
    if (c) { //from c
        int toA = min(capA - a, c);
        rec(a + toA, b, c - toA);
        int toB = min(capB - b, c);
        rec(a, b + toB, c - toB);
    }
}

int main()
{
    ofstream fout ("milk3.out");
    ifstream fin ("milk3.in");

    fin >> capA >> capB >> capC;

    rec(0, 0, capC);
    sort(cvals.begin(), cvals.end());

    fout << cvals[0];
    for (int i = 1; i < int(cvals.size()); ++i)
        fout << " " << cvals[i];
    fout << endl;

    return 0;
}
