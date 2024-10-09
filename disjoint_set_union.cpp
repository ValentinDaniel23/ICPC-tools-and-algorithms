#include <bits/stdc++.h>

using namespace std;

struct disjoint_set_union
{
    static const int size = 1e6;
    int parent[size], height[size];

    int find_set(int v)
    {
        if (v == parent[v])
            return v;
        return parent[v] = find_set(parent[v]);
    }

    void make_set(int v)
    {
        parent[v] = v;
        height[v] = 0;
    }

    void union_sets(int a, int b)
    {
        a = find_set(a);
        b = find_set(b);
        if (a != b)
        {
            if (height[a] < height[b])
                swap(a, b);
            parent[b] = a;
            if (height[a] == height[b])
                height[a]++;
        }
    }
};