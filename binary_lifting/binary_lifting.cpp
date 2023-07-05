// the problem is to find the kth ancestor of a node in a tree
// preprocessing: O(n*log(n))
// for each query O(log(n))
#include <iostream>
#include <vector>
using namespace std;

class TreeAncestor {
    vector<vector<int>> up; // int up[N][20];
    vector<int> depth;
    int LOG;
public:
    TreeAncestor(int n, vector<int>& parent) {
        LOG = 0;
        while((1 << LOG) <= n) {
            LOG++;
        }
        // LOG = ceil(log2(n))
        up = vector<vector<int>>(n, vector<int>(LOG));
        depth = vector<int>(n);
        // up[v][j] is 2^j -th ancestor of node v
        parent[0] = 0;
        for(int v = 0; v < n; v++) {
            up[v][0] = parent[v];
            if(v != 0) {
                depth[v] = depth[parent[v]] + 1;
            }
            for(int j = 1; j < LOG; j++) {
                up[v][j] = up[ up[v][j-1] ][j-1];
            }
        }
    }
    int getKthAncestor(int node, int k) {
        if(depth[node] < k) {
            return -1;
        }
        // for eg: 19th ancestor of node is the (16+2+1)st ancestor of node
        for(int j = LOG - 1; j >= 0; j--) {
            if(k >= (1 << j)) {
                node = up[node][j];
                k -= 1 << j;
            }
        }
        return node;
    }
};

int main()
{
    int n = 9;
    vector<int> parent = {-1, 0, 0, 0, 1, 2, 2, 2, 3};
    TreeAncestor ta (n, parent);

    cout << ta.getKthAncestor(4, 1) << endl;
    cout << ta.getKthAncestor(5, 2) << endl;

    return 0;
}