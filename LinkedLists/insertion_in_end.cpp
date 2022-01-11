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
void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
Node *insert(Node *head, int n)
{
    Node *Adress = new Node(n);
    Node *temp = head;
    while (true)
    {
        temp = temp->next;
        if (temp->next == NULL)
        {
            Adress->next = NULL;
            temp->next = Adress;
            break;
        }
    }

    return head;
}
int main()
{
    Node *head = insert();
    print(head);
    cout << endl
         << "Enter NO. you want to insert at end" << endl;
    int n;
    cin >> n;
    Node *newhead = insert(head, n);
    print(newhead);
}