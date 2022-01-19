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
    // cout << "Enter root data" << endl;
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
    queue<BinaryTree<int> *> Queue;
    Queue.push(root);
    while (Queue.size() != 0)
    {
        BinaryTree<int> *front = Queue.front();
        Queue.pop();
        cout << front->data << " : ";
        if (front->left != NULL)
        {
            cout << "L->" << front->left->data << " ,";
            Queue.push(front->left);
        }
        if (front->right != NULL)
        {
            cout << "R->" << front->right->data << " ,";
            Queue.push(front->right);
        }
        cout << endl;
    }
}
int no_of_nodes(BinaryTree<int> *root)
{
    int ans = 1;
    if (root == NULL)
    {
        return 0;
    }
    ans += no_of_nodes(root->left);
    ans += no_of_nodes(root->right);

    return ans;
}
bool if_present(BinaryTree<int> *root, int key)
{
    if (root == NULL)
    {
        return false;
    }
    if (root->data == key)
    {
        return true;
    }
    bool ans = if_present(root->left, key);
    if (ans)
    {
        return true;
    }
    bool ans1 = if_present(root->right, key);

    return ans1;
}
int height(BinaryTree<int> *root)
{
    int h = -1, k = 0, k1 = 0;
    if (root == NULL)
    {
        return 0;
    }
    k = height(root->left);
    k1 = height(root->right);
    if (k > k1)
    {
        return k + 1;
    }
    return k1 + 1;
}
void inorder(BinaryTree<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ,";
    inorder(root->right);
}
void preorder(BinaryTree<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ,";
    preorder(root->left);
    preorder(root->right);
}
void postorder(BinaryTree<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ,";
}

int main()
{
    int n;
    BinaryTree<int> *root = takeinput_levelwise();
    printTree(root);
    cout << "NO. of nodes are : " << no_of_nodes(root) << endl;
    cout << "Enter a number you want to find : " << endl;
    cin >> n;
    int k = if_present(root, n);
    if (k == 1)
    {
        cout << "present" << endl;
    }
    else
    {
        cout << "no present" << endl;
    }
    cout << "Height of Tree is :" << height(root) << endl;
    cout << "Inorder Traversal :" << endl;
    inorder(root);
    cout << endl
         << "Preorder Traversal :" << endl;
    preorder(root);
    cout << endl
         << "Postorder Traversal :" << endl;
    postorder(root);
}
//1 2 4 -1 -1 5 6 -1 -1 7 -1 -1 3 8 -1 -1 -1
//1 2 4 9 -1 5 6 -1 -1 7 -1 -1 3 8 -1 -1 -1 -1 -1
