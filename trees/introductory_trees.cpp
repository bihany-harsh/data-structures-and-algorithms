#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <climits>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node *parent;

    Node(int x)
    {
        this->data = x;
        this->left = NULL;
        this->right = NULL;
        this->parent = NULL;
    }
};

void Inorder_walk_util(Node *root, vector<int> &res)
{
    if (root != NULL)
    {
        Inorder_walk_util(root->left, res);
        res.push_back(root->data);
        Inorder_walk_util(root->right, res);
    }
}

vector<int> Inorder_walk(Node *root)
{
    vector<int> res;
    Inorder_walk_util(root, res);
    return res;
}

Node *Search(Node *root, int x)
{
    if (root == NULL || root->data == x)
        return root;
    if (root->data < x)
        return Search(root->right, x);
    else
        return Search(root->left, x);
}

Node *Minumum(Node *root)
{
    if (root == NULL)
        return root;
    Node *iter = root;
    while (iter->left)
        iter = iter->left;
    return iter;
}

Node *Maximum(Node *root)
{
    if (root == NULL)
        return root;
    Node *iter = root;
    while (iter->right)
        iter = iter->right;
    return iter;
}

Node *Successor(Node *node)
{
    if (node->right != NULL)
        return Minumum(node->right);
    Node *p = node->parent;
    Node *iter = node;
    while (p != NULL && p->right == iter)
    {
        iter = p;
        p = p->parent;
    }
    return p;
}

Node *Predecessor(Node *node)
{
    if (node->left != NULL)
        return Maximum(node->left);
    Node *p = node->parent;
    Node *iter = node;
    while (p != NULL && p->left == iter)
    {
        iter = p;
        p = p->parent;
    }
    return p;
}

void Insert(Node *root, int x)
{
    Node *node = new Node(x);
    Node *curr = root;
    Node *prev = NULL;

    while (curr != NULL)
    {
        prev = curr;
        if (curr->data > x)
            curr = curr->left;
        else
            curr = curr->right;
    }
    node->parent = prev;
    if (prev == NULL) // empty tree
        root = node;
    else if (prev->data > x)
        prev->left = node;
    else
        prev->right = node;
}

void Delete(Node *root, Node *node)
{
    Node *split = NULL;
    if (node->left == NULL || node->right == NULL)
        split = node;
    else
        split = Successor(node);

    Node *child = NULL;
    if (split->left != NULL)
        child = split->left;
    else
        child = split->right;

    if (child != NULL)
        child->parent = split->parent;

    if (split->parent == NULL)
        root = child; // split is root
    else if (split == split->parent->left)
        split->parent->left = child;
    else
        split->parent->right = child;

    if (split != node)
        node->data = split->data;

    delete split;
}

Node *tree_from_sorted_array_util(vector<int> &arr, int i, int j)
{
    if (i > j)
        return NULL;

    int mid = (i + j) / 2;
    Node *root = new Node(arr[mid]);
    Node *left = tree_from_sorted_array_util(arr, i, mid - 1);
    root->left = left;
    if (left != NULL)
        left->parent = root;
    Node *right = tree_from_sorted_array_util(arr, mid + 1, j);
    root->right = right;
    if (right != NULL)
        right->parent = root;

    return root;
}

Node *tree_from_sorted_array(vector<int> &arr)
{
    return tree_from_sorted_array_util(arr, 0, arr.size() - 1);
}

Node *balance_bst(Node *root)
{
    vector<int> inorder = Inorder_walk(root);
    return tree_from_sorted_array(inorder);
}

bool is_bst(Node *root)
{
    if (root == NULL)
        return true;
    if (root->left != NULL)
    {
        if (root->left->data > root->data)
            return false;
    }
    if (root->right != NULL)
    {
        if (root->right->data <= root->data)
            return false;
    }
    if (!is_bst(root->left) || !is_bst(root->right))
        return false;

    return true;
}

