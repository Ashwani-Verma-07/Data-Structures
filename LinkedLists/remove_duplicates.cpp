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
Node *remove_duplicates(Node *head)
{

    Node *temp1 = head;
    Node *temp2 = head->next;
    while (temp2 != NULL)
    {
        if (head == NULL or head->next == NULL)
        {

            return NULL;
        }
        if (temp1->data != temp2->data)
        {
            temp1->next = temp2;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        else
        {
            temp2 = temp2->next;
        }
        }
    temp1->next = temp2;
    return head;
}
// Node *remove_duplicates(Node *head)
// {
//     Node *temp = head;
//     while (temp && temp->next)
//     {
//         if (temp->data == temp->next->data)
//             temp->next = temp->next->next;
//         else
//             temp = temp->next;
//     }
//     return head;
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
    cout << "Enter elements" << endl;
    Node *head = insert();
    Node *star = remove_duplicates(head);
    print(star);
}