#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator
{
public:
    BSTIterator(TreeNode *root);
    bool hasNext();
    int next();
};

queue<TreeNode *> q;

void form_queue(TreeNode *root)
{
    if (root == NULL)
        return;
    form_queue(root->left);
    q.push(root);
    form_queue(root->right);
}

BSTIterator::BSTIterator(TreeNode *root)
{
    // inorder traversal
    form_queue(root);
}

bool BSTIterator::hasNext()
{
    return !q.empty();
}

int BSTIterator::next()
{
    TreeNode *temp = q.front();
    q.pop();
    return temp->val;
}

int main()
{
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(8);

    BSTIterator i = BSTIterator(root);
    while (i.hasNext())
        cout << i.next() << " ";
    cout << endl;
    return 0;
}
