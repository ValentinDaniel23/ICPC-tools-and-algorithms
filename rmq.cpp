#include <bits/stdc++.h>

using namespace std;

ifstream f("rmq.in");
ofstream g("rmq.out");

void Compute_Rmq(int n, int *v, int *p, int **rmq)
{
    int llog = p[n];

    for(int i = 0; i <= llog ; i++)
    {
        for(int j = 1; j <= n - (1<<i) + 1; j++)
        {
            if(i == 0) rmq[j][i] = v[j];
            else rmq[j][i] = min(rmq[j][i-1], rmq[j+(1<<(i-1))][i-1]);
        }
    }
}

int main()
{
    int N, M, *V, **RMQ, *P;
    f>>N>>M;
    V = new int[N + 1];
    P = new int[N + 1];
    RMQ = new int*[N + 1];
    for(int i = 1; i <= N; i++)
    {
        f>>V[i];
        if(i == 1) P[i] = 0;
        else P[i] = P[i/2] + 1;
    }
    for(int i = 1; i <= N; i++) RMQ[i] = new int[P[N] + 1];

    Compute_Rmq(N, V, P, RMQ);

    while(M--)
    {
        int a, b;
        f>>a>>b;
        if(a > b) swap(a, b);
        int dim = b - a + 1;
        g<<min(RMQ[a][P[dim]], RMQ[b-(1<<P[dim])+1][P[dim]])<<'\n';
    }

    for(int i = 1; i <= N; i++) delete[] RMQ[i];
    delete[] V;
    delete[] P;
    delete[] RMQ;

    return 0;
}
