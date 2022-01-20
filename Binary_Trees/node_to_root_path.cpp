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
vector<int> v;
bool Node_path(BinaryTree *root, int key)
{
    if (root == NULL)
    {
        return false;
    }
    if (root->data == key)
    {
        v.push_back(root->data);
        return true;
    }
    bool lst = Node_path(root->left, key);
    if (lst)
    {
        v.push_back(root->data);
        return true;
    }
    bool rst = Node_path(root->right, key);
    if (rst)
    {
        v.push_back(root->data);
        return true;
    }
    return false;
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
    int k;
    BinaryTree *root = input();
    output(root);
    cout << "Enter NODE you want to find path : " << endl;
    cin >> k;
    Node_path(root, k);
    for (int x : v)
    {
        cout << x << " ,";
    }
}
//1 2 4 9 -1 5 6 -1 -1 7 10 -1 3 8 -1 -1 -1 -1 -1 -1 -1