#include <iostream>
#include <queue>
#include <fstream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node *parent;

    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
        parent = NULL;
    }
};

class Tree
{
public:
    Node *root;
    Tree()
    {
        root = NULL;
    }

    bool Search(int data);
};

bool Tree::Search(int data)
{
    Node *current = root;
    bool found = false;
    while (!found)
    {
        if (current == NULL)
            return false;
        else if (current->data == data)
            return true;
        else if (current->data > data)
            current = current->left;
        else
            current = current->right;
    }
    return false;
}

void fill_array(int *arr, int n)
{
    // random number generator
    srand(time(0));

    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 100;
    }
}

void createTree(Tree *tree, int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        Node *new_node = new Node(arr[i]);
        if (tree->root == NULL)
        {
            tree->root = new_node;
        }
        else
        {
            Node *current = tree->root;
            Node *parent = NULL;
            while (true)
            {
                parent = current;
                if (arr[i] < current->data)
                {
                    current = current->left;
                    if (current == NULL)
                    {
                        parent->left = new_node;
                        new_node->parent = parent;
                        break;
                    }
                }
                else
                {
                    current = current->right;
                    if (current == NULL)
                    {
                        parent->right = new_node;
                        new_node->parent = parent;
                        break;
                    }
                }
            }
        }
    }
}

// Level Order Print

void LevelOrderPrint(Tree *tree)
{
    if (tree->root == NULL)
        return;

    Node *root = tree->root;
    queue<Node *> Q1, Q2;

    if (root == NULL)
        return;

    Q1.push(root);
    while (!Q1.empty() || !Q2.empty())
    {
        while (!Q1.empty())
        {
            Node *current = Q1.front();
            Q1.pop();
            cout << current->data << " ";
            if (current->left != NULL)
                Q2.push(current->left);
            if (current->right != NULL)
                Q2.push(current->right);
        }
        cout << endl;
        while (!Q2.empty())
        {
            Node *current = Q2.front();
            Q2.pop();
            cout << current->data << " ";
            if (current->left != NULL)
                Q1.push(current->left);
            if (current->right != NULL)
                Q1.push(current->right);
        }
        cout << endl;
    }
}

int main()
{
    Tree *tree = new Tree();
    int n = 50;
    int *arr = new int[n];
    fill_array(arr, n);
    createTree(tree, arr, n);

    ofstream file;
    file.open("tree.txt");
    streambuf *stream_buffer_cout = cout.rdbuf();
    cout.rdbuf(file.rdbuf());
    LevelOrderPrint(tree);
    cout.rdbuf(stream_buffer_cout);
    file.close();

    cout << "Finding 10: " << tree->Search(10) << endl;
    

    return 0;
}