/*
ID: jasper_1
PROG: ride
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int translate(string s)
{
    unsigned long c = 1;
    for (int i = 0; i < int(s.size()); ++i) {
        c *= (s[i] - 'A' + 1);
    }
    return c % 47;
}

int main()
{
    ofstream fout ("ride.out");
    ifstream fin ("ride.in");

    string a, b;
    fin >> a >> b;

    if (translate(a) == translate(b))
        fout << "GO" << endl;
    else
        fout << "STAY" << endl;

    return 0;
}
