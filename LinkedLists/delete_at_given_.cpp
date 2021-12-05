#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int element)
    {
        data = element;
        next = NULL;
    }
};
Node *input()
{
    int data;
    cin >> data;
    Node *head = NULL;
    Node *tail = NULL;
    while (data != -1)
    {
        Node *newaddress = new Node(data); //dynamic memory allocation
        if (head == NULL)
        {
            head = newaddress;
            tail = newaddress;
        }
        else
        {
            tail->next = newaddress;
            tail = tail->next;
        }
        cin >> data;
    }
    return head;
}
Node *newDelete(Node *head, int index)
{
    Node *temp = head;
    Node *pass = head;
    int count = 0;
    Node *a, *b;
    if (index == 0)
    {
        head = head->next;
        return head;
    }
    while (index - 1 > 0)
    {
        temp = temp->next;
        index--;
    }
    if (temp != NULL)
    {
        a = temp->next;
        b = a->next;
        temp->next = b;
    }
    if (temp == NULL)
    {
        temp->next = NULL;
    }
    delete (a);
    return head;
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
    int index;
    cout << "Enter elements" << endl;
    Node *head = input();
    cout << "Give index wish to delete" << endl;

    cin >> index;
    head = newDelete(head, index);
    print(head);
}