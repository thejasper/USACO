/*
ID: jasper_1
PROG: preface
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>
#include <utility>
using namespace std;

vector< pair<int, string> > roman;

string convert(int n)
{
    string ret = "";

    for (int i = 0; i < int(roman.size()) && n > 0; ++i) {
        while (roman[i].first <= n) {
            ret += roman[i].second;
            n -= roman[i].first;
        }
    }

    return ret;
}

int main()
{
    ofstream fout ("preface.out");
    ifstream fin ("preface.in");

    roman.push_back(make_pair(1000, "M"));
    roman.push_back(make_pair(900, "CM"));
    roman.push_back(make_pair(500, "D"));
    roman.push_back(make_pair(400, "CD"));
    roman.push_back(make_pair(100, "C"));
    roman.push_back(make_pair(90, "XC"));
    roman.push_back(make_pair(50, "L"));
    roman.push_back(make_pair(40, "XL"));
    roman.push_back(make_pair(10, "X"));
    roman.push_back(make_pair(9, "IX"));
    roman.push_back(make_pair(5, "V"));
    roman.push_back(make_pair(4, "IV"));
    roman.push_back(make_pair(1, "I"));

    int n, letters[26];
    fin >> n;

    memset(letters, 0, sizeof(letters));
    for (int i = 1; i <= n; ++i) {
        string s = convert(i);

        for (int j = 0; j < int(s.size()); ++j)
            ++letters[s[j] - 'A'];
    }

    for (int i = int(roman.size()) - 1; i >= 0; --i) {
        if (int(roman[i].second.size()) == 1) {
            char a = roman[i].second[0];
            if (letters[a - 'A'])
                fout << a << ' ' << letters[a - 'A'] << endl;
        }
    }

    return 0;
}
