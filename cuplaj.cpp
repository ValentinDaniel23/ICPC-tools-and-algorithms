#include <bits/stdc++.h>

using namespace std;

#define MAXN 10005
vector<int> G[MAXN];

int l[MAXN], r[MAXN], u[MAXN];

int pairup(int node)
{
    if (u[node])
        return 0;
    u[node] = 1;

    for (int &x : G[node])
    {
        if (r[x] == 0)
        {
            l[node] = x;
            r[x] = node;
            return 1;
        }
    }

    for (int &x : G[node])
    {
        if (pairup(r[x]))
        {
            l[node] = x;
            r[x] = node;
            return 1;
        }
    }

    return 0;
}

int main()
{
    int n, m, edges;

    cin >> n >> m >> edges;

    while (edges--)
    {
        int x, y;
        cin >> x >> y;
        G[x].push_back(y);
    }

    int change = 1;

    while (change == 1)
    {
        change = 0;
        for (int i = 1; i <= n; i++)
            u[i] = 0;
        for (int i = 1; i <= n; i++)
            if (l[i] == 0)
                change |= pairup(i);
    }

    int cnt = 0;
    for (int i = 1; i <= n; i++)
        if (l[i])
            cnt++;

    cout << cnt << '\n';

    for (int i = 1; i <= n; i++)
        if (l[i])
            cout << i << ' ' << l[i] << '\n';

    return 0;
}