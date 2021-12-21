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
class Stack
{
    Node *head, *tail;
    int size; //no.of elements present in stack
public:
    Stack()
    {
        head = NULL;
        size = 0;
    }
    int getSize()
    {
        return size;
    }
    bool isEmpty()
    {
        return head == NULL;
    }
    void push(int element)
    {
        Node *newNode = new Node(element);
            newNode->next = head;
            head = newNode;
        size++;
    }
    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty!" << endl;
            return 0;
        }
        int ans = head->data;
        head = head->next;
        head->next = NULL;
        delete (head);
        size--;
        return ans;
    }
    int top()
    {
        if (isEmpty())
        {
            cout << "Stack is empty!" << endl;
            return 0;
        }
        return head->data;
    }
};
int main()
{
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    cout << "Top element is: " << s.top() << endl;
    s.pop();
    cout << "after pop"
         << " Top element is: " << s.top() << endl;
    cout << "size is: " << s.getSize() << endl;
    cout << "stack is empty or NOT " << s.isEmpty() << endl;
}
