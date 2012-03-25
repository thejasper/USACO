/*
ID: jasper_1
PROG: ariprog
LANG: C++
*/
#include <algorithm>
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

#define MAX 125000

int sq[MAX + 1];
vector<int> nums;
vector< pair<int, int> > ans; //diff, start

void fill_squares(int highest)
{
    memset(sq, 0, sizeof(sq));
    for (int i = 0; i <= highest; ++i) {
        for (int j = i; j <= highest; ++j) {
            int num = i * i + j * j;
            if (!sq[num]) //geen duplicaten
                nums.push_back(num);
            sq[num] = 1;
        }
    }
    sort(nums.begin(), nums.end());
}

void find_answers(int length)
{
    int n = int(nums.size());
    for (int i = 0; i < n; ++i) { //startplaatsen
        for (int j = i + 1; j < n; ++j) { //een volgend getal
            int diff = nums[j] - nums[i]; //2 getallen vormen sowieso seq
            int ok = 1;
            for (int k = 2; k < length; ++k) { //ver genoeg?
                int next = nums[i] + k * diff;
                if (next > MAX || !sq[next]) {
                    ok = 0;
                    break;
                }
            }

            if (ok) ans.push_back(make_pair(diff, nums[i]));
        }
    }
}

int main()
{
    ofstream fout ("ariprog.out");
    ifstream fin ("ariprog.in");

    int min_length, highest_square;
    fin >> min_length >> highest_square;

    fill_squares(highest_square);
    find_answers(min_length);

    int found = int(ans.size());
    if (!found)
        fout << "NONE" << endl;
    else {
        sort(ans.begin(), ans.end());
        for (int i = 0; i < found; ++i)
            fout << ans[i].second << " " << ans[i].first << endl;
    }

    return 0;
}
