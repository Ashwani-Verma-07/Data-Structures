#include <iostream>
#include <queue>
#include <vector>
#include <map>
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
        left = right = NULL;
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
    queue<BinaryTree *> q;
    BinaryTree *root = new BinaryTree(rootData);
    q.push(root);
    while (!q.empty())
    {
        int leftData, rightData;
        BinaryTree *front = q.front();
        q.pop();
        cout << "Enter left data of " << front->data << " : " << endl;
        cin >> leftData;
        if (leftData != -1)
        {
            BinaryTree *child = new BinaryTree(leftData);
            front->left = child;
            q.push(child);
        }
        cout << "Enter right data of " << front->data << " : " << endl;
        cin >> rightData;
        if (rightData != -1)
        {
            BinaryTree *child = new BinaryTree(rightData);
            front->right = child;
            q.push(child);
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
    queue<BinaryTree *> q;
    q.push(root);
    while (q.size() != 0)
    {
        BinaryTree *front = q.front();
        q.pop();
        cout << front->data << " :";
        if (front->left != NULL)
        {
            cout << " L->" << front->left->data;
            q.push(front->left);
        }
        if (front->right != NULL)
        {
            cout << " R->" << front->right->data;
            q.push(front->right);
        }
        cout << endl;
    }
}

vector<int> vertical_order(BinaryTree *root)
{
    vector<int> ans;
    map<int, vector<int>> mp;
    queue<pair<BinaryTree *, int>> q;
    q.push({root, 0});
    while (q.size() != 0)
    {
        BinaryTree *f = q.front().first;
        int val = q.front().second;
        q.pop();
        mp[val].push_back(f->data);
        if (f->left)
        {
            q.push({f->left, val - 1});
        }
        if (f->right)
        {
            q.push({f->right, val + 1});
        }
    }
    for (auto it : mp)
    {
        for (auto i : it.second)
            ans.push_back(i);
    }
    return ans;
}
int main()
{
    BinaryTree *root = input();
    output(root);
    vector<int> num = vertical_order(root);
    for (int i = 0; i < num.size(); i++)
    {
        cout << num[i] << " ";
    }
}