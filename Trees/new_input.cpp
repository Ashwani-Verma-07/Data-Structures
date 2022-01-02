#include <bits/stdc++.h>
#include "header_file.h"
using namespace std;

TreeNode<int> *takeinputLevelwise()
{
    int rootData;
    cout << "Enter data" << endl;
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);
    queue<TreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << "Enter no. of children of " << front->data << endl;
        int numchild;
        cin >> numchild;
        for (int i = 0; i < numchild; i++)
        {
            int childdata;
            cout << "Enter " << i << "th child of " << front->data << endl;
            cin >> childdata;
            TreeNode<int> *child = new TreeNode<int>(childdata);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}
void output(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " : ";
    for (int i = 0; i < root->children.size(); i++)
    {
        cout << root->children[i]->data << " ,";
    }
    cout << endl;
    for (int i = 0; i < root->children.size(); i++)
    {
        output(root->children[i]);
    }
}
int largestNode(TreeNode<int> *root)
{
    int max_ = root->data;
    for (int i = 0; i < root->children.size(); i++)
    {
        int data = largestNode(root->children[i]);

        max_ = max(max_, data);
    }
    return max_;
}
int sumNodes(TreeNode<int> *root)
{
    int sum = root->data;
    for (int i = 0; i < root->children.size(); i++)
    {
        int data = sumNodes(root->children[i]);
        sum += data;
    }
    return sum;
}
TreeNode<int> *input()
{
    int root;
    cout << "Enter Data" << endl;
    cin >> root;
    TreeNode<int> *rootAddress = new TreeNode<int>(root);
    int n;
    cout << "Enter NO. of elements" << endl;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        TreeNode<int> *child = input();
        rootAddress->children.push_back(child);
    }
    return rootAddress;
}
int main()
{
    TreeNode<int> *root = takeinputLevelwise();
    output(root);
}
