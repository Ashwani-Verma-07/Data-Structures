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
Node *dummyNode_rec(Node *head1, Node *head2)
{
    if (head1 == NULL)
    {
        return head2;
    }
    if (head2 == NULL)
    {
        return head1;
    }
    Node *head3;

    if (head1->data < head2->data)
    {
        head3 = head1;
        head3->next = dummyNode_rec(head1->next, head2);
    }
    else
    {
        head3 = head2;
        head3->next = dummyNode_rec(head1, head2->next);
    }
    return head3;
}
Node *dummyNode(Node *head1, Node *head2)
{
    Node *head3 = new Node(-1);
    Node *temp = head3;
    while (head1 != NULL and head2 != NULL)
    {
        if (head1->data > head2->data)
        {
            head3->next = head2;
            head2 = head2->next;
        }
        else
        {
            head3->next = head1;
            head1 = head1->next;
        }
        head3 = head3->next;
    }
    while (head1 != NULL)
    {
        head3->next = head1;
        head1 = head1->next;
        head3 = head3->next;
    }
    while (head2 != NULL)
    {
        head3->next = head2;
        head2 = head2->next;
        head3 = head3->next;
    }
    return temp->next;
}
int main()
{
    cout << "Enter elements @1 " << endl;
    Node *head1 = insert();
    cout << "Enter elements @2 " << endl;
    Node *head2 = insert();
    Node *star = dummyNode_rec(head1, head2);
    print(star);
}
