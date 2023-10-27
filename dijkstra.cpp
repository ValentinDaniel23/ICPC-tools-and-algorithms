#include <bits/stdc++.h>

using namespace std;

const int inf = 2e9;

int* Dijstra1(int n, vector< vector< pair<int, int > > > vecini)
{
    int *dist = new int[n+1];
    for(int i=1; i<=n; i++) dist[i] = inf;

    priority_queue< pair<int, int> > coada; /// heap cu proprietatea elementului mai mare
    coada.push({0, 1});
    dist[1] = 0;
    while (!coada.empty())
    {
        pair<int, int> nod = coada.top();
        coada.pop();

        if (nod.first > dist[nod.second])
            continue;

        for (auto child : vecini[nod.second])
        {
            if (child.second + nod.first < dist[child.first])
            {
                dist[child.first] = child.second + nod.first;
                coada.push({dist[child.first], child.first});
            }
        }
    }

    return dist;
}

int *Dijstra2(int n, vector< vector< pair<int, int > > > vecini)
{
    int *dist = new int[n+1];
    for(int i=1; i<=n; i++) dist[i] = inf;

    set< pair<int, int> > s;
    s.insert({0, 1});
    dist[1] = 0;

    while(!s.empty())
    {
        pair<int, int> pereche = *s.begin();
        s.erase(s.begin());
        int nod = pereche.second;

        for(auto vecin:vecini[nod])
        {
            if(dist[nod] + vecin.second < dist[vecin.first])
            {
                if(s.find({dist[vecin.first], vecin.first}) != s.end())
                {
                    s.erase({dist[vecin.first], vecin.first});
                }

                dist[vecin.first] = dist[nod] + vecin.second;
                s.insert({dist[vecin.first], vecin.first});
            }
        }
    }

    return dist;
}

ifstream f("dijkstra.in");
ofstream g("dijkstra.out");

void ShowDist(int n, int *v)
{
    for(int i=2; i<=n; i++)
    {
        if(v[i] != inf) g<<v[i]<<' ';
        else g<<'0'<<' ';
    }
}


int main()
{
    int N, M;
    f>>N>>M;
    vector< vector< pair<int, int > > > Edges(N+1);

    while(M--)
    {
        int x, y,z;
        f>>x>>y>>z;
        Edges[x].push_back({y, z});
    }

    int *Dist;

    //Dist = Dijstra1(N, Edges);
    //ShowDist(N, Dist);

    Dist = Dijstra2(N, Edges);
    ShowDist(N, Dist);
    delete[] Dist;

    /*
    for(int i=1; i<=N; i++)
    {
        cout<<sizeof(Edges[i])<<'\n';
        for(int j=0; j<Edges[i].size(); j++)
        {
            pair<int, int> edge = Edges[i][j];
            cout<<i<<" -> "<<edge.first<<" de cost "<<edge.second<<'\n';
        }
    }
    */

    return 0;
}
