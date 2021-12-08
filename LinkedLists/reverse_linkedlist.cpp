#include <iostream>
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
Node *insert()
{
    Node *head = NULL;
    Node *tail = NULL;
    int data;
    cin >> data;
    while (data != -1)
    {
        Node *newAddress = new Node(data);
        if (head == NULL)
        {
            head = newAddress;
            tail = newAddress;
        }
        else
        {
            tail->next = newAddress;
            tail = tail->next;
        }
        cin >> data;
    }

    return head;
}
void recursive_call(Node *head)
{
    if (head == NULL)
    {
        return;
    }
    recursive_call(head->next);
    cout << head->data << " ";
}
void print(Node *head)
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
    cout << "Enter elements" << endl;
    Node *head = insert();
    recursive_call(head);
}