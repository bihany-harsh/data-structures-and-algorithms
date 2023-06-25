#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void make_bst(vector<int> &arr, int left, int right, int &index)
{
    if (index >= arr.size())
        return;
    if (arr[index] <= left || arr[index] >= right)
        return;
    int root_val = arr[index];
    index++;
    make_bst(arr, left, root_val, index);
    make_bst(arr, root_val, right, index);
}

bool is_possible_tree(vector<int> &arr)
{
    // given preorder traversal to show if tree is possible.
    int index = 0;
    make_bst(arr, INT_MIN, INT_MAX, index);
    if (index < arr.size())
        return false;
    return true;
}