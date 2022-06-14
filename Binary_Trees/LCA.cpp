#include <iostream>
#include <queue>
#include <vector>
using namespace std;
// LCA Loweat Common Ancestor in BT
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
BinaryTree *LCA(BinaryTree *root, int p, int q)
{
    if (root == NULL || root->data == p || root->data == q)
    {
        return root;
    }
    BinaryTree *left = LCA(root->left, p, q);
    BinaryTree *right = LCA(root->right, p, q);

    if (left == NULL)
        return right;
    if (right == NULL)
        return left;

    return root;
}
int main()
{
    BinaryTree *root = input();
    int a, b;
    cout << "The LCA of a: ";
    cin >> a;
    cout << " and b: ";
    cin >> b;
    BinaryTree *num = LCA(root, a, b);
    cout << num->data << endl;
}
// 1 2 4 9 -1 5 6 -1 -1 7 10 -1 3 8 -1 -1 -1 -1 -1 -1 -1
//  LCA:(4,5) = 4