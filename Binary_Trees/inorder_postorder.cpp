#include <iostream>
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
        BinaryTree *front = Queue.front();
        Queue.pop();
        cout << "Enter left Child of " << front->data << endl;
        int leftData, rightData;
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
        cout << front->data << " :";
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
BinaryTree *buildTree(int inorder[], int postorder[], int in_S, int in_E, int post_S, int post_E)
{
    if (in_S > in_E)
    {
        return NULL;
    }
    int rootData = postorder[post_E];
    int rootindex = -1;
    for (int i = in_S; i <= in_E; i++)
    {
        if (inorder[i] == rootData)
        {
            rootindex = i;
            break;
        }
    }
    int linS = in_S;
    int linE = rootindex - 1;
    int lPostS = post_S;
    int lPostE = lPostS + linE - linS;
    int rinS = rootindex + 1;
    int rinE = in_E;
    int rPostS = lPostE + 1;
    int rPostE = rinE - rinS + rPostS;
    BinaryTree *root = new BinaryTree(rootData);
    root->left = buildTree(inorder, postorder, linS, linE, lPostS, lPostE);
    root->right = buildTree(inorder, postorder, rinS, rinE, rPostS, rPostE);
    return root;
}

int main()
{
    int k;
    //     BinaryTree *new_ = input();
    //     output(new_);
    cout << "Enter Size of Array : " << endl;
    cin >> k;
    int postorder[100], inorder[100];
    cout << "Enter INORDER ";
    for (int i = 0; i < k; i++)
    {
        cin >> inorder[i];
    }
    cout << "Enter POSTORDER ";
    for (int i = 0; i < k; i++)
    {
        cin >> postorder[i];
    }
    BinaryTree *temp = buildTree(inorder, postorder, 0, k - 1, 0, k - 1);
    output(temp);
}
// Enter INORDER 8 4 2 5 11 13 12 14 9 1 6 3 7 10
// Enter POSTORDER 8 4 2 5 11 13 12 14 9 6 3 7 10 1