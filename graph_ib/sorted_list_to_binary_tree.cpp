#include <iostream>
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

struct ListNode
{
    int val;
    ListNode *next;

    ListNode(int x)
    {
        this->val = x;
        this->next = NULL;
    }
};

TreeNode * sorted_list_to_tree_util(ListNode **head, int start, int end)
{
    if(start > end)
        return NULL;
    
    int mid = (start + end) / 2;
    TreeNode *left = sorted_list_to_tree_util(head, start, mid - 1);
    TreeNode *root = new TreeNode((*head)->val);
    root->left = left;
    *head = (*head)->next;
    root->right = sorted_list_to_tree_util(head, mid + 1, end);
    return root;
}

TreeNode * sorted_list_to_tree(ListNode *head)
{
    if (!head) return NULL;  
    ListNode *temp = head;  
    int n = 0;
    while(temp)
    {
        n++;
        temp = temp->next; 
    }

    return sorted_list_to_tree_util(&head, 0, n - 1);
}