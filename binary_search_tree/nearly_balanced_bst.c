#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#include <stdbool.h>

int *arr;

struct Node
{
    int data;
    struct Node *parent;
    struct Node *left;
    struct Node *right;
    int size;
};

// *****LevelOrder print using queue for visualization*****

struct queueNode
{
    struct Node *node;
    struct queueNode *next;
};

struct queueNode *createQueueNode(struct Node *node)
{
    struct queueNode *temp = (struct queueNode *)malloc(sizeof(struct queueNode));
    temp->node = node;
    temp->next = NULL;

    return temp;
}

void Enqueue(struct queueNode **queueHead, struct Node *x)
{
    struct queueNode *temp = createQueueNode(x);
    if (*queueHead == NULL)
    {
        *queueHead = temp;
        return;
    }
    struct queueNode *traveller = *queueHead;
    while (traveller->next != NULL)
    {
        traveller = traveller->next;
    }
    traveller->next = temp;
}

struct Node *Dequeue(struct queueNode **queueHead)
{
    if (*queueHead == NULL)
    {
        return NULL;
    }
    struct Node *temp = (*queueHead)->node;
    *queueHead = (*queueHead)->next;

    return temp;
}

bool isEmpty(struct queueNode *queueHead)
{
    if (queueHead == NULL)
    {
        return true;
    }
    return false;
}

void LevelOrderPrint(struct Node *rootNode)
{
    struct queueNode *queueHead = NULL;
    Enqueue(&queueHead, rootNode);
    Enqueue(&queueHead, NULL);
    while (!isEmpty(queueHead))
    {
        struct Node *temp = Dequeue(&queueHead);
        if (temp == NULL)
        {
            printf("\n");
            if (!isEmpty(queueHead))
            {
                Enqueue(&queueHead, NULL);
            }
        }
        else
        {
            printf("%d ", temp->data);
            if (temp->left != NULL)
            {
                Enqueue(&queueHead, temp->left);
            }
            if (temp->right != NULL)
            {
                Enqueue(&queueHead, temp->right);
            }
        }
    }
}

// ***** END OF SNIPPET *****

struct Node *createValueNode(int val)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = val;
    temp->parent = NULL;
    temp->left = NULL;
    temp->right = NULL;
    temp->size = 1;

    return temp;
}

bool isNearlyBalanced(struct Node *rootNode)
{
    if (rootNode == NULL)
        return true;
    int leftSize = rootNode->left == NULL ? 0 : rootNode->left->size;
    int rightSize = rootNode->right == NULL ? 0 : rootNode->right->size;
    int totalSize = rootNode->size;
    if (leftSize <= (3 * totalSize) / 4 && rightSize <= (3 * totalSize) / 4)
        return true;
    return false;
}

int *createArray(struct Node *rootNode, int *arr, int *index)
{
    if (rootNode == NULL)
    {
        return arr;
    }
    arr = createArray(rootNode->left, arr, index);
    arr[*index] = rootNode->data;
    *index += 1;
    arr = createArray(rootNode->right, arr, index);

    return arr;
}

struct Node *treeFromArray(int *arr, int start, int end)
{
    if (start > end)
    {
        return NULL;
    }
    int mid = (start + end) / 2;
    struct Node *temp = createValueNode(arr[mid]);
    temp->left = treeFromArray(arr, start, mid - 1);
    if (temp->left != NULL)
    {
        temp->left->parent = temp;
    }
    temp->right = treeFromArray(arr, mid + 1, end);
    if (temp->right != NULL)
    {
        temp->right->parent = temp;
    }
    temp->size = end - start + 1;

    return temp;
}

void sizeUpdate(struct Node *node)
{
    if (node == NULL)
    {
        return;
    }
    int leftSize = node->left == NULL ? 0 : node->left->size;
    int rightSize = node->right == NULL ? 0 : node->right->size;
    node->size = leftSize + rightSize + 1;
    sizeUpdate(node->parent);
}

void Insert(struct Node **rootNode, int val)
{
    struct Node *traveller = *rootNode;
    struct Node *prev = NULL;
    int flag = 1;
    while (traveller != NULL)
    {
        if (isNearlyBalanced(traveller))
        {
            traveller->size += 1;
            prev = traveller;
            traveller = traveller->right;
        }
        else
        {
            flag = 0;
            break;
        }
    }
    if (flag == 1)
    {
        prev->right = createValueNode(val);
        prev->right->parent = prev;
    }
    else
    {
        free(arr);
        arr = (int *)malloc(sizeof(int) * (traveller->size));
        int index = 0;
        arr = createArray(traveller, arr, &index);
        traveller = treeFromArray(arr, 0, traveller->size - 1);
        if (prev == NULL)
        {
            *rootNode = traveller;
            sizeUpdate(*rootNode);
        }
        else
        {
            sizeUpdate(prev);
            prev->right = traveller;
            traveller->parent = prev;
        }
        Insert(rootNode, val);
    }
}

int main()
{
    struct Node *rootNode = createValueNode(1);
    clock_t start_t, end_t;
    double total_t;
    FILE *fptr = fopen("output.csv", "a");
    if (fptr == NULL)
    {
        printf("Error!");
        exit(1);
    }

    start_t = clock();
    for (int j = 10000; j <= 7000000; j = j + 50000)
    {
        int k = j - 50000;
        if (k == 0)
        {
            for (int i = 2; i <= j; i++)
            {
                Insert(&rootNode, i);
            }
        }
        else
        {
            for (int i = k + 1; i <= j; i++)
            {
                Insert(&rootNode, i);
            }
        }
        end_t = clock();
        total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
        fprintf(fptr, "%d, %f", j, total_t);
        fprintf(fptr, "\n");
    }

    return 0;
}