#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right, *parent;
    bool color; // Red -> 1, Black -> 0

    Node(int data)
    {
        this->data = data;
        left = right = parent = NullNode;
        this->color = 1;
        if (data == -1)
            this->color = 0;
    }

    void leftRotation();
    void rightRotation();

    static Node *NullNode;
};

Node *Node::NullNode = new Node(-1);

void Node::leftRotation()
{
    Node *v = this->right;
    this->right = v->left;
    if (v->left != NullNode)
        v->left->parent = this;
    v->parent = this->parent;

    if (this->parent != NullNode)
    {
        if (this->parent->left == this)
            this->parent->left = v;
        else
            this->parent->right = v;
    }
    v->left = this;
    this->parent = v;
}

void Node::rightRotation()
{
    Node *v = this->left;
    this->left = v->right;
    if (v->right != NullNode)
        v->right->parent = this;
    v->parent = this->parent;

    if (this->parent != NullNode)
    {
        if (this->parent->left == this)
            this->parent->left = v;
        else
            this->parent->right = v;
    }
    v->right = this;
    this->parent = v;
}

class RedBlackTree
{
public:
    Node *root;

    RedBlackTree()
    {
        root = Node::NullNode;
    }

    void Insert(int data);
    void InsertFix(Node *v);
};

void RedBlackTree::Insert(int data)
{
    Node *v = new Node(data);
    if (root == Node::NullNode)
    {
        root = v;
        root->color = 0;
        return;
    }
    else
    {
        Node *current = root;
        Node *parent = Node::NullNode;
        while (current != Node::NullNode)
        {
            parent = current;
            if (current->data < data)
                current = current->right;
            else
                current = current->left;
        }
        v->parent = parent;
        if (parent->data < data)
            parent->right = v;
        else
            parent->left = v;
        InsertFix(v);
    }
}

void RedBlackTree::InsertFix(Node *z)
{
    while (z->parent != Node::NullNode && z->parent->color == 1)
    {
        if (z->parent == z->parent->parent->left)
        {
            Node *y = z->parent->parent->right;
            if (y->color == 1)
            {
                z->parent->color = 0;
                y->color = 0;
                z->parent->parent->color = 1;
                z = z->parent->parent;
            }
            else
            {
                if (z == z->parent->right)
                {
                    z = z->parent;
                    z->leftRotation();
                }
                z->parent->color = 0;
                z->parent->parent->color = 1;
                z->parent->parent->rightRotation();
            }
        }
        else
        {
            Node *y = z->parent->parent->left;
            if (y->color == 1)
            {
                z->parent->color = 0;
                y->color = 0;
                z->parent->parent->color = 1;
                z = z->parent->parent;
            }
            else
            {
                if (z == z->parent->left)
                {
                    z = z->parent;
                    z->rightRotation();
                }
                z->parent->color = 0;
                z->parent->parent->color = 1;
                z->parent->parent->leftRotation();
            }
        }
    }
    root->color = 0;
}

// Level order with color
void LevelOrder(Node *root)
{
    if (root == Node::NullNode)
        return;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        cout << temp->data << " ";
        if (temp->left != Node::NullNode)
            q.push(temp->left);
        if (temp->right != Node::NullNode)
            q.push(temp->right);
        if (temp->color == 1)
            cout << "Red"
                 << " ";
        else
            cout << "Black"
                 << " ";
        cout << endl;
    }
}

// Inorder traversal with color

void Inorder(Node *root)
{
    if (root == Node::NullNode)
        return;
    Inorder(root->left);
    cout << root->data << " ";
    if (root->color == 1)
        cout << "Red"
             << " ";
    else
        cout << "Black"
             << " ";
    cout << endl;
    Inorder(root->right);
}

int main()
{
    RedBlackTree rbt;
    rbt.Insert(11);
    rbt.Insert(2);
    rbt.Insert(14);
    rbt.Insert(1);
    rbt.Insert(7);
    rbt.Insert(15);
    rbt.Insert(5);
    rbt.Insert(8);
    rbt.Insert(4);

    Inorder(rbt.root);
    return 0;
}
