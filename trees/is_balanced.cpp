#include <iostream>
#include <utility>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

pair<bool, int> isBalanced_util(TreeNode* root)
{
    // stores if the tree is balanced and the height of the tree
    if (root == NULL)
        return make_pair(true, 0);
    pair<bool, int> left = isBalanced_util(root->left);
    pair<bool, int> right = isBalanced_util(root->right);

    int ht = max(left.second, right.second) + 1;
    bool balanced = left.first && right.first && abs(left.second - right.second) <= 1;
    return make_pair(balanced, ht);
}

int isBalanced(TreeNode* root)
{
    return isBalanced_util(root).first;
}