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
// Node *recursive_call(Node *head)
// {
//     if (head == NULL)
//     {
//         return head;
//     }
//     Node *temp = recursive_call(head->next);
// }
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
Node *reverse(Node *head)
{
    Node *prev = NULL;
    while (head != NULL)
    {
        Node *temp = head->next;
        head->next = prev;
        prev = head;
        head = temp;
    }
    return prev;
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
    int flag = 1;
    cout << "Enter elements" << endl;
    Node *head = insert();
    Node *star = reverse(head);

    // Node *star = recursive_call(head);
    while (head != NULL && star != NULL)
    {
        if (head->data == star->data)
        {
            flag = 1;
        }
        else
        {
            flag = 0;
        }
        head = head->next;
        star = star->next;
    }

    if (flag == 1)
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
}
