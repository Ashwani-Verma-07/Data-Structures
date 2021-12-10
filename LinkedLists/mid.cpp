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
    int data;
    cin >> data;
    Node *head = NULL;
    Node *tail = NULL;
    while (data != -1)
    {
        Node *newAdress = new Node(data);
        if (head == NULL)
        {
            head = newAdress;
            tail = newAdress;
        }
        else
        {
            tail->next = newAdress;
            tail = tail->next;
        }
        cin >> data;
    }
    return head;
}
Node *mid_point(Node *head)
{
    if (head == NULL or head->next == NULL)
    {
        return head;
    }
    Node *temp1 = head;
    Node *temp2 = head;
    while (true)
    {

        temp2 = temp2->next->next;
        temp1 = temp1->next;
        if (temp2 == NULL or temp2->next == NULL)
        {
            return temp1;
        }
    }
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
    print(head);
    Node *mid = mid_point(head);
    cout << endl
         << "Mid point element is " << mid->data << endl;
}