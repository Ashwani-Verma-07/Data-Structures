#include <iostream>
#include <queue>
using namespace std;
int main()
{
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(179);
    pq.push(1);
    pq.push(12);
    pq.push(78);
    pq.push(0);
    pq.push(200);

    cout << "Size"
         << " " << pq.size() << endl;
    cout << "Top " << pq.top() << endl;
    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }
}