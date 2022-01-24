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
bool Search(BinaryTree *root, int key)
{
    if (root == NULL)
    {
        return false;
    }
    if (root->data == key)
    {
        return true;
    }
    if (root->data < key)
    {
        return Search(root->right, key);
    }
    if (root->data > key)
    {
        return Search(root->left, key);
    }
    return false;
}
void printTree(BinaryTree *root, int lb, int ub)
{
    if (root == NULL)
    {
        return;
    }
    if (root->data > lb)
    {
        printTree(root->left, lb, ub);
    }
    if (root->data > lb && root->data < ub)
    {
        cout << root->data << " ";
    }
    if (root->data < ub)
    {
        printTree(root->right, lb, ub);
    }
}
void output(BinaryTree *root)
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
int main()
{
    int p, q;
    BinaryTree *root = input();
    output(root);
    cout << "Enter a range you want to search " << endl;
    cin >> p >> q;
    printTree(root, p, q);
    return 0;
}
//5 2 8 1 3 7 9 -1 -1 -1 -1 -1 -1 -1 -1