#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <list>
#include <climits>
using namespace std;

int string_diff(string &a, string &b)
{
    if (a.size() != b.size())
        return -1;

    int diff = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] != b[i])
            diff++;
    }
    return diff;
}

int transform_steps(string &A, string &B, vector<string> &mediate_strings)
{
    // edges b/w those strings which are 1 char apart
    // find shortest path b/w A and B

    // string and its index in mediate_strings; if A -> 0, B -> mediate_strings.size() + 1, o/w (1 + index) for mediate_strings
    vector<list<pair<int, string>>> adj_list(mediate_strings.size() + 2);

    // edges for A and B
    for (int i = 0; i < mediate_strings.size(); i++)
    {
        int diff = string_diff(A, mediate_strings[i]);
        if (diff == 1)
        {
            adj_list[0].push_back({1 + i, mediate_strings[i]});
            adj_list[1 + i].push_back({0, A});
        }
        diff = string_diff(B, mediate_strings[i]);
        if (diff == 1)
        {
            adj_list[mediate_strings.size() + 1].push_back({1 + i, mediate_strings[i]});
            adj_list[1 + i].push_back({mediate_strings.size() + 1, B});
        }
    }

    // b/w A and B
    int diff = string_diff(A, B);
    if (diff == 1)
    {
        adj_list[0].push_back({mediate_strings.size() + 1, B});
        adj_list[mediate_strings.size() + 1].push_back({0, A});
    }

    // other edges
    for (int i = 0; i < mediate_strings.size(); i++)
    {
        for (int j = i + 1; j < mediate_strings.size(); j++)
        {
            int diff = string_diff(mediate_strings[i], mediate_strings[j]);
            if (diff == 1)
            {
                adj_list[1 + i].push_back({1 + j, mediate_strings[j]});
                adj_list[1 + j].push_back({1 + i, mediate_strings[i]});
            }
        }
    }

    // BFS
    vector<bool> visited(mediate_strings.size() + 2, false);
    vector<int> distance(mediate_strings.size() + 2, INT_MAX);

    queue<int> q;
    q.push(0);
    visited[0] = true;
    distance[0] = 0;

    while (!q.empty())
    {
        int v = q.front();
        q.pop();

        for (auto i : adj_list[v])
        {
            if (!visited[i.first])
            {
                visited[i.first] = true;
                distance[i.first] = distance[v] + 1;
                q.push(i.first);
            }
        }
    }

    if (!visited[mediate_strings.size() + 1])
        return 0;
    return distance[mediate_strings.size() + 1] + 1;
}

int main()
{
    string A = "hit";
    string B = "cog";
    vector<string> mediate_strings = {"hot", "dot", "dog", "lot", "log"};
    cout << transform_steps(A, B, mediate_strings) << endl;
    return 0;
}