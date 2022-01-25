#include <bits/stdc++.h>
using namespace std;
class BinaryTree
{
public:
    int data;
    BinaryTree *left;
    BinaryTree *right;
    BinaryTree(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};
BinaryTree *input()
{
    int rootData;
    cin >> rootData;
    if (rootData == -1)
    {
        return NULL;
    }
    BinaryTree *root = new BinaryTree(rootData);
    queue<BinaryTree *> Queue;
    Queue.push(root);
    while (Queue.size() != 0)
    {
        int leftData, rightData;
        BinaryTree *front = Queue.front();
        Queue.pop();
        cout << "Enter left child of " << front->data << endl;
        cin >> leftData;
        if (leftData != -1)
        {
            BinaryTree *child = new BinaryTree(leftData);
            front->left = child;
            Queue.push(child);
        }
        cout << "Enter right child of " << front->data << endl;
        cin >> rightData;
        if (rightData != -1)
        {
            BinaryTree *child = new BinaryTree(rightData);
            front->right = child;
            Queue.push(child);
        }
    }
    return root;
}
void output_Tree(BinaryTree *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<BinaryTree *> Queue;
    Queue.push(root);
    while (Queue.size() != 0)
    {
        BinaryTree *front = Queue.front();
        Queue.pop();
        cout << front->data << ":";
        if (front->left != NULL)
        {
            cout << " L->" << front->left->data;
            Queue.push(front->left);
        }
        if (front->right != NULL)
        {
            cout << " R->" << front->right->data;
            Queue.push(front->right);
        }
        cout << endl;
    }
}
void preorder(BinaryTree *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
BinaryTree *print_preorder(int arr[], int ub, int lb)
{
    if (ub > lb)
    {
        return NULL;
    }
    int mid = (ub + lb) / 2;

    BinaryTree *root = new BinaryTree(arr[mid]);
    root->left = print_preorder(arr, ub, mid - 1);
    root->right = print_preorder(arr, mid + 1, lb);
    return root;
}
int main()
{
    int n, arr[1000];
    cout << "Enter NO. of elements ";
    cin >> n;
    cout << "Enter Array elements" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    // BinaryTree *root = input();
    // output_Tree(root);
    BinaryTree *root = print_preorder(arr, 0, n - 1);
    preorder(root);

    return 0;
}
//5 2 8 1 3 7 9 -1 -1 -1 -1 -1 -1 -1 -1