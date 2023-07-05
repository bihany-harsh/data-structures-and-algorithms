// a mixture of graph and dp
// the problem is: given a weighted tree find the max edge between a pair of vertices
// in the query
#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int main()
{
    vector<vector<int>> graph = {{1, 2, 11}, {1, 3, 1}, {2, 4, 12}, {2, 5, 100}};
    vector<vector<int>> queries = {{3, 5}, {2, 3}};
    // vector<int> ans = max_edge_queries(graph, queries);
    // for (auto i : ans)
    //     cout << i << " ";
    // cout << endl;
    return 0;
}