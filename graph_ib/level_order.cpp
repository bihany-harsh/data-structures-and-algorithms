#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x)
    {
        this->val = x;
        this->left = NULL;
        this->right = NULL;
    }
};

vector<vector<int>> level_order(TreeNode* root)
{
    vector<vector<int>> result;
    if (root == NULL)
        return result;
    
    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty())
    {
        int size = q.size();
        vector<int> level;
        for (int i = 0; i < size; i++)
        {
            TreeNode* v = q.front();
            q.pop();
            level.push_back(v->val);
            if (v->left != NULL)
                q.push(v->left);
            if (v->right != NULL)
                q.push(v->right);
        }
        result.push_back(level);
    }

    return result;
}

int main()
{
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    vector<vector<int>> result = level_order(root);

    for (int i = 0; i < result.size(); i++)
    {
        cout << "[";
        for (int j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j] << ", ";
        }
        cout << "]" << endl;
    }
}