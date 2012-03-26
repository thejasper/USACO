/*
ID: jasper_1
PROG: sprime
LANG: C++
*/
#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n;
vector<int> res;

int isprime(int num)
{
    if (num == 2) return 1;
    if (num % 2 == 0)return 0;
    for (int i = 3; i <= ceil(sqrt(num)); ++i)
        if (num % i == 0)
            return 0;
    return 1;
}

void gen(int num, int sz = 1)
{
    if (!isprime(num))
        return;

    if (sz == n) {
        res.push_back(num);
        return;
    }

    for (int i = 1; i <= 9; i += 2)
        gen(num * 10 + i, sz + 1);
}

int main()
{
    ofstream fout ("sprime.out");
    ifstream fin ("sprime.in");

    fin >> n;

    gen(2); gen(3); gen(5); gen(7);

    sort(res.begin(), res.end());
    for (int i = 0; i < int(res.size()); ++i)
        fout << res[i] << endl;

    return 0;
}
