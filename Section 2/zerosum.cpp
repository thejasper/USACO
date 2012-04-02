/*
ID: jasper_1
PROG: zerosum
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

vector<string> res;
int n;

void solve(int place, int sum, string s)
{
    if (place == n + 1) {
        if (sum == 0)
            res.push_back(s);
        return;
    }

    int num = 0;
    string add = "";
    for (int i = place; i <= n; ++i) {
        if (i != place) add += ' ';
        add += char(i + '0');
        num = num * 10 + i;

        solve(i + 1, sum + num, s + '+' + add);
        solve(i + 1, sum - num, s + '-' + add);
    }
}

int main()
{
    ofstream fout ("zerosum.out");
    ifstream fin ("zerosum.in");

    fin >> n;

    solve(2, 1, "1");
    solve(3, 12, "1 2");
    solve(4, 123, "1 2 3");
    solve(5, 1234, "1 2 3 4");

    sort(res.begin(), res.end());
    for (int i = 0; i < int(res.size()); ++i)
        fout << res[i] << endl;

    return 0;
}