Node *tree_from_level_order(vector<int> &arr)
{
    if (arr.size() == 0)
        return NULL;

    queue<pair<Node *, pair<int, int>>> q;
    Node *head = new Node(arr[0]);
    Node *root = head;

    q.push(make_pair(root, make_pair(INT_MIN, INT_MAX)));
    for (int i = 1; i < arr.size(); i++)
    {
        Node *node = q.front().first;
        pair<int, int> range = q.front().second;

        if (arr[i] < range.second && arr[i] > range.first)
        {
            if (arr[i] < node->data)
            {
                if (node->left != NULL)
                {
                    q.pop();
                    i--;
                    continue;
                }
                node->left = new Node(arr[i]);
                q.push(make_pair(node->left, make_pair(range.first, node->data)));
            }
            else
            {
                q.pop();
                node->right = new Node(arr[i]);
                q.push(make_pair(node->right, make_pair(node->data, range.second)));
            }
        }
        else
        {
            q.pop();
            i--;
        }
    }
    return head;
}

bool is_level_order(vector<int> &arr)
{
    // to check whether the given array is a level order traversal of a BST
    if (arr.size() == 0)
        return true;
    queue<pair<int, pair<int, int>>> q;
    q.push(make_pair(arr[0], make_pair(INT_MIN, INT_MAX)));
    int k = 1;
    while (k != arr.size() && !q.empty())
    {
        pair<int, pair<int, int>> node = q.front();
        q.pop();
        if (k < arr.size() && arr[k] < node.first && arr[k] > node.second.first)
        {
            q.push(make_pair(arr[k], make_pair(node.second.first, node.first)));
            k++;
        }
        if (k < arr.size() && arr[k] > node.first && arr[k] < node.second.second)
        {
            q.push(make_pair(arr[k], make_pair(node.first, node.second.second)));
            k++;
        }
    }
    if (k == arr.size())
        return true;
    else
        return false;
}

void morris_inorder_util(Node *root, vector<int> &res)
{
    Node *curr = root;
    while (curr != NULL)
    {
        if (curr->left == NULL)
        {
            res.push_back(curr->data);
            curr = curr->right;
        }
        else
        {
            Node *predecessor = curr->left;
            while (predecessor->right != NULL && predecessor->right != curr)
            {
                predecessor = predecessor->right;
            }

            if (predecessor->right == NULL)
            {
                predecessor->right = curr;
                curr = curr->left;
            }
            else
            {
                predecessor->right = NULL;
                res.push_back(curr->data);
                curr = curr->right;
            }
        }
    }
}

vector<int> morris_inorder(Node *root)
{
    vector<int> res;
    morris_inorder_util(root, res);
    return res;
}

void Level_order_util(Node *root, vector<int> &arr)
{
    if (root == NULL)
        return;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *node = q.front();
        q.pop();
        arr.push_back(node->data);
        if (node->left != NULL)
            q.push(node->left);
        if (node->right != NULL)
            q.push(node->right);
    }
}

vector<int> Level_order(Node *root)
{
    vector<int> res;
    Level_order_util(root, res);
    return res;
}

Node *flatten_bst(Node* root)
{
    if(root == NULL)
        return NULL;
    Node* left = flatten_bst(root->left);
    Node* right = flatten_bst(root->right);
    root->left = NULL;
    root->right = NULL;
    if(left != NULL)
    {
        Node* temp = left;
        while(temp->right != NULL)
            temp = temp->right;
        temp->right = root;
        root->left = temp;
    }
    if(right != NULL)
    {
        root->right = right;
        right->left = root;
    }
    if(left != NULL)
        return left;
    else
        return root;
}

int main()
{
    vector<int> arr = {7, 4, 12, 3, 6, 8, 1, 5, 10};
    Node *root = tree_from_level_order(arr);

    vector<int> level_order = Level_order(root);
    for (auto i : level_order)
        cout << i << " ";
    cout << endl;

    Node* head = flatten_bst(root);
    Node* temp = head;
    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->right;
    }
    cout<<endl;

    return 0;
}