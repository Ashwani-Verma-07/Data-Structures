#include <iostream>
#include <climits>
using namespace std;
int profit(int n, int c, int *wt, int *prices)
{
    if (n == 0 || c == 0)
    {
        return 0;
    }
    int ans = 0;
    int inc, exc;
    inc = exc = INT_MIN;
    // inc
    if (wt[n - 1] <= c)
    {
        inc = prices[n - 1] + profit(n - 1, c - wt[n - 1], wt, prices);
    }
    // exc
    exc = profit(n - 1, c, wt, prices);
    ans = max(inc, exc);
    return ans;
}
int main()
{
    cout << "Enter NO. of items in shop : ";
    int weights[1000], n, c, prices[1000];
    cin >> n;
    cout << "Enter Weights and prices of " << n << " items " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> weights[i] >> prices[i];
    }
    cout << "Enter Capacity of robber Bag : ";
    cin >> c;
    cout << "Max price robber can steal is: " << profit(n, c, weights, prices) << endl;
}