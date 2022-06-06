#include <iostream>
#include <vector>
using namespace std;
int fibo(int n, vector<int> &dp)
{
    if (n <= 1)
    {
        return n;
    }
    if (dp[n] != -1)
        return dp[n];

    return dp[n] = fibo(n - 1, dp) + fibo(n - 2, dp);
}
int fibo_rec(int n)
{
    if (n <= 1)
    {
        return n;
    }
    return fibo_rec(n - 1) + fibo_rec(n - 2);
}
int main()
{
    int n;
    cin >> n;
    vector<int> dp(n + 1, -1);
    cout << "Via Dp" << endl;
    cout << fibo(n, dp) << endl;
    cout << "Via Recursion" << endl;
    cout << fibo_rec(n) << endl;
}