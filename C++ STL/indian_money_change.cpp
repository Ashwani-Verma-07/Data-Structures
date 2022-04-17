#include <bits/stdc++.h>
using namespace std;
bool compare(int a, int b)
{
    return a <= b;
}
int main()
{
    // Indian Money System
    int coins[] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
    int n = sizeof(coins) / sizeof(int);
    int money;
    cout << "Enter money to find min. no. of notes " << endl;
    cin >> money;
    cout << "Notes required : " << endl;
    cout << lower_bound(coins, coins + n, money, compare) - coins << endl;
    while (money > 0)
    {
        int lb = lower_bound(coins, coins + n, money, compare) - coins - 1;
        int m = coins[lb];
        cout << m << " Rupee note ,";
        money -= m;
    }
}