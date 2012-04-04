/*
ID: jasper_1
PROG: maze1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <utility>
#include <cstring>
using namespace std;

int dr[] = { -1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

int valid(int r, int c, int w, int h)
{
    return r >= 0 && c >= 0 && r < h && c < w;
}

int main()
{
    ofstream fout ("maze1.out");
    ifstream fin ("maze1.in");

    int w, h;
    fin >> w >> h;
    fin.ignore();
    w = 2 * w + 1;
    h = 2 * h + 1;

    string a[h];
    for (int i = 0; i < h; ++i)
        getline(fin, a[i]);

    queue< pair<int, int> > q;
    int vis[h][w];
    memset(vis, -1, sizeof(vis));
    for (int i = 1; i < w - 1; ++i) {
        if (a[0][i] == ' ')     q.push(make_pair(0, i)), vis[0][i] = 1;
        if (a[h - 1][i] == ' ') q.push(make_pair(h - 1, i)), vis[h - 1][i] = 1;
    }
    for (int i = 1; i < h - 1; ++i) {
        if (a[i][0] == ' ')     q.push(make_pair(i, 0)), vis[i][0] = 1;
        if (a[i][w - 1] == ' ') q.push(make_pair(i, w - 1)), vis[i][w - 1] = 1;
    }

    while (!q.empty()) {
        pair<int, int> curr = q.front();
        int r = curr.first;
        int c = curr.second;
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (valid(nr, nc, w, h) && vis[nr][nc] == -1 && a[nr][nc] == ' ') {
                q.push(make_pair(nr, nc));
                vis[nr][nc] = vis[r][c] + 1;
            }
        }
    }

    int furthest = 0;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (vis[i][j] > furthest)
                furthest = vis[i][j];
        }
    }

    fout << (furthest / 2) << endl;

    return 0;
}
