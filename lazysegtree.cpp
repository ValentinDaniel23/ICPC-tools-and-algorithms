#include <vector>

using namespace std;

struct SegTree
{
    int n;
    vector<int> aint;
    vector<bool> lazy;

    SegTree(int n) : n(n)
    {
        aint.resize(4 * n + 1);
        lazy.resize(4 * n + 1);
    }

    void build(int node, int st, int dr)
    {
        if (st == dr)
        {
            return;
        }
        else
        {
            int mid = (st + dr) / 2;
            int leftChild = 2 * node;
            int rightChild = 2 * node + 1;

            build(leftChild, st, mid);
            build(rightChild, mid + 1, dr);
        }
    }

    void query(int node, int st, int dr, int L, int R)
    {
        if (L > R)
        {
            return;
        }
        if (R < st || dr < L)
        {
            return;
        }

        if (L <= st && dr <= R)
        {

            return;
        }
        int mid = (st + dr) / 2;
        int leftChild = 2 * node;
        int rightChild = 2 * node + 1;

        if (lazy[node])
        {
            /// la stanga

            /// la dreapta

            /// golesc
            lazy[node] = false;
        }

        query(leftChild, st, mid, L, R);
        query(rightChild, mid + 1, dr, L, R);
    }

    void update(int node, int st, int dr, int L, int R)
    {
        if (L > R)
        {
            return;
        }
        if (R < st || dr < L)
        {
            return;
        }

        if (L <= st && dr <= R)
        {
            return;
        }

        int mid = (st + dr) / 2;
        int leftChild = 2 * node;
        int rightChild = 2 * node + 1;

        if (lazy[node])
        {
            /// la stanga

            /// la dreapta

            /// golesc
            lazy[node] = false;
        }

        update(leftChild, st, mid, L, R);
        update(rightChild, mid + 1, dr, L, R);
    }
};