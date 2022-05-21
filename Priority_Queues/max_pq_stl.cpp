#include <queue>
#include <iostream>
using namespace std;
int main()
{
    int n;
    priority_queue<int> pq;
    pq.push(16);
    pq.push(11);
    pq.push(178);
    pq.push(7);
    pq.push(78);
    pq.push(22);
    // Max Priority Queue
    cout << "Size"
         << " " << pq.size() << endl;
    cout << "Top " << pq.top() << endl;
    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }
}