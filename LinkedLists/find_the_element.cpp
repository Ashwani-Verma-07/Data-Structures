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
int find_out(Node *head, int key, int i)
{
    if (head == NULL)
    {
        return -1;
    }
    if (head->data == key)
    {
        return i;
    }
    return find_out(head->next, key, i + 1);
}
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
int main()
{
    int key;
    cout << "Enter the elements" << endl;
    Node *star = insert();
    cout << "Enter key to find out" << endl;
    cin >> key;
    int f = find_out(star, key, 0);
    cout << f << endl;
}