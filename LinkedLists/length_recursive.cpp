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

int input_rec(Node *head, int input, int count)
{
    if (input == -1)
    {
        return count;
    }
    cin >> input;
    Node *newAdress = new Node(input);
    head = newAdress;
    return input_rec(head->next, input, count + 1);
}
Node *insert()
{
    int data;
    cin >> data;
    Node *head = NULL;
    Node *tail = NULL;
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
    cout << "Enter values" << endl;
    int data;
    cin >> data;
    Node *head = NULL;
    Node *tail = NULL;
    // Node *head = insert();
    int len = input_rec(head, data, 0);
    cout << len << endl;
}
