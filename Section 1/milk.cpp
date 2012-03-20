/*
ID: jasper_1
PROG: milk2
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

int main()
{
    ofstream fout ("milk2.out");
    ifstream fin ("milk2.in");

    int n;
    vector< pair<int, int> > t;

    fin >> n;
    for (int i = 0; i < n; ++i) {
        int start, stop;
        fin >> start >> stop;
        t.push_back(make_pair(start, stop));
    }

    sort(t.begin(), t.end());

    int started = t[0].first;
    int cont = 0, idle = 0;
    int furthest = t[0].second;

    for (int i = 1; i < n; ++i) {
        int start = t[i].first;
        int stop = t[i].second;

        if (start > furthest) { //gap
            cont = max(cont, furthest - started);
            idle = max(idle, start - furthest);
            started = start;
            furthest = stop;
        }
        if (stop > furthest)
            furthest = stop;
    }

    cont = max(cont, furthest - started);
    fout << cont << " " << idle << endl;

    return 0;
}
