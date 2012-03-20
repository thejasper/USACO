/*
ID: jasper_1
PROG: namenum
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <utility>

using namespace std;

char get_num(char c)
{
    if (c > 'Q') --c;
    c -= 'A';
    return c / 3 + 2 + '0';
}

string make_serial(string s)
{
    string serial = "";
    int n = int(s.size());
    for (int i = 0; i < n; ++i)
        serial += get_num(s[i]);
    return serial;
}

int main()
{
    ofstream fout ("namenum.out");
    ifstream fin ("namenum.in");
    ifstream valid("dict.txt");

    string cow;
    fin >> cow;

    string s;
    vector< pair<string, string> > names; //name, serial
    while (valid >> s)
        names.push_back(make_pair(s, make_serial(s)));

    int found = 0;
    for (int i = 0; i < int(names.size()); ++i)
        if (names[i].second == cow)
            fout << names[i].first << endl, found = 1;
    if (!found)
        fout << "NONE" << endl;

    return 0;
}
