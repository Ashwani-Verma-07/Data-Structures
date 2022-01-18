#include <iostream>
#include <queue>
using namespace std;
template <typename T>
class BinaryTree
{
public:
    T data;
    BinaryTree<T> *left;
    BinaryTree<T> *right;
    BinaryTree(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};
BinaryTree<int> *input()
{
    int rootData;
    cin >> rootData;
    BinaryTree<int> *root = new BinaryTree<int>(rootData);
    queue<BinaryTree<int> *> Queue;
    Queue.push(root);
    while (Queue.size() != 0)
    {
        BinaryTree<int> *front = Queue.front();
        Queue.pop();
        cout << "Enter left Child of " << front->data << endl;
        int leftData, rightData;
        cin >> leftData;
        if (leftData != -1)
        {
            BinaryTree<int> *child = new BinaryTree<int>(leftData);
            front->left = child;
            Queue.push(child);
        }
        cout << "enter right child of " << front->data << endl;
        cin >> rightData;
        if (rightData != -1)
        {
            BinaryTree<int> *child = new BinaryTree<int>(rightData);
            front->right = child;
            Queue.push(child);
        }
    }
    return root;
}
BinaryTree<int> *buildTree(int inorder[], int preorder[], int in_S, int in_E, int pre_S, int pre_E)
{
    if (in_S > in_E)
    {
        return NULL;
    }

    int rootData = preorder[pre_S];
    int rootIndex = -1;
    for (int i = in_S; i <= in_E; i++)
    {
        if (inorder[i] == rootData)
        {
            rootIndex = i;
            break;
        }
    }
    int lPreS = pre_S + 1;
    int lInS = in_S;
    int lInE = rootIndex - 1;
    int lPreE = lInE - lInS + lPreS;
    int rPreS = lPreE + 1;
    int rPreE = pre_E;
    int rInS = rootIndex + 1;
    int rInE = in_E;
    BinaryTree<int> *root = new BinaryTree<int>(rootData);
    root->left = buildTree(inorder, preorder, lInS, lInE, lPreS, lPreE);
    root->right = buildTree(inorder, preorder, rInS, rInE, rPreS, rPreE);
    return root;
}

void printTree(BinaryTree<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " :";
    if (root->left != NULL)
    {
        cout << " L->" << root->left->data;
    }
    if (root->right != NULL)
    {
        cout << " R->" << root->right->data;
    }
    cout << endl;
    printTree(root->left);
    printTree(root->right);
}
int main()
{
    int k;
    // BinaryTree<int> *root = input();
    // printTree(root);
    int inorder[100], preorder[100];
    cout << "Enter Size of Array" << endl;
    cin >> k;
    cout << "Enter INORDER ";
    for (int i = 0; i < k; i++)
    {
        cin >> inorder[i];
    }
    cout << "Enter PREORDER ";
    for (int i = 0; i < k; i++)
    {
        cin >> preorder[i];
    }
    BinaryTree<int> *num = buildTree(inorder, preorder, 0, k - 1, 0, k - 1);
    printTree(num);
}
