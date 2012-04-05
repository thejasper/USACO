/*
ID: jasper_1
PROG: comehome
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <utility>
#include <queue>
#include <cctype>
using namespace std;

#define MAX 256
#define INF 1000000

int main()
{
    ofstream fout ("comehome.out");
    ifstream fin ("comehome.in");

    int n;
    vector< pair<char, int> >G[MAX];

    fin >> n;
    for (int i = 0; i < n; ++i) {
        int d;
        char from, to;
        fin >> from >> to >> d;
        G[int(from)].push_back(make_pair(to, d));
        G[int(to)].push_back(make_pair(from, d));
    }
    
    priority_queue<pair<int, char>, vector< pair<int, char> >, greater< pair<int, char> > >q;
    int dist[MAX];
    for (int i = 0; i < MAX; ++i)
        dist[i] = INF;

    q.push(make_pair(0, 'Z'));
    dist['Z'] = 0;

    while (!q.empty()) {
        pair<int, char> curr = q.top();
        q.pop();
        int d = curr.first;
        int c = curr.second;

        if (d < dist[c])
            continue;

        if (isupper(c) && c != 'Z') {
            fout << char(c) << ' ' << d << endl;
            break;
        }

        for (int i = 0; i < int(G[c].size()); ++i) {
            int next = G[c][i].first;
            int weight = G[c][i].second;

            if (dist[next] > d + weight) {
                dist[next] = d + weight;
                q.push(make_pair(dist[next], next));
            }
        }
    }

    return 0;
}
