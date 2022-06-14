#include <iostream>
#include <vector>
#include <queue>
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
bool isleaf(BinaryTree *root)
{
    return (root->left == NULL && root->right == NULL);
}
void leaf(BinaryTree *root)
{
    if (root == NULL)
    {
        return;
    }
    leaf(root->left);
    if (isleaf(root))
        cout << root->data << " ";

    leaf(root->right);
}
void left(BinaryTree *root)
{
    if (root == NULL)
        return;
    if (root->left)
    {
        cout << root->data << " ";
        left(root->left);
    }
    else if (root->right)
    {
        cout << root->data << " ";
        left(root->right);
    }
}

void right(BinaryTree *root)
{
    if (root == NULL)
        return;
    if (root->right)
    {
        right(root->right);
        cout << root->data << " ";
    }
    else if (root->left)
    {
        right(root->left);
        cout << root->data << " ";
    }
}
void boundry(BinaryTree *root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";

    left(root->left);
    // Printing All Leaves
    leaf(root->left);
    leaf(root->right);

    right(root->right);
}

int main()
{
    BinaryTree *root = input();
    output(root);

    cout << "Boundary Order Traversal is: ";
    boundry(root);
}