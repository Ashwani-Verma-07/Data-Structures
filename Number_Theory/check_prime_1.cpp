#include <iostream>
using namespace std;
int isPrime[1000];
int Steive(int n)
{
    bool array[n + 1];
    for (int i = 0; i < n; i++)
    {
        array[i] = true;
    }
    array[0] = false;
    array[1] = false;
    for (int i = 2; i * i <= n; i++)
    {
        if (array[i] == true)
        {
            for (int j = i * i; j <= n; j += i)
            {
                array[j] = false;
            }
        }
    }
    int count = 0;
    int j = 0;
    for (int i = 0; i <= n; i++)
    {
        if (array[i] == true)
        {
            isPrime[j] = i;
            j++;
            count++;
        }
    }
    return count;
}
int main()
{
    int n;
    cin >> n;
    int primes = Steive(n);
    cout << "Number of Primes is: " << primes << endl;
    cout << "Numbers are : ";
    for (int i = 0; i < primes; i++)
    {
        cout << isPrime[i] << " ";
    }
}
