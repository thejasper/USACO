/*
ID: jasper_1
PROG: crypt1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int digit[10];

int allowed(int n)
{
    while (n > 0) {
        if (!digit[n % 10])
            return 0;
        n /= 10;
    }
    return 1;
}

int main()
{
    ofstream fout ("crypt1.out");
    ifstream fin ("crypt1.in");

    int n;
    fin >> n;
    for (int i = 0; i < 10; ++i) digit[i] = 0;
    for (int i = 0; i < n; ++i) {
        int d;
        fin >> d;
        digit[d] = 1;
    }

    int total=0;
    for (int i = 111; i <= 999; ++i) {
        if (!allowed(i))
            continue;

        for (int j = 11; j <= 99; ++j) {
            if (!allowed(j) || i*j >= 10000)
                continue;

            int p1 = (j % 10) * i;
            int p2 = (j / 10) * i;
            if (p1 >= 1000 || p2 >= 1000)
                continue;
            int res = p1 + p2 * 10;
            if (!allowed(p1) || !allowed(p2) || !allowed(res))
                continue;

            total++;
        }
    }

    cout << total << endl;

    return 0;
}
