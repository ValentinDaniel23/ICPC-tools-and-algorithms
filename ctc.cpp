#include <bits/stdc++.h>

using namespace std;

int n, m, nrc = 0;
bool viz[100001];
vector<int> G[100001], GT[100001], comp[100001];
stack<int> s;

void dfst(int k)
{
    viz[k] = 1;

    for (int &x : GT[k])
        if (!viz[x])
            dfst(x);
    s.push(k);
}

void dfs(int k)
{
    viz[k] = 1;
    comp[nrc].push_back(k);
    for (int &x : G[k])
        if (!viz[x])
            dfs(x);
}

int main()
{
    cin >> n >> m;

    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        G[x].push_back(y);
        GT[y].push_back(x);
    }

    for (int i = 1; i <= n; i++)
    {
        if (!viz[i])
            dfst(i);
    }

    for (int i = 1; i <= n; i++)
        viz[i] = 0;

    while (!s.empty())
    {
        if (!viz[s.top()])
        {
            dfs(s.top());
            nrc++;
        }
        s.pop();
    }

    cout << nrc << '\n';

    for (int i = 0; i < nrc; i++)
    {
        for (int &x : comp[i])
            cout << x << ' ';
        cout << '\n';
    }

    return 0;
}