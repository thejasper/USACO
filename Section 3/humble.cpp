/*
ID: jasper_1
PROG: humble
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <vector>
#include <set>
#include <climits>
#include <algorithm>
using namespace std;

int main()
{
    ofstream fout ("humble.out");
    ifstream fin ("humble.in");

    int k , n;
    set<long long> seen;

    fin >> k >> n;
    int orig[k];
    for (int i = 0; i < k; ++i) {
        int num;
        fin >> num;
        orig[i] = num;
        seen.insert(num);
    }

    sort(orig, orig + k);

    while (n > 1) {
        long long next = *seen.begin();
        //cout << next << endl;
        seen.erase(seen.find(next));

        for (int i = 0; i < k; ++i) {
            long long next_num = next * orig[i];

            if (int(seen.size()) >= n && next_num > *seen.rbegin())
                break;

            seen.insert(next_num);
        }
        --n;
    }

    fout << *seen.begin() << endl;

    return 0;
}
