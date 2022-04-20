#include <bits/stdc++.h>
using namespace std;
class Stack
{
public:
    queue<int> q1;
    queue<int> q2;

    Stack()
    {
    }
    void push(int x)
    {
        q1.push(x);
    }
    void pop()
    {
        // remove the added element from q1
        // we have to move first n-1 elements in q2
        // interchange the names of q1 and q2
        if (q1.empty())
        {
            return;
        }
        while (q1.size() > 1)
        {
            int element = q1.front();
            q2.push(element);
            q1.pop();
        }
        // removing last element
        q1.pop();
        // queue<int> temp = q1;
        // q1 = q2;
        // q2 = temp;
        // OR
        swap(q1, q2);
    }
    int top()
    {
        while (q1.size() > 1)
        {
            int element = q1.front();
            q2.push(element);
            q1.pop();
        }
        // 1 element in q1
        int element = q1.front();
        q1.pop();
        q2.push(element);
        swap(q1, q2);
        return element;
    }
    int size()
    {
        return q1.size() + q2.size();
    }
    bool empty()
    {
        return size() == 0;
    }
};
int main()
{
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    while (!s.empty())
    {
        cout << "Size is: " << s.size();
        cout << " " << s.top() << " ";
        s.pop();
    }
}
