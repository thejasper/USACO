/*
ID: jasper_1
PROG: milk
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main()
{
    ofstream fout ("milk.out");
    ifstream fin ("milk.in");

    int req, n;
    fin >> req >> n;

    vector< pair<int, int> > milk(n, make_pair(0, 0));
    for (int i = 0; i < n; ++i)
        fin >> milk[i].first >> milk[i].second; //price, gallons

    sort(milk.begin(), milk.end());

    int cost = 0;
    for (int i = 0; i < n && req; ++i) {
        int canbuy = min(req, milk[i].second);
        req -= canbuy;
        cost += canbuy * milk[i].first;
    }

    fout << cost << endl;

    return 0;
}
