#include <bits/stdc++.h>
using namespace std;
class Queue
{
public:
    stack<int> s1;
    stack<int> s2;

    void push(int element)
    {
        s1.push(element);
    }
    void pop()
    {
        if (s1.empty())
        {
            return;
        }
        while (s1.size() > 1)
        {
            int element = s1.top();
            s2.push(element);
            s1.pop();
        }
        s1.pop();
        while (s2.size() > 1)
        {
            int element = s2.top();
            s1.push(element);
            s2.pop();
        }
        }
    int front()
    {

        while (s1.size() > 1)
        {
            int element = s1.top();
            s2.push(element);
            s1.pop();
        }
        int element = s1.top();
        s1.pop();
        s2.push(element);

        while (s2.size() > 1)
        {
            int element = s2.top();
            s1.push(element);
            s2.pop();
        }
        return element;
    }
    int size()
    {
        return s1.size() + s2.size();
    }
    bool empty()
    {
        return size() == 0;
    }
};

int main()
{
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    cout << q.front() << endl;
    q.pop();
    cout << q.front() << endl;
    q.pop();
    q.pop();
    cout << q.front() << endl;
    cout << q.size() << endl;
    cout << q.empty() << endl;
}