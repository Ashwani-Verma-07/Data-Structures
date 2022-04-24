#include <bits/stdc++.h>
using namespace std;
class Fun
{
public:
    void operator()(string s)
    {
        cout << "The given string is " << s << endl;
    }
};

int main()
{
    int n;
    cin >> n;
    priority_queue<int> p;                             // max-priority queue
    priority_queue<int, vector<int>, greater<int>> pq; // min priority queue
    for (int i = 0; i < n; i++)
    {
        int no;
        cin >> no;
        pq.push(no);
    }
    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }
    // Functor
    Fun f;             // Constructor
    f("Hello World!"); // Overloaded() operator = Function call where f is an o bject
}