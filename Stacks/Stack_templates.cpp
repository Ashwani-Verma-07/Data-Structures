#include <iostream>
using namespace std;
template <typename T>
class Stack
{
    T *data;
    int nextindex;
    int capacity;

public:
    Stack()
    {
        data = new T[4];
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
    void push(T element)
    {

        // if (nextindex == capacity)
        // {
        //     cout << "Stack is empty" << endl;  }
        if (nextindex == capacity)
        {
            T *newdata = new T[2 * capacity];
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
    T pop()
    {
        if (isEmpty())
        {
            cout << "Stack is Empty" << endl;
            return 0;
        }
        nextindex--;
        return data[nextindex];
    }
    T top()
    {
        if (isEmpty())
        {
            cout << "Stack is Empty" << endl;
            return 0;
        }
        return data[nextindex - 1];
    }
};
int main()
{
    int n, num;

    Stack<char> s;
    s.push('A');
    s.push('B');
    s.push('C');
    s.push('D');
    s.push('E');
    cout << s.top() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.size() << endl;
    cout << s.isEmpty() << endl;
}