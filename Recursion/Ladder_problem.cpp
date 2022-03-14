#include <iostream>
using namespace std;
int ladder(int n, int k)
{
    if (n == 0)
    {
        return 1;
    }
    if (n < 0)
    {
        return 0;
    }
    int ans = 0;
    for (int i = 1; i <= k; i++)
    {
        ans += ladder(n - i, k);
    }
    return ans;
}
int main()
{
    cout << "Enter NO. of ladder you want" << endl;
    int n, k;
    cin >> n;
    cout << "Enter NO. of ladder you jump" << endl;
    cin >> k;
    cout << "The NO. of ways you can jump " << n << " ladder is : ";
    cout << ladder(n, k) << endl;
}