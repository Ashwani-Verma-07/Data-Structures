#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
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
void markParents(BinaryTree *root, unordered_map<BinaryTree *, BinaryTree *> &parent_track, BinaryTree *target)
{
    queue<BinaryTree *> queue;
    queue.push(root);
    while (!queue.empty())
    {
        BinaryTree *current = queue.front();
        queue.pop();
        if (current->left)
        {
            parent_track[current->left] = current;
            queue.push(current->left);
        }
        if (current->right)
        {
            parent_track[current->right] = current;
            queue.push(current->right);
        }
    }
}
vector<int> distance(BinaryTree *root, BinaryTree *target, int k)
{
    unordered_map<BinaryTree *, BinaryTree *> parent_track;
    markParents(root, parent_track, target);

    unordered_map<BinaryTree *, bool> visited;
    queue<BinaryTree *> queue;
    queue.push(target);
    visited[target] = true;
    int curr_level = 0;
    while (!queue.empty())
    {
        int size = queue.size();
        if (curr_level++ == k)
            break;
        for (int i = 0; i < size; i++)
        {
            BinaryTree *current = queue.front();
            queue.pop();
            if (current->left && !visited[current->left])
            {
                queue.push(current->left);
                visited[current->left] = true;
            }
            if (current->right && !visited[current->right])
            {
                queue.push(current->right);
                visited[current->right] = true;
            }
            if (parent_track[current] && !visited[parent_track[current]])
            {
                queue.push(parent_track[current]);
                visited[parent_track[current]] = true;
            }
        }
    }
    vector<int> result;
    while (!queue.empty())
    {
        BinaryTree *current = queue.front();
        queue.pop();
        result.push_back(current->data);
    }
    return result;
}
int main()
{
    BinaryTree *root = input();
    vector<int> num;
    num = distance(root, root->right->left, 2);
    for (int i = 0; i < num.size(); i++)
    {
        cout << num[i] << " ";
    }
}
// input: 1 2 4 9 -1 5 6 -1 -1 7 10 -1 3 8 -1 -1 -1 -1 -1 -1 -1
// k = 2,target:5
// output: 8 6 1