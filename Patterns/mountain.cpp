#include <iostream>
using namespace std;
int main ()
{
    int i, j, k = 1;
    int n;
    cin >> n;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= i; j++)
            {
                cout << k << "\t";
                k++;
            }
        for (j = 1; j <= 2*n - 1 - 2*i; j++)
            cout << "\t";
        for (j = 1; j <= i; j++)
            {
                k--;
                if (k == n)
                    continue;
                cout << k << "\t";
            }
        cout << endl;
    }
    return 0;
}