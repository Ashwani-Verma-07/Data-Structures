#include <bits/stdc++.h>
using namespace std;

int frog(vector<int> &num, int k, int n)
{
    if (n == 0)
        return 0;
    int min_steps = INT_MAX;
    for (int i = 1; i <= k; i++)
    {
        if (n - i >= 0)
        {
            int left = frog(num, k, n - i) + abs(num[n] - num[n - i]);
            min_steps = min(min_steps, left);
        }
    }
    return min_steps;
}
// Memoization
int frog_jump(vector<int> &num, int k)
{
    int n = num.size();
    int dp[n + 1], minSteps = 0;
    dp[0] = 0;
    for (int i = 1; i < n; i++)
    {
        int minSteps = INT_MAX;
        for (int j = 1; j <= k; j++)
        {
            if (i - j >= 0)
            {
                int jump = dp[i - j] + abs(num[i] - num[i - j]);
                minSteps = min(minSteps, jump);
            }
        }
        dp[i] = minSteps;
    }
    return dp[n - 1];
}
int main()
{
    int n, k;
    cin >> n;
    vector<int> num(n);
    cout << "Enter Steps : ";
    cin >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }
    cout << frog(num, k, n - 1) << endl;
    cout << frog_jump(num, k) << endl;
}