/*
ID: jasper_1
PROG: pprime
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

int geteven(int n)
{
    int a = n;
    while (a > 0) {
        n = n * 10 + a % 10;
        a /= 10;
    }
    return n;
}

int getodd(int n)
{
    int a = n;
    a /= 10;
    while (a > 0) {
        n = n * 10 + a % 10;
        a /= 10;
    }
    return n;
}

int isprime(int n)
{
    if (n < 2) return 0;
    if (n == 2)return 1;
    if (n % 2 == 0)return 0;
    for (int i = 3; i <= ceil(sqrt(n)); i += 2)
        if (n % i == 0)
            return 0;
    return 1;
}

int main()
{
    ofstream fout ("pprime.out");
    ifstream fin ("pprime.in");

    int a, b;
    fin >> a >> b;

    int digits_a = log10(a) + 1;
    int digits_b = log10(b) + 1;

    int start = (digits_a + 1) / 2 - 1;
    int stop = (digits_b + 1) / 2;

    vector<int> res;
    //wat extra genereren maar is nog steeds snel genoeg..
    for (int i = pow(10, start); i <= pow(10, stop); ++i) {
        int odd = getodd(i);
        int even = geteven(i);

        if (odd >= a && odd <= b && isprime(odd))
            res.push_back(odd);
        if (even >= a && even <= b && isprime(even))
            res.push_back(even);
    }

    sort(res.begin(), res.end());

    for (int i = 0; i < int(res.size()); ++i)
        fout << res[i] << endl;

    return 0;
}
