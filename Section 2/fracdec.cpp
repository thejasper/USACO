/*
ID: jasper_1
PROG: fracdec
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int pos[1000000];

string num(int n)
{
    if (!n) return "0";
    string ret = "";
    while (n > 0) {
        ret = char(n % 10 + '0') + ret;
        n /= 10;
    }
    return ret;
}

string fraction(int tel, int noem)
{
    string q = ".";
    int add;

    while (1) {
        if (pos[tel] == 0)
            pos[tel] = q.size();
        else
            return q.substr(0, pos[tel]) + "(" + q.substr(pos[tel]) + ")";

        if (tel < noem)
            tel *= 10;

        add = 0;
        if (tel >= noem) {
            add = tel / noem;
            tel -= add * noem;
        }
        q += num(add);

        if (tel == 0)
            break;
    }

    return q;
}

int main()
{
    ofstream fout ("fracdec.out");
    ifstream fin ("fracdec.in");

    int tel, noem;
    fin >> tel >> noem;

    string ans = num(tel / noem);
    if (tel % noem == 0)
        ans += ".0";
    else
        ans += fraction(tel % noem, noem);

    for (int i = 0; i < int(ans.size()); ++i)  {
        fout << ans[i];
        if ((i + 1) % 76 == 0 || i == int(ans.size()) - 1)
            fout << endl;
    }

    return 0;
}
