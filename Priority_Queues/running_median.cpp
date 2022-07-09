#include <iostream>
#include <queue>
using namespace std;
int main()
{
    priority_queue<int> leftheap;
    priority_queue<int, vector<int>, greater<int>> rightheap;
    int d;
    cout << "Enter Sequence of stream ended by -1" << endl;
    cin >> d;
    leftheap.push(d);

    float med = d;
    cout << med << " ";
    cin >> d;
    while (d != -1)
    {
        // left or right or equal
        if (leftheap.size() > rightheap.size())
        {
            if (d < med)
            {
                rightheap.push(leftheap.top());
                leftheap.pop();
                leftheap.push(d);
            }
            else
            {
                rightheap.push(d);
            }
            med = (leftheap.top() + rightheap.top()) / 2.0;
        }
        else if (leftheap.size() == rightheap.size())
        {
            if (d < med)
            {
                leftheap.push(d);
                med = leftheap.top();
            }
            else
            {
                rightheap.push(d);
                med = rightheap.top();
            }
        }
        else
        {
            if (d < med)
            {
                leftheap.push(d);
            }
            else
            {
                leftheap.push(rightheap.top());
                rightheap.pop();
                rightheap.push(d);
            }
            med = (leftheap.top() + rightheap.top()) / 2.0;
        }
        cout << med << " ";
        cin >> d;
    }
}
// Output:
//  Enter Sequence of stream ended by -1
//  10 5 2 3 0 12 18 20 22 -1
//  10 7.5 5 4 3 4 5 7.5 10