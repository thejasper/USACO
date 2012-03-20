/*
ID: jasper_1
PROG: gift1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <utility>

using namespace std;

int main()
{
    ofstream fout ("gift1.out");
    ifstream fin ("gift1.in");

    int n;
    fin >> n;

    map<string, pair<int, int> > names;
    string inorder[n];
    
    for (int i = 0; i < n; ++i) {
        string s;
        fin >> s;
        names[s] = make_pair(0, 0);
        inorder[i] = s;
    }

    for (int i = 0; i < n; ++i) {
        string name;
        int money, cnt;
        fin >> name >> money >> cnt;

        if (!cnt) continue;
        int moneygive = money / cnt;
        names[name].first = money;
        names[name].second += money % cnt;

        for (int j = 0; j < cnt; ++j) {
            string giveto;
            fin >> giveto;
            names[giveto].second += moneygive;
        }
    }

    for (int i = 0; i < n; ++i) {
        fout << inorder[i] << " " << (names[inorder[i]].second - names[inorder[i]].first) << endl;
    }

    return 0;
}
