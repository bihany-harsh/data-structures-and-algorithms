#include <iostream>
#include <vector>
#include <list>
using namespace std;

bool is_cylic(vector<list<int>> &adj_list, vector<bool> &visited, vector<bool> &rec_stack, int v)
{
    visited[v] = true;
    rec_stack[v] = true;

    for (int i : adj_list[v])
    {
        if (!visited[i])
        {
            if (is_cylic(adj_list, visited, rec_stack, i))
                return true;
        }
        else if (rec_stack[i])
            return true;
    }
    return false;
}

int is_possible(int N, vector<int> &pre_req, vector<int> &courses)
{
    vector<list<int>> adj_list(N);
    for (int i = 0; i < pre_req.size(); i++)
    {
        adj_list[pre_req[i] - 1].push_back(courses[i] - 1);
    }

    // to detect cycle in directed graph
    vector<bool> visited(N, false);
    vector<bool> rec_stack(N, false);

    for (int i = 0; i < N; i++)
    {
        if (!visited[i])
        {
            if(is_cylic(adj_list, visited, rec_stack, i))
                return 0;
        }
    }

    return 1;
}

int main()
{
    int N = 5;
    vector<int> pre_req = {1, 3, 4, 5};
    vector<int> courses = {2, 1, 5, 3};
    cout << is_possible(N, pre_req, courses) << endl;
    return 0;
}