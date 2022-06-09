#include <iostream>
#include <vector>
#include <climits>
using namespace std;
// Frog can jump 1 or 2 indexes | get minimum energy used to go from 0 to n-1
int frog_jump(int num[], int n, vector<int> &dp)
{
    if (n == 0)
        return 0;

    if (dp[n] != -1)
        return dp[n];
    int left = frog_jump(num, n - 1, dp) + abs(num[n] - num[n - 1]);
    int right;
    if (n > 1)
    {
        right = frog_jump(num, n - 2, dp) + abs(num[n] - num[n - 2]);
    }
    return dp[n] = min(left, right);
}
// Tabulation
int frog_(int num[], int n)
{
    vector<int> dp(n, 0);
    dp[0] = 0;

    for (int i = 1; i < n; i++)
    {
        int fs = dp[i - 1] + abs(num[i] - num[i - 1]);
        int ss = INT_MAX;
        if (i > 1)
            ss = dp[i - 2] + abs(num[i] - num[i - 2]);

        dp[i] = min(fs, ss);
    }
    return dp[n - 1];
}
int frog_space(int num[], int n)
{
    int prev = 0;
    int prev2 = 0;
    for (int i = 1; i < n; i++)
    {
        int left = prev + abs(num[i] - num[i - 1]);
        int right = INT_MAX;
        if (i > 1)
        {
            right = prev2 + abs(num[i] - num[i - 2]);
        }
        int curri = min(left, right);
        prev2 = prev;
        prev = curri;
    }
    return prev;
}
int main()
{
    int n, num[10000];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }
    vector<int> dp(n + 1, -1);
    cout << "Minimum distance is: " << frog_jump(num, n - 1, dp) << endl;
    cout << "Minimum distance using tabulation: " << frog_(num, n) << endl;
    cout << "Space optimisation: " << frog_space(num, n) << endl;
}
