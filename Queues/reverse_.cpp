#include <Bits/stdc++.h>
using namespace std;
void queue_call(queue<int> &q)
{
    if (q.empty())
    {
        return;
    }
    int x = q.front();
    q.pop();
    queue_call(q);
    q.push(x);
}
int main()
{
    int n, num;
    queue<int> q;
    cout << "Enter No. of elements" << endl;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        q.push(num);
    }
    queue_call(q);
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
}