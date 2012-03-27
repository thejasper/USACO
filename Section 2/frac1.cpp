/*
ID: jasper_1
PROG: frac1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct fraction {
    int teller, noemer;
    fraction(int t, int n) : teller(t), noemer(n) {}

    bool operator<(const fraction& f) const {
        return teller * f.noemer < f.teller * noemer;
    }
};

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main()
{
    ofstream fout ("frac1.out");
    ifstream fin ("frac1.in");

    int n;
    fin >> n;

    vector<fraction> ans;
    for (int j = 1; j <= n; ++j) //noemer
        for (int i = 0; i <= j; ++i) //teller
            if (gcd(i, j) == 1)
                ans.push_back(fraction(i, j));
    sort(ans.begin(), ans.end());

    for (int i = 0; i < int(ans.size()); ++i)
        fout << ans[i].teller << '/' << ans[i].noemer << endl;

    return 0;
}
