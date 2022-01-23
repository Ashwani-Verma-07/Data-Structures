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
bool lefttoright = true;
void output_zig(BinaryTree *root)
{
    if (root == NULL)
    {
        return;
    }
    stack<BinaryTree *> rootStack;
    stack<BinaryTree *> nextStack;
    rootStack.push(root);
    while (rootStack.size() != 0)
    {
        BinaryTree *front = rootStack.top();
        rootStack.pop();
        if (front != NULL)
        {
            cout << front->data << " ";

            if (lefttoright)
            {
                if (front->left != NULL)
                {
                    nextStack.push(front->left);
                }
                if (front->right != NULL)
                {
                    nextStack.push(front->right);
                }
            }
            else
            {
                if (front->right != NULL)
                {
                    nextStack.push(front->right);
                }
                if (front->left != NULL)
                {
                    nextStack.push(front->left);
                }
            }
            if (rootStack.empty())
            {
                cout << endl;
                swap(rootStack, nextStack);
                lefttoright = !lefttoright;
            }
        }
    }
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
    cout << "In ZIG-ZAC order printing" << endl;
    output_zig(root);
}
//1 5 10 7 8 -1 -1 -1 -1 9 -1 -1 -1
//1 2 4 9 -1 5 6 -1 -1 7 10 -1 3 8 -1 -1 -1 -1 -1 -1 -1