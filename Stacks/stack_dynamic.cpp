#include <iostream>
using namespace std;
class Stack
{
    int *data;
    int nextindex;
    int capacity;

public:
    Stack()
    {
        data = new int[4];
        nextindex = 0;
        capacity = 4;
    }
    int size()
    {
        return nextindex;
    }
    bool isEmpty()
    {
        // if(nextindex==0){
        //     return true;
        // }else{
        //     return false;
        // }
        return nextindex == 0;
    }
    void push(int element)
    {

        // if (nextindex == capacity)
        // {
        //     cout << "Stack is empty" << endl;  }
        if (nextindex == capacity)
        {
            int *newdata = new int[2 * capacity];
            for (int i = 0; i < capacity; i++)
            {
                newdata[i] = data[i];
            }
            capacity *= 2;
            delete[] data;
            data = newdata;
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

    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    cout << s.top() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.size() << endl;
    cout << s.isEmpty() << endl;
}