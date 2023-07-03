#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* find_parent(TreeNode* root, TreeNode* split)
{
    if (root == NULL)
        return NULL;
    if (root->left == split || root->right == split)
        return root;
    TreeNode* left = find_parent(root->left, split);
    TreeNode* right = find_parent(root->right, split);
    if (left)
        return left;
    if (right)
        return right;
    return NULL;
}

void Delete(TreeNode *root, TreeNode *node)
{
    TreeNode* split = node;
    // split has to be node itself because it is a half node
    TreeNode* parent = find_parent(root, split);
    TreeNode* child = NULL;
    if (split->left != NULL)
        child = split->left;
    else
        child = split->right;
    
    if (parent == NULL)
        root = child;
    else if (parent->left == split)
        parent->left = child;
    else
        parent->right = child;
    
    delete split;
}

TreeNode *delete_half_nodes(TreeNode *root)
{
    // iterating and finding half nodes deleting them otw
    if (root == NULL)
        return NULL;
    root->left = delete_half_nodes(root->left); 
    root->right = delete_half_nodes(root->right);
    if (root->left == NULL && root->right == NULL)
        return root;
    if (root->left == NULL)
    {
        TreeNode* temp = root->right;
        delete root;
        return temp;
    }
    if (root->right == NULL)
    {
        TreeNode* temp = root->left;
        delete root;
        return temp;
    }
    return root;
}

int main()
{

    return 0;
}