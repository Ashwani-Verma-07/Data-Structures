#include <bits/stdc++.h>
using namespace std;
int join_ropes(int *ropes, int n)
{
    priority_queue<int, vector<int>, greater<int>> pq(ropes, ropes + n);
    int cost = 0;
    while (pq.size() > 1)
    {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();

        int new_rope = (a + b);
        cost += new_rope;
        pq.push(new_rope);
    }
    return cost;
}
int main()
{
    int ropes[] = {2, 4, 3, 6};
    int n = 4;
    cout << join_ropes(ropes, n) << endl;
}
// One Way;
//  (2,4,3,6)=(2+4)=>6
//  (6,3,6)=(6+3)=>9
//  (9,6)=(9+6)=>15
//  (6,9,15)=(6+9+15)=>30
// Another Way;
//(2,3,4,6)=(2+3)=>5
//  (5,4,6)=(5+4)=>9
//  (9,6)=(9+6)=>15
//  (5,9,15)=(5+9+15)=>29
// Answer:29