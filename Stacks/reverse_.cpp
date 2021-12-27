#include <bits/stdc++.h>
using namespace std;
void insert_at_bottom(stack<int> &s1, int x)
{
    if (s1.empty())
    {
        s1.push(x);
        return;
    }

    int top = s1.top();
    s1.pop();
    insert_at_bottom(s1, x);
    s1.push(top);
}
void call_stack(stack<int> &s1)
{
    if (s1.empty())
    {
        return;
    }
    int x = s1.top();
    s1.pop();
    call_stack(s1);
    insert_at_bottom(s1, x);
}
int main()
{
    stack<int> s1;
    int n, num, k;
    cout << "Enter No. of elements" << endl;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        s1.push(num);
    }
    call_stack(s1);
    while (!s1.empty())
    {
        cout << s1.top() << " ";
        s1.pop();
    }
    return 0;
}