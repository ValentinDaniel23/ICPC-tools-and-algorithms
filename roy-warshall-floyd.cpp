#include <bits/stdc++.h>

using namespace std;

const int LIM = 1e9;

void Compute_Distances(int n, int **dist)
{
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                if(dist[i][k] != 0 && dist[k][j] != 0 && i != j && ( (dist[i][k] + dist[k][j] < dist[i][j]) || !dist[i][j] )) dist[i][j] = dist[i][k] + dist[k][j];
}

ifstream f("royfloyd.in");
ofstream g("royfloyd.out");

int main()
{
    int N, **V;
    f>>N;
    V = new int* [N+1];
    for(int i = 1; i <= N; i++) V[i] = new int [N+1];
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            f>>V[i][j];
        }
    }
    Compute_Distances(N, V);
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
            g<<V[i][j]<<' ';
        g<<'\n';
    }

    for(int i = 1; i <= N; i++) delete[] V[i];
    delete[] V;

    return 0;
}

