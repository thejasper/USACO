/*
ID: jasper_1
PROG: agrinet
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

#define MAX 100

int parent[MAX];

int get_parent(int i)
{
    if (parent[i] == i)
        return i;
    return parent[i] = get_parent(parent[i]);
}

int same(int i, int j)
{
    return get_parent(i) == get_parent(j);
}

void merge(int i, int j)
{
    int parent_i = get_parent(i);
    parent[parent_i] = get_parent(j);
}

int main()
{
    ofstream fout ("agrinet.out");
    ifstream fin ("agrinet.in");

    int n;
    fin >> n;

    for (int i = 0; i < n; ++i)
        parent[i] = i;

    vector< pair<int, pair<int, int> > > edges;
    for (int i = 0; i < n; ++i)  {
        for (int j = 0; j < n; ++j) {
            int w;
            fin >> w;
            if (w) edges.push_back(make_pair(w, make_pair(i, j)));
        }
    }

    sort(edges.begin(), edges.end());

    int weight = 0, picked = 0;
    for (int i = 0; i < int(edges.size()) ; ++i) {
        int w = edges[i].first;
        int u = edges[i].second.first;
        int v = edges[i].second.second;

        if (!same(u, v)) {
            weight += w;
            merge(u, v);
            ++picked;
        }

        if (picked == n - 1)
            break;
    }

    fout << weight << endl;

    return 0;
}
