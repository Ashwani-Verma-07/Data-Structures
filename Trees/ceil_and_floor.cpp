#include <bits/stdc++.h>
using namespace std;
template <typename T>
class TreeNode
{
public:
    T data;
    vector<TreeNode<T> *> children;
    TreeNode(T data)
    {
        this->data = data;
    }
    ~TreeNode()
    {
        for (int i = 0; i < children.size(); i++)
        {
            delete children[i];
        }
    }
};
TreeNode<int> *input()
{
    int rootData;
    // cout << "Enter data" << endl;
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);
    queue<TreeNode<int> *> Queue_;
    Queue_.push(root);
    while (Queue_.size() != 0)
    {
        TreeNode<int> *front = Queue_.front();
        Queue_.pop();
        int child_num;
        //  cout << "Enter Number of children of " << front->data << endl;
        cin >> child_num;
        for (int i = 0; i < child_num; i++)
        {
            int child_Data;
            //      cout << "Enter " << i + 1 << "th data of " << front->data << endl;
            cin >> child_Data;
            TreeNode<int> *child = new TreeNode<int>(child_Data);
            Queue_.push(child);
            front->children.push_back(child);
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

    queue<TreeNode<int> *> Queue_data;
    Queue_data.push(root);
    while (Queue_data.size() != 0)
    {
        TreeNode<int> *front = Queue_data.front();
        Queue_data.pop();
        cout << front->data << " : ";
        for (int i = 0; i < front->children.size(); i++)
        {
            cout << front->children[i]->data << ", ";
            Queue_data.push(front->children[i]);
        }
        cout << endl;
    }
}
int floor_ = INT_MIN;
int ceil_ = INT_MAX;
void call(TreeNode<int> *root, int key)
{

    if (root == NULL)
    {
        return;
    }
    int data = root->data;
    if (data > key)
    {
        if (data < ceil_)
        {
            ceil_ = data;
        }
    }
    if (data < key)
    {
        if (data > floor_)
        {
            floor_ = data;
        }
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        call(root->children[i], key);
    }
    return;
}
int main()
{
    TreeNode<int> *root = input();
    output(root);
    cout << "Enter element to find ceil_ and floor_" << endl;
    int key;
    cin >> key;
    call(root, key);
    if (ceil_ == INT_MAX) //smallest among larger.
    {
        ceil_ = 0;
    }
    if (floor_ == INT_MIN) // largest among smaller.
    {
        floor_ = 0;
    }
    cout << "Ceil value for " << key << " is " << ceil_ << endl;
    cout << "Floor value for " << key << " is " << floor_ << endl;
}

//1 3 2 9 11 2 19 25 1 18 1 3 0 0 1 4 0 0