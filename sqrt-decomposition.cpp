#include <bits/stdc++.h>

using namespace std;

const int BLOCK_SIZE = 600; // Division by constants is well optimized by compilers.

void remove(int)
{
}
void add(int)
{
}
int get_answer()
{
}

int block_size;

struct Query
{
    int l, r, idx;
    bool operator<(Query other) const
    {
        if (l / BLOCK_SIZE == other.l / BLOCK_SIZE)
        {
            // In odd blocks sort the right index in ascending order and in even blocks sort it in descending order
            return (l / BLOCK_SIZE & 1) ? (r < other.r) : (r > other.r);
        }
        return l / BLOCK_SIZE < other.l / BLOCK_SIZE;
    }
};

vector<int> mo_s_algorithm(vector<Query> queries)
{
    vector<int> answers(queries.size());
    sort(queries.begin(), queries.end());

    // TODO: initialize data structure

    int cur_l = 1;
    int cur_r = 0;
    // invariant: data structure will always reflect the range [cur_l, cur_r]
    for (Query q : queries)
    {
        while (cur_l > q.l)
        {
            cur_l--;
            add(cur_l);
        }
        while (cur_r < q.r)
        {
            cur_r++;
            add(cur_r);
        }
        while (cur_l < q.l)
        {
            remove(cur_l);
            cur_l++;
        }
        while (cur_r > q.r)
        {
            remove(cur_r);
            cur_r--;
        }
        answers[q.idx] = get_answer();
    }
    return answers;
}