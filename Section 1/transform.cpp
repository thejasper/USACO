/*
ID: jasper_1
PROG: transform
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int n;
typedef vector<string> vs;

int same(vs& a, vs& b)
{
    for (int i = 0; i < n; ++i)
        if (a[i] != b[i])
            return 0;
    return 1;
}

vs rotate_once(vs& a)
{
    vs ret(n, string(n, ' '));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            ret[j][n - i - 1] = a[i][j];
        }
    }
    return ret;
}

vs mirror(vs &a)
{
    vs res;
    for (int i = 0; i < n; ++i) {
        string rev(a[i].rbegin(), a[i].rend());
        res.push_back(rev);
    }
    return res;
}

int check_rotate(vs& orig, vs& res)
{
    vs copy(orig.begin(), orig.end());

    for (int i = 1; i <= 3; ++i) {
        copy = rotate_once(copy);
        if (same(copy, res))
            return i;
    }
    return 0;
}

int check_mirror(vs &orig, vs& res)
{
    vs mirrored = mirror(orig);
    return same(mirrored, res);
}

int check_combined(vs& orig, vs& res)
{
    vs mirrored = mirror(orig);
    return check_rotate(mirrored, res);
}

int find_transformation(vs& orig, vs&res)
{
    int ret = check_rotate(orig, res);
    if (ret)
        return ret;
    if (check_mirror(orig, res))
        return 4;
    if (check_combined(orig, res))
        return 5;
    if (same(orig, res))
        return 6;
    return 7;
}

int main()
{
    ofstream fout ("transform.out");
    ifstream fin ("transform.in");

    fin >> n;

    vs orig;
    vs res;

    for (int i = 0; i < n; ++i) {
        string s;
        fin >> s;
        orig.push_back(s);
    }

    for (int i = 0; i < n; ++i) {
        string s;
        fin >> s;
        res.push_back(s);
    }

    fout << find_transformation(orig, res) << endl;

    return 0;
}
