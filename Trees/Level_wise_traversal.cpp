#include <bits/stdc++.h>
#include "header_file.h"
using namespace std;

TreeNode<int> *input_level()
{
    int rootData;
    cout << "Enter Data " << endl;
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);
    queue<TreeNode<int> *> Queue_Node;
    Queue_Node.push(root);
    while (Queue_Node.size() != 0)
    {
        TreeNode<int> *front = Queue_Node.front();
        int number;
        cout << "Enter No. of children of " << front->data << endl;
        Queue_Node.pop();
        cin >> number;
        for (int i = 0; i < number; i++)
        {
            int childData;
            cout << "Enter " << i + 1 << "th data of " << front->data << endl;
            cin >> childData;
            TreeNode<int> *child = new TreeNode<int>(childData);
            Queue_Node.push(child);
            front->children.push_back(child);
        }
    }
    return root;
}
void output_level(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<TreeNode<int> *> Queue_data;
    Queue_data.push(root);
    while (Queue_data.size() != 0)
    {
        TreeNode<int> *front = Queue_data.front();
        Queue_data.pop();
        cout << front->data << " : ";
        for (int i = 0; i < front->children.size(); i++)
        {
            cout << front->children[i]->data << " ,";
            Queue_data.push(front->children[i]);
        }
        cout << endl;
    }
}
int main()
{
    TreeNode<int> *root = input_level();
    output_level(root);
}