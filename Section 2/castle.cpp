/*
ID: jasper_1
PROG: castle
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

#define MAX 55

int m, n; //rij, col
int a[MAX][MAX];
int vis[MAX][MAX];
int curr_room;

void dfs(int r, int c)
{
    if (vis[r][c])
        return;
    vis[r][c] = 1;
    if (!(a[r][c] & 1))
        dfs(r, c - 1);
    if (!(a[r][c] & 2))
        dfs(r - 1, c);
    if (!(a[r][c] & 4))
        dfs(r, c + 1);
    if (!(a[r][c] & 8))
        dfs(r + 1, c);
    ++curr_room;
}

vector<int> get_room_cnts()
{
    memset(vis, 0, sizeof(vis));
    vector<int> rooms;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (!vis[i][j]) {
                curr_room = 0;
                dfs(i, j);
                rooms.push_back(curr_room);
            }
        }
    }
    return rooms;
}

int main()
{
    ofstream fout ("castle.out");
    ifstream fin ("castle.in");

    fin >> n >> m;
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            fin >> a[i][j];

    vector<int> rooms = get_room_cnts();

    fout << int(rooms.size()) << endl;
    int biggest = *max_element(rooms.begin(), rooms.end());
    fout << biggest << endl;

    int bestr = 0, bestc = 0, dir = 0;
    for (int j = 0; j < n; ++j) { //zover mogelijk west
        for (int i = m - 1; i >= 0; --i) {
            for (int k = 2; k <= 4; k += 2) {
                //enkel omhoog in laatste kolom, enkel opzij in eerste rij
                if ((j == n - 1 && k == 4) || (i == 0 && k == 2))
                    continue;
                if (a[i][j] & k) {
                    a[i][j] &= ~k; //muur wegdoen
                    if (k == 2) a[i - 1][j] &= ~8; else a[i][j + 1] &= ~1;

                    //kon beter door grootte kamer op te slaan 
                    //zodat het niet opnieuw moet berekend worden
                    rooms = get_room_cnts();
                    int curr = *max_element(rooms.begin(), rooms.end());

                    a[i][j] |= k; //muur terugzetten
                    if (k == 2) a[i - 1][j] |= 8; else a[i][j + 1] |= 1;

                    if (curr > biggest)
                        biggest = curr, bestr = i, bestc = j, dir = k;
                }
            }
        }
    }

    fout << biggest << endl;
    fout << bestr + 1 << ' ' << bestc + 1 << ' ' << (dir == 2 ? 'N' : 'E') << endl;

    return 0;
}
