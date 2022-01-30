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
void preInpost(BinaryTree *root)
{
    stack<pair<BinaryTree *, int>> st;
    if (root == NULL)
    {
        return;
    }
    st.push({root, 1});
    vector<int> pre, in, post;
    while (!st.empty())
    {
        auto front = st.top();
        st.pop();
        if (front.second == 1)
        {
            pre.push_back(front.first->data);
            front.second++;
            st.push(front);
            if (front.first->left != NULL)
            {
                st.push({front.first->left, 1});
            }
        }
        else if (front.second == 2)
        {
            in.push_back(front.first->data);
            front.second++;
            st.push(front);
            if (front.first->right != NULL)
            {
                st.push({front.first->right, 1});
            }
        }
        else
        {
            post.push_back(front.first->data);
        }
    }
    cout << "PreOrder is : ";
    for (int i : pre)
    {
        cout << i << " ";
    }
    cout << endl
         << "InOrder is : ";
    for (int i : in)
    {
        cout << i << " ";
    }
    cout << endl
         << "PostOrder is : ";
    for (int i : post)
    {
        cout << i << " ";
    }
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
    int key;
    BinaryTree *root = input();
    output(root);
    cout << "PreOrder InOrder PostOrder in ONE Traversal " << endl;
    preInpost(root);
}
//1 2 4 9 -1 5 6 -1 -1 7 10 -1 3 8 -1 -1 -1 -1 -1 -1 -1