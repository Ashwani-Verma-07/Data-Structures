#include <bits/stdc++.h>
using namespace std;
void inplaceHeapSort(int pq[], int n)
{
    int parentindex = 0;
    // Build the heap in input array
    for (int i = 0; i < n; i++)
    {
        int childindex = i;
        while (childindex > 0)
        {
            parentindex = (childindex - 1) / 2;
            if (pq[childindex] < pq[parentindex])
            {
                swap(pq[childindex], pq[parentindex]);
            }
            else
            {
                break;
            }
            childindex = parentindex;
        }
    }

    // Remove elements
    int size = n;
    while (size > 1)
    {
        swap(pq[0], pq[size - 1]);

        size--;

        int parentindex = 0;
        int leftChildindex = 2 * parentindex + 1;
        int rightChildindex = 2 * parentindex + 2;
        while (leftChildindex < size)
        {
            int minindex = parentindex;
            if (pq[minindex] > pq[leftChildindex])
            {
                minindex = leftChildindex;
            }
            if (rightChildindex < size && pq[minindex] > pq[rightChildindex])
            {
                minindex = rightChildindex;
            }
            if (minindex == parentindex)
            {
                break;
            }

            swap(pq[minindex], pq[parentindex]);

            parentindex = minindex;
            leftChildindex = 2 * parentindex + 1;
            rightChildindex = 2 * parentindex + 2;
        }
    }
}

int main()
{
    int input[] = {1, 2, 0, 8, 6, -1, 200, 180, 9, 4};
    inplaceHeapSort(input, 10);
    for (int i = 0; i < 10; i++)
    {
        cout << input[i] << " ";
    }
}

// Output:
// 200 180 9 8 6 4 2 1 0 -1