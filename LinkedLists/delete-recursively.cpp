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
Node *recursive_delete(Node *head, int i)
{
    if (head == NULL)
    {
        return head;
    }

    if (i == 0)
    {
        Node *temp = head->next;

        delete (head);
        return temp;
    }
    head->next = recursive_delete(head->next, i - 1);
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
    int i;
    cout << "Enter the elements" << endl;
    Node *head = insert();
    cout << "Give position of delete node" << endl;
    cin >> i;
    Node *star = recursive_delete(head, i);
    print(star);
}