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
int msn = 0;
int ms = INT_MIN;

int max_sum_subTREE(TreeNode<int> *root)
{
    int num = 0;
    int sum = 0;
    for (int i = 0; i < root->children.size(); i++)
    {

        int data_ = root->children[i]->data;
        sum += data_;
        max_sum_subTREE(root->children[i]);
    }
    if (sum > ms)
    {
        msn = root->data;
        ms = sum;
    }

    return sum;
}
int main()
{
    TreeNode<int> *root = input();
    output(root);
    max_sum_subTREE(root);
    cout << "Node : " << msn << " has maximun sum of : " << endl;
    cout << ms << endl;
}

//1 3 2 9 11 2 19 25 1 18 1 3 0 0 1 4 0 0