#include <iostream>
using namespace std;
// Frog can jump 1 or 2 indexes | get minimum energy used to go from 0 to n-1
int frog_jump(int num[], int n)
{
    if (n == 0)
    {
        return 0;
    }
    int left = frog_jump(num, n - 1) + abs(num[n - 1] - num[n]);
    int right;
    if (n > 1)
    {
        right = frog_jump(num, n - 2) + abs(num[n - 2] - num[n]);
    }
    return min(left, right);
}
int main()
{
    int n, num[10000];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }
    cout << frog_jump(num, n - 1) << endl;
}