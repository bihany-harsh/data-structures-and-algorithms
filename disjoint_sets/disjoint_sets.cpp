#include <iostream>
using namespace std;

class disjoint_sets
{
public:
    int N;
    int *parent;
    int *size;

    disjoint_sets(int N)
    {
        this->N = N;
        parent = new int[N];
        size = new int[N];
        for (int i = 0; i < N; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int Find(int i);
    bool Is_same_set(int i, int j);
    void Union(int i, int j);
};

int disjoint_sets::Find(int i)
{
    if (parent[i] == i)
        return i;
    else
    {
        parent[i] = Find(parent[i]);
        return parent[i];
    }
}

void disjoint_sets::Union(int i, int j)
{
    int i_id = Find(i);
    int j_id = Find(j);
    if (i_id == j_id)
        return;
    if (size[i_id] > size[j_id])
    {
        parent[j_id] = i_id;
        size[i_id] += size[j_id];
        size[j_id] = 0;
    }
    else
    {
        parent[i_id] = j_id;
        size[j_id] += size[i_id];
        size[i_id] = 0;
    }
}

bool disjoint_sets::Is_same_set(int i, int j)
{
    return Find(i) == Find(j);
}

int main()
{
    disjoint_sets ds(5);
    ds.Union(0, 2);
    ds.Union(4, 2);
    ds.Union(3, 1);
    cout << ds.Is_same_set(0, 4) << endl;
    cout << ds.Is_same_set(1, 4) << endl;

    return 0;
}
