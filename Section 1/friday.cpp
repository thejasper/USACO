/*
ID: jasper_1
PROG: friday
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

int isleap(int year)
{
    if (year % 4 != 0)
        return 0;
    if (year % 100 == 0 && year % 400 != 0)
        return 0;
    return 1;
}

int main()
{
    ofstream fout ("friday.out");
    ifstream fin ("friday.in");

    int n;
    fin >> n;

    int res[7];
    memset(res, 0, sizeof(res));

    int year = 1900;
    int month = 0;
    int weekday = 0;
    ++res[0]; // 13/01/1900 op zaterdag

    int months_to_go = n * 12 - 1;
    int days_skip[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    while (months_to_go--) {
        int skip = days_skip[month];
        if (month == 1 && isleap(year))
            ++skip;
        weekday = (weekday + skip) % 7;
        ++res[weekday];
        month = (month + 1) % 12;
        if (month == 0)
            ++year;
    }

    for (int i=0; i<6; ++i)
        fout << res[i] << " ";
    fout << res[6] << endl;

    return 0;
}
