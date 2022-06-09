#include <bits/stdc++.h>
using namespace std;
// Recursion
int rod(vector<int> &num, int k)
{
    if (k == 0)
    {
        return 0;
    }
    int size = INT_MIN;
    for (int i = 1; i <= k; i++)
    {
        size = max(size, num[i - 1] + rod(num, k - i));
    }
    return size;
}
// Using DP
int rod_cutting(vector<int> &num, vector<int> &dp, int k)
{
    if (k == 0)
        return 0;
    if (dp[k] != -1)
        return dp[k];
    int size = INT_MIN;

    for (int i = 1; i <= k; i++)
    {
        size = max(size, num[i - 1] + rod_cutting(num, dp, k - i));
    }

    dp[k] = size;
    return size;
}
// Tabulation
int rod_cut(vector<int> &num, int k)
{
    vector<int> dp(k + 1, 0);
    dp[0] = 0;

    for (int i = 1; i <= k; i++)
    {
        int size = INT_MIN;
        for (int j = 1; j <= i; j++)
        {
            size = max(size, num[j - 1] + dp[i - j]);
        }
        dp[i] = size;
    }
    return dp[k];
}
int main()
{
    vector<int> num{1, 5, 8, 9, 10, 17, 17, 20, 24, 30};

    int n = num.size();
    int k;
    cout << "Enter Rod Length: ";
    cin >> k;
    vector<int> dp(k + 1, -1);
    cout << rod(num, k) << endl;
    cout << "Using Dynamic Programming: ";
    cout << rod_cutting(num, dp, k) << endl;
    cout << "Tabulation: " << rod_cut(num, k) << endl;
}
