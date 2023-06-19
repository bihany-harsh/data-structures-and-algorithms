#include <iostream>
#include <vector>
using namespace std;

class Graph
{
public:
    int V;
    vector<vector<int>> adj_matrix;

    Graph(int V);
    void add_edge(int u, int v, int weight);
    vector<vector<int>> floyd_warshall();
};

Graph::Graph(int V)
{
    this->V = V;
    adj_matrix = vector<vector<int>>(V, vector<int>(V, INT_MAX));
    for (int i = 0; i < V; i++)
        adj_matrix[i][i] = 0;
}

void Graph::add_edge(int u, int v, int weight)
{
    adj_matrix[u][v] = weight;
}

vector<vector<int>> Graph::floyd_warshall()
{
    vector<vector<int>> distance = adj_matrix;
    
    for (int k = 0; k < V; k++)
    {
        for (int i = 0; i < V; i++)
        {
            if (distance[i][k] == INT_MAX)
                continue;
            for (int j = 0; j < V; j++)
            {
                if (distance[k][j] == INT_MAX)
                    continue;
                if (distance[i][j] > distance[i][k] + distance[k][j])
                    distance[i][j] = distance[i][k] + distance[k][j];
            }
        }
    }
    return distance;
}

int main()
{
    int V = 5;
    Graph g(V);
    g.add_edge(0, 1, 3);
    g.add_edge(0, 2, 8);
    g.add_edge(0, 4, -4);
    g.add_edge(1, 3, 1);
    g.add_edge(1, 4, 7);
    g.add_edge(2, 1, 4);
    g.add_edge(3, 0, 2);
    g.add_edge(3, 2, -5);
    g.add_edge(4, 3, 6);

    vector<vector<int>> distance = g.floyd_warshall();

    for (int i = 0; i < V; i++)
    {
        cout << "Shortest distance from vertex " << i << " to all other vertices:\n";
        for (int j = 0; j < V; j++)
        {
            if (distance[i][j] == INT_MAX)
                cout << "INF ";
            else
                cout << distance[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}