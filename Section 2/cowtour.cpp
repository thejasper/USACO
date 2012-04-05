/*
ID: jasper_1
PROG: cowtour
LANG: C++
*/
#include <algorithm>
#include <assert.h>
#include <cmath>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>
#include <vector>
using namespace std;

#define MAX 160
#define MAX_DIST 150000

int n;
int xCord[MAX], yCord[MAX], visited[MAX];
double biggest=0;
string a[MAX];

struct component {
    vector<int> part;
    double furthest[MAX];

    double distance(int i, int j) {
        return sqrt(pow(xCord[i] - xCord[j], 2) + pow(yCord[i] - yCord[j], 2));
    }

    double max_distance(int source) {
        double dist[n];
        priority_queue<pair<double, int>, vector< pair<double, int> >, greater< pair<double, int> > >q;

        for (int i = 0; i < n; ++i)
            dist[i] = MAX_DIST;

        q.push(make_pair(0.0, source));
        dist[source] = 0.0;

        while (!q.empty()) {
            pair<int, int> curr = q.top();
            double d = curr.first;
            int node = curr.second;
            q.pop();

            if (d > dist[node])
                continue;

            for (int i = 0; i < n; ++i) {
                if (a[node][i] == '1' && dist[i] > d + distance(node, i)) {
                    dist[i] = d + distance(node, i);
                    q.push(make_pair(dist[i], i));
                }
            }
        }

        double maxi = 0;
        for (int i = 0; i < n; ++i)
            if (dist[i] > maxi && dist[i] < MAX_DIST)
                maxi = dist[i], biggest = max(biggest, dist[i]);
        return maxi;
    }

    void fill_furthest() {
        for (int i = 0; i < int(part.size()); ++i) {
            furthest[i] = max_distance(part[i]);
        }
    }
} comp[MAX];

void dfs(int i, int num_comp)
{
    if (visited[i])
        return;
    visited[i] = 1;
    for (int j = 0; j < n; ++j)
        if (a[i][j] == '1' && !visited[j])
            dfs(j, num_comp);
    comp[num_comp].part.push_back(i);
}

int main()
{
    ofstream fout ("cowtour.out");
    ifstream fin ("cowtour.in");

    fin >> n;
    for (int i = 0; i < n; ++i)
        fin >> xCord[i] >> yCord[i];
    for (int i = 0; i < n; ++i)
        fin >> a[i];

    int num_connected = 0;
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            dfs(i, num_connected);
            comp[num_connected++].fill_furthest();
        }
    }

    double min_diameter = MAX_DIST;
    for (int i = 0; i < num_connected; ++i)
    for (int j = i + 1; j < num_connected; ++j)
    for (int x = 0; x < int(comp[i].part.size()); ++x)
    for (int y = 0; y < int(comp[j].part.size()); ++y) {
        double hyp = comp[i].distance(comp[i].part[x], comp[j].part[y]);
        min_diameter = min(min_diameter, comp[i].furthest[x] + hyp + comp[j].furthest[y]);
    }

    fout << fixed << showpoint << setprecision(6) << max(biggest, min_diameter) << endl;

    return 0;
}
