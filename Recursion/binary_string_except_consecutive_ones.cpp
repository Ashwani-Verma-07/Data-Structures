#include <iostream>
#include <vector>
using namespace std;
// Given n no. of binary digits find out no. of different pairs but exclude consecutive ones.
int solve(int n)
{
    vector<int> dp(n + 2, 0);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n + 1; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n + 1];
}
int main()
{
    int n;
    cin >> n;
    cout << solve(n) << endl;
}