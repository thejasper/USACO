/*
ID: jasper_1
PROG: dualpal
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string convert(int n, int b)
{
    string ret = "";
    while (n > 0) {
        int last = n % b;
        n /= b;
        ret = string(1, last + '0') + ret;
    }
    return ret;
}

int palindrome(string s)
{
    return s == string(s.rbegin(), s.rend());
}

int more_than_two(int n)
{
    int num = 0;
    for (int i = 2; i <= 10; ++i) {
        if (palindrome(convert(n, i)))
            ++num;
        if (num >= 2)
            return 1;
    }
    return 0;
}

int main()
{
    ofstream fout ("dualpal.out");
    ifstream fin ("dualpal.in");

    int n, s;
    fin >> n >> s;

    for (int i = s + 1; n; ++i) {
        if (more_than_two(i)) {
            fout << i << endl;
            --n;
        }
    }

    return 0;
}
