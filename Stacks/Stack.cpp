#include <iostream>
using namespace std;
class Stack
{
    int *data;
    int nextindex;
    int capacity;

public:
    Stack(int totalSize)
    {
        data = new int[totalSize];
        nextindex = 0;
        capacity = totalSize;
    }
    int size()
    {
        return nextindex;
    }
    bool isEmpty()
    {
        return nextindex == 0;
    }
    void push(int element)
    {
        if (nextindex == capacity)
        {
            cout << "Stack is empty" << endl;
        }

        data[nextindex] = element;
        nextindex++;
    }
    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack is Empty" << endl;
        }
        nextindex--;
        return data[nextindex];
    }
    int top()
    {
        if (isEmpty())
        {
            cout << "Stack is Empty" << endl;
        }
        return data[nextindex - 1];
    }
};
int main()
{
    int n, num;
    cout << "Enter size of stack created" << endl;
    cin >> n;
    Stack s(n);
    cout << "Enter elements :" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        s.push(num);
    }
    cout << s.top() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.size() << endl;
    cout << s.isEmpty() << endl;
}