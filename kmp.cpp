#include <bits/stdc++.h>

using namespace std;

vector<int> make_prefix(string &s, int n)
{
    int q = 0;
    vector<int> p(n + 1);

    p[0] = p[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        while (q && s[q + 1] != s[i])
            q = p[q];
        if (s[q + 1] == s[i])
            q++;
        p[i] = q;
    }

    return p;
}

int main()
{
    string s;
    cin >> s;

    s = " " + s;

    vector<int> p = make_prefix(s, s.size() - 1);

    for (const int &x : p)
        cout << x << ' ';

    return 0;
}