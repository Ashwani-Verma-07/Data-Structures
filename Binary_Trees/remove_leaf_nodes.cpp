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
int max_so_far = INT_MIN;
int min_so_far = INT_MAX;

BinaryTree *input()
{
    int rootData;
    cin >> rootData;
    BinaryTree *root = new BinaryTree(rootData);
    queue<BinaryTree *> Queue;
    Queue.push(root);
    while (Queue.size() != 0)
    {
        int leftData, rightData;
        BinaryTree *front = Queue.front();
        Queue.pop();
        cout << "Enter left Data of " << front->data << endl;
        cin >> leftData;
        if (leftData != -1)
        {
            BinaryTree *child = new BinaryTree(leftData);
            front->left = child;
            Queue.push(child);
        }
        cout << "Enter right Data of " << front->data << endl;
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
BinaryTree *remove_leaf(BinaryTree *root)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->left == NULL and root->right == NULL)
    {
        delete root;
        return NULL;
    }
    root->left = remove_leaf(root->left);
    root->right = remove_leaf(root->right);
    return root;
}
void output(BinaryTree *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<BinaryTree *> Queue_;
    Queue_.push(root);
    while (Queue_.size() != 0)
    {
        BinaryTree *front = Queue_.front();
        Queue_.pop();
        cout << front->data << " :";
        if (front->left != NULL)
        {
            cout << " L->" << front->left->data;
            Queue_.push(front->left);
        }
        if (front->right != NULL)
        {
            cout << " R->" << front->right->data;
            Queue_.push(front->right);
        }
        cout << endl;
    }
}
int main()
{
    BinaryTree *root = input();
    output(root);
    BinaryTree *front = remove_leaf(root);
    cout << "Tree without leaf Node is : " << endl;
    output(front);
}
//1 2 4 9 -1 5 6 -1 -1 7 10 -1 3 8 -1 -1 -1 -1 -1 -1 -1