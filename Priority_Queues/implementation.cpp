#include <bits/stdc++.h>
using namespace std;
class PriorityQueue
{
    vector<int> pq;

public:
    PriorityQueue()
    {
    }
    bool isEmpty()
    {
        return pq.size() == 0;
    }
    int getMin()
    {
        if (isEmpty())
        {
            return 0;
        }
        return pq[0];
    }
    int getSize()
    {
        return pq.size();
    }
    void insert(int element)
    {
        pq.push_back(element);

        int childindex = (pq.size() - 1);
        while (childindex > 0)
        {
            int parentindex = (childindex - 1) / 2;
            if (pq[childindex] < pq[parentindex])
            {
                int temp = pq[childindex];
                pq[childindex] = pq[parentindex];
                pq[parentindex] = temp;
            }
            else
            {
                break;
            }
            childindex = parentindex;
        }
    }
    int removeMin()
    {
        if (pq.empty())
        {
            return 0;
        }
        int ans = pq[0];
        pq[0] = pq[pq.size() - 1];
        pq.pop_back();

        // down heapify

        int parentindex = 0;
        int leftChildindex = 2 * parentindex + 1;
        int rightChildindex = 2 * parentindex + 2;
        while (leftChildindex < pq.size())
        {
            int minindex = parentindex;
            if (pq[minindex] > pq[leftChildindex])
            {
                minindex = leftChildindex;
            }
            if (rightChildindex < pq.size() && pq[minindex] > pq[rightChildindex])
            {
                minindex = rightChildindex;
            }
            if (minindex == parentindex)
            {
                break;
            }
            int temp = pq[minindex];
            pq[minindex] = pq[parentindex];
            pq[parentindex] = temp;

            parentindex = minindex;
            leftChildindex = 2 * parentindex + 1;
            rightChildindex = 2 * parentindex + 2;
        }
        return ans;
    }
};

int main()
{
    PriorityQueue p;
    p.insert(100);
    p.insert(10);
    p.insert(15);
    p.insert(4);
    p.insert(17);
    p.insert(21);
    p.insert(67);
    cout << p.getSize() << endl;
    cout << p.getMin() << endl;
    while (!p.isEmpty())
    {

        cout << p.removeMin() << " ";

    }
    cout << endl;
}

//Output:
// 7
// 4
// 4 10 15 17 21 67 100 
