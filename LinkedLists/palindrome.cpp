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
Node *reverse_rec(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *temp = reverse_rec(head->next);
    Node *tail = head->next;
    tail->next = head;
    head->next = NULL;
    return temp;
}
// Node *reverse(Node *head)
// {
//     Node *prev = NULL;
//     while (head != NULL)
//     {
//         Node *temp = head->next;
//         head->next = prev;
//         prev = head;
//         head = temp;
//     }
//     return prev;
// }
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
    int flag = -1;
    Node *head = insert();
    Node *star = reverse_rec(head);

    print(star);
    while (head != NULL && star != NULL)
    {
        if (head->data != star->data)
        {
            flag = 0;
            break;
        }
        else
        {
            flag = 1;
        }
        head = head->next;
        star = star->next;
    }

    if (flag == 1)
    {
        cout << "true" << endl;
    }
    if (flag == 0)
    {
        cout << "false" << endl;
    }
    return 0;
}
