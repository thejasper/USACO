/*
ID: jasper_1
PROG: money
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;

int main()
{
    ofstream fout ("money.out");
    ifstream fin ("money.in");

    int val, num_coins;
    fin >> num_coins >> val;

    int coins[num_coins];
    for (int i = 0; i < num_coins; ++i)
        fin >> coins[i];

    long long ways[val + 1];
    memset(ways, 0, sizeof(ways));
    ways[0] = 1;

    for (int j = 0; j < num_coins; ++j) {
        for (int i = 1; i <= val; ++i) {
            if (coins[j] > i)
                continue;
            ways[i] += ways[i - coins[j]];
        }
    }

    fout << ways[val] << endl;

    return 0;
}
