class Fenwick
{
    vector <int> a;
    int _n;
    int lsb(int i)
    {
        return i & (-i);
    }
public :

    Fenwick (int n)
    {
        a.resize(n + 1);
        _n = n;
    }

    void update(int pos, int val)
    {
        for(int i = pos; i <= _n; i += lsb(i))
            a[i] += val;
    }

    int query(int pos)
    {
        int ans = 0;
        for(int i = pos; i >= 1; i -= lsb(i))
            ans += a[i];
        return ans;
    }
};
