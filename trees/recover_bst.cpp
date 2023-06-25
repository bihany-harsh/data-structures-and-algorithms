#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x)
    {
        left = NULL;
        right = NULL;
    }
};

void utility(TreeNode *root, int &ans1, int &ans2, int prev)
{
    if (root == NULL)
        return;
    utility(root->left, ans1, ans2, prev);
    if (root->val > prev)
        prev = root->val;
    else
    {
        if (ans1 == INT_MIN)
        {
            ans1 = prev;
            ans2 = root->val;
        }
        else
        {
            ans2 = root->val;
            return;
        }
        prev = root->val;
    }
    prev = root->val;
    utility(root->right, ans1, ans2, prev);
}

vector<int> recover_bst(TreeNode *root)
{
    int ans1 = INT_MIN, ans2 = INT_MIN, prev = INT_MIN;
    utility(root, ans1, ans2, prev);
}