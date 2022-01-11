#include <iostream>
#include <queue>
using namespace std;
template <typename T>
class BinaryTree
{
public:
    T data;
    BinaryTree *left;
    BinaryTree *right;
    BinaryTree(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
    ~BinaryTree()
    {
        delete left;
        delete right;
    }
};
BinaryTree<int> *takeinput_levelwise()
{
    int rootData;
    cout << "Enter root data" << endl;
    cin >> rootData;
    if (rootData == -1)
    {
        return NULL;
    }
    BinaryTree<int> *root = new BinaryTree<int>(rootData);
    queue<BinaryTree<int> *> Queue_;
    Queue_.push(root);
    while (Queue_.size() != 0)
    {
        BinaryTree<int> *front = Queue_.front();
        Queue_.pop();
        cout << "Enter left child of " << front->data << endl;
        int leftChildData;
        cin >> leftChildData;
        if (leftChildData != -1)
        {
            BinaryTree<int> *child = new BinaryTree<int>(leftChildData);
            front->left = child;
            Queue_.push(child);
        }
        cout << "Enter right child of " << front->data << endl;
        int rightChildData;
        cin >> rightChildData;
        if (rightChildData != -1)
        {
            BinaryTree<int> *child = new BinaryTree<int>(rightChildData);
            front->right = child;
            Queue_.push(child);
        }
    }
    return root;
}
void printTree(BinaryTree<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " : ";
    if (root->left != NULL)
    {
        cout << "L->" << root->left->data;
    }
    if (root->right != NULL)
    {
        cout << " ,R->" << root->right->data;
    }
    cout << endl;
    printTree(root->left);
    printTree(root->right);
}
BinaryTree<int> *takeinput()
{
    int rootData;
    cout << "Enter Data " << endl;
    cin >> rootData;
    if (rootData == -1)
    {
        return NULL;
    }
    BinaryTree<int> *root = new BinaryTree<int>(rootData);
    BinaryTree<int> *leftChild = takeinput();
    BinaryTree<int> *rightChild = takeinput();
    root->left = leftChild;
    root->right = rightChild;
    return root;
}
int main()
{
    BinaryTree<int> *root = takeinput_levelwise();
    printTree(root);
}
//1 2 4 -1 -1 5 6 -1 -1 7 -1 -1 3 8 -1 -1 -1