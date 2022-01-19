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
// int height(BinaryTree<int> *root)
// {
//     if (root == NULL)
//     {
//         return 0;
//     }
//     return 1 + max(height(root->left), height(root->right));
// }
// int diameter(BinaryTree<int> *root)
// {
//     if (root == NULL)
//     {
//         return 0;
//     }
//     int option1 = height(root->left) + height(root->right);
//     int option2 = diameter(root->left);
//     int option3 = diameter(root->right);
//     return max(option1, max(option2, option3));
// }
pair<int, int> heightDiameter(BinaryTree<int> *root)
{
    if (root == NULL)
    {
        pair<int, int> p;
        p.first = 0;
        p.second = 0;
        return p;
    }
    pair<int, int> leftAns = heightDiameter(root->left);
    pair<int, int> rightAns = heightDiameter(root->right);
    int ld = leftAns.second;
    int lh = leftAns.first;
    int rd = rightAns.second;
    int rh = rightAns.first;

    int height = 1 + max(lh, rh);
    int diameter = max(lh + rh, max(ld, rd));
    pair<int, int> p;
    p.first = height;
    p.second = diameter;
    return p;
}
int main()
{
    BinaryTree<int> *root = input();
    printTree(root);
    // cout << "Maximum diameter is : " << diameter(root) << endl;
    cout << endl
         << endl;
    pair<int, int> p = heightDiameter(root);
    cout << "Height : " << p.first << endl;
    cout << "Maximum Diameter is : " << p.second << endl;
    delete root;
}
//1 2 4 9 -1 5 6 -1 -1 7 10 -1 3 8 -1 -1 -1 -1 -1 -1 -1
