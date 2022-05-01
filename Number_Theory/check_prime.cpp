#include <iostream>
using namespace std;
bool checkPrime(int n)
{
    int factor = 0;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            if (i * i == n)
            {
                factor++;
            }
            else
            {
                factor += 2;
            }
        }
    }
    if (factor == 2)
    {
        return true;
    }
    return false;
}
int main()
{
    int n, count = 0;
    ;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        if (checkPrime(i))
        {
            count++;
        }
    }
    cout << count << endl;
}