/*
ID: jasper_1
PROG: packrec
LANG: C++
*/
#include <algorithm>
#include <fstream>
#include <iostream>
#include <set>
#include <string>
#include <utility>
#include <vector>
using namespace std;

#define st first
#define nd second

set< pair<int, int> > ans;
int best = 123456789;

void add(int w, int h)
{
    int opp = w * h;
    if (opp < best) {
        ans.clear();
        best = opp;
    }
    if (opp == best)
        ans.insert(make_pair(min(w, h), max(w, h)));
}

int main()
{
    ofstream fout ("packrec.out");
    ifstream fin ("packrec.in");

    vector< pair<int, int> > rec(4, make_pair(0, 0));
    int c[4];
    for (int i = 0; i < 4; ++i) {
        fin >> rec[i].st >> rec[i].nd;
        c[i] = i;
    }

    do {
        for (int i = 0; i < 16; ++i) {
            int w, h;
            vector< pair<int, int> > r; //kopie anders geordend en gedraaid (w,h)
            for (int j = 0; j < 4; ++j) {
                if (i & (1 << j))
                    r.push_back(make_pair(rec[c[j]].st, rec[c[j]].nd));
                else
                    r.push_back(make_pair(rec[c[j]].nd, rec[c[j]].st));
            }

            //figure 1
            w = r[0].st + r[1].st + r[2].st + r[3].st;
            h = max(r[0].nd, max(r[1].nd, max(r[2].nd, r[3].nd)));
            add(w, h);

            //figure 2
            w = max(r[0].nd, r[1].st + r[2].st + r[3].st);
            h = r[0].st + max(r[1].nd, max(r[2].nd, r[3].nd));
            add(w, h);

            //figure 3
            w = max(r[0].nd + r[3].st, r[1].st + r[2].st + r[3].st);
            h = max(r[0].st + max(r[1].nd, r[2].nd), r[3].nd);
            add(w, h);

            //figure 4-5
            w = max(r[0].st, r[1].st) + r[2].st + r[3].st;
            h = max(r[0].nd + r[1].nd, max(r[2].nd, r[3].nd));
            add(w, h);

            //figure 6
            if (r[1].nd == r[2].nd)
                w = max(r[1].st + r[2].st, r[0].st + r[3].st);
            if (r[1].nd > r[2].nd && r[1].nd < r[2].nd + r[3].nd)
                w = max(r[1].st + r[2].st, max(r[1].st + r[3].st, r[0].st + r[3].st));
            if (r[2].nd > r[1].nd && r[2].nd < r[1].nd + r[0].nd)
                w = max(r[2].st + r[1].st, max(r[2].st + r[0].st, r[0].st + r[3].st));
            h = max(r[0].nd + r[1].nd, r[2].nd + r[3].nd);
            add(w, h);
        }
    } while (next_permutation(c, c + 4));

    fout << best << endl;
    for (set< pair<int, int> >::iterator it = ans.begin(); it != ans.end(); ++it)
        fout << it->st << ' ' << it->nd << endl;

    return 0;
}
