#include <iostream>
#include <queue>
using namespace std;
class BinaryTree
{
public:
    int data;
    BinaryTree *right;
    BinaryTree *left;
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
        BinaryTree *front = Queue.front();
        Queue.pop();
        int leftData, rightData;
        cout << "Enter left child of " << front->data << endl;
        cin >> leftData;
        if (leftData != -1)
        {
            BinaryTree *child = new BinaryTree(leftData);
            Queue.push(child);
            front->left = child;
        }
        cout << "Enter right child of " << front->data << endl;
        cin >> rightData;
        if (rightData != -1)
        {
            BinaryTree *child = new BinaryTree(rightData);
            Queue.push(child);
            front->right = child;
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
void inorder(BinaryTree *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
BinaryTree *inorder_succ(BinaryTree *root)
{
    BinaryTree *curr = root;
    while (curr && curr->left != NULL)
    {
        curr = curr->left;
    }
    return curr;
}
BinaryTree *delete_in_bst(BinaryTree *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (key < root->data)
    {
        root->left = delete_in_bst(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = delete_in_bst(root->right, key);
    }
    else
    {
        if (root->left == NULL)
        {
            BinaryTree *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            BinaryTree *temp = root->left;
            free(root);
            return temp;
        }
        BinaryTree *temp = inorder_succ(root->right);
        root->data = temp->data;
        root->right = delete_in_bst(root->right, temp->data);
    }
    return root;
}

int main()
{
    int key;
    BinaryTree *root = input();
    output(root);
    cout << endl;
    inorder(root);
    cout << endl;
    cout << "Enter NO. you want to delete ";
    cin >> key;
    BinaryTree *newRoot = delete_in_bst(root, key);
    output(newRoot);
    inorder(newRoot);
}