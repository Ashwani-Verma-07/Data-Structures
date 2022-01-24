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

bool isBST3(BinaryTree *root, int min = INT_MIN, int max = INT_MAX)
{
    if (root == NULL)
    {
        return true;
    }
    if (root->data < min or root->data > max)
    {
        return false;
    }
    bool isLeftOK = isBST3(root->left, min, root->data - 1);
    bool isRightOK = isBST3(root->right, root->data, max);
    return isLeftOK && isRightOK;
}
int main()
{
    int key;
    BinaryTree *root = input();
    output_Tree(root);
    if (isBST3(root))
    {
        cout << "Tree is BST" << endl;
    }
    else
    {
        cout << "Tree is NOT BST" << endl;
    }
    return 0;
}
//5 2 8 1 3 7 9 -1 -1 -1 -1 -1 -1 -1 -1 ->Tree is BST
//3 2 7 1 -1 5 8 -1 -1 4 6 -1 -1 -1 -1 -1 -1 ->Tree is BST
//4 2 6 1 30 5 7 -1 -1 -1 -1 -1 -1 -1 -1 ->Tree is NOT BST