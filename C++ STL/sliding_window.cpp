#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Brute force -> O(nk)
    // but we have to optimize it by using deque data structure
    // so the optimized version has O(n+k) work;
    int n, a[10000], k, i;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cin >> k;
    // we have to prcess first k elements separately
    deque<int> Q(k);
    for (i = 0; i < k; i++)
    {
        while (!Q.empty() && a[i] > a[Q.front()])
        {
            Q.pop_back();
        }
        Q.push_back(i);
    }

    // Process remaining elements:
    for (; i < n; i++)
    {
        cout << a[Q.front()] << " ";
        // 1.remove the elements which are not part of window

        while ((!Q.empty() && Q.front() <= i - k))
        {
            Q.pop_front();
        }

        // 2.Remove the elements which are not useful and are in window
        while (!Q.empty() && a[i] >= a[Q.back()])
        {
            Q.pop_back();
        }

        // 3.Add the new elements (Expansion)
        Q.push_back(i);
    }
    cout << a[Q.front()] << endl;
    for (; i < n; i++)
    {
        cout << a[Q.front()] << " ";
        // remove the elements which are ont the part of the window(Contraction)
        while (!Q.empty() && (Q.front() <= i - k))
        {
            Q.pop_front();
        }
    }

    return 0;
}