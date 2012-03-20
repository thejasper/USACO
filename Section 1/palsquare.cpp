/*
ID: jasper_1
PROG: palsquare
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

char translate(int n)
{
    return "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"[n];
}

string convert(int n, int b)
{
    string ret = "";
    while (n > 0) {
        int last = n % b;
        n /= b;
        ret = translate(last) + ret;
    }
    return ret;
}

int check_palindrome(string s)
{
    return s == string(s.rbegin(), s.rend());
}

int main()
{
    ofstream fout ("palsquare.out");
    ifstream fin ("palsquare.in");

    int b;
    fin >> b;

    for (int i = 1; i <= 300; ++i) {
        string square = convert(i * i, b);
        if (check_palindrome(square))
            fout << convert(i, b) << " " << square << endl;
    }

    return 0;
}
