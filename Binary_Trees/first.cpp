#include <iostream>
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
    BinaryTree<int> *root = takeinput();
    printTree(root);
}
//1 2 4 -1 -1 5 6 -1 -1 7 -1 -1 3 8 -1 -1 -1