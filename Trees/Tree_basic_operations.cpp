#include <bits/stdc++.h>
using namespace std;
template <typename T>
class TreeNode
{
public:
    T data;
    vector<TreeNode *> children;
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
int numnodes(TreeNode<int> *root)
{
    int ans = 1;
    for (int i = 0; i < root->children.size(); i++)
    {
        ans += numnodes(root->children[i]);
    }
    return ans;
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
int height(TreeNode<int> *root)
{
    int h = -1;
    for (int i = 0; i < root->children.size(); i++)
    {
        int k = height(root->children[i]);
        h = max(h, k);
    }
    h += 1;
    return h;
}
void preorder(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << ", ";
    for (int i = 0; i < root->children.size(); i++)
    {
        preorder(root->children[i]);
    }
}
void postorder(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        postorder(root->children[i]);
    }
    cout << root->data << ", ";
}
void depth_of_Tree(TreeNode<int> *root, int k)
{
    if (root == NULL)
    {
        return;
    }
    if (k == 0)
    {
        cout << root->data << ", ";
        return;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        depth_of_Tree(root->children[i], k - 1);
    }
}
int no_of_leaf(TreeNode<int> *root)
{
    int k = 0;
    if (root->children.size() == 0)
    {
        return 1;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        k = k + no_of_leaf(root->children[i]);
    }
    return k;
}
void DeleteTree(TreeNode<int> *root)
{
    for (int i = 0; i < root->children.size(); i++)
    {
        DeleteTree(root->children[i]);
    }
    delete root;
}
int main()
{
    TreeNode<int> *root = input_level();
    output_level(root);
    cout << "Size is : " << numnodes(root) << endl;
    cout << "Sum is : " << sumNodes(root) << endl;
    cout << "Largest Node is : " << largestNode(root) << endl;
    cout << "Height of tree is : " << height(root) << endl;
    int key;
    cout << "Enter depth want to find : " << endl;
    cin >> key;
    depth_of_Tree(root, key);
    cout << endl;
    cout << "NO. of leaf Nodes are" << endl;
    cout << no_of_leaf(root) << endl;
    cout << "Pre-Order : " << endl;
    preorder(root);
    cout << endl;
    cout << "Post-Order : " << endl;
    postorder(root);
    cout << endl;
    cout << "Enter '1' or '0' for recursively-delete or destructor-delete" << endl;
    int n;
    cin >> n;
    if (n == 1)
    {
        DeleteTree(root);
    }
    else
    {
        delete root;
    }
}