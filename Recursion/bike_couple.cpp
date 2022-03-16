#include <iostream>
#include <vector>
using namespace std;
int countFriendsPairings(int n)
{
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {

        dp[i] = dp[i - 1] + (i - 1) * dp[i - 2];
    }

    return dp[n];
}
int main()
{
    cout << "Enter NO. of members who goes for party : ";
    int n;
    cin >> n;
    cout << "NO. of ways members can go either single or couple : ";
    cout << countFriendsPairings(n) << endl;
}