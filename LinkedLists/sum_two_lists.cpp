#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};
Node *input1(Node *l1, Node *l2)
{

    Node *head = NULL, *prev = NULL;
    int carry = 0;
    while (l1 || l2)
    {
        int v1 = l1 ? l1->data : 0;
        int v2 = l2 ? l2->data : 0;
        int tmp = v1 + v2 + carry;
        carry = tmp / 10;
        int data = tmp % 10;
        Node *cur = new Node(data);
        if (!head)
            head = cur;
        if (prev)
            prev->next = cur;
        prev = cur;
        l1 = l1 ? l1->next : NULL;
        l2 = l2 ? l2->next : NULL;
    }
    if (carry > 0)
    {
        Node *l = new Node(carry);
        prev->next = l;
    }
    return head;
}

Node *input()
{
    int data;
    Node *head = NULL;
    Node *tail = NULL;
    cin >> data;
    while (data != -1)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = tail->next;
        }
        cin >> data;
    }
    return head;
}
void output(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("error.txt", "w", stderr);
    freopen("output.txt", "w", stdout);
#endif
    Node *insert = input();
    Node *insert1 = input();
    Node *num = input1(insert, insert1);
    output(num);
    return 0;
}