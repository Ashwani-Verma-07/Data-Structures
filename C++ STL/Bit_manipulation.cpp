#include <bits/stdc++.h>
using namespace std;

int countSetBits(int x)
{
    int count = 0;
    while (x)
    {
        x &= (x - 1);
        count++;
    }
    return count;
}
int main()
{
    int num, number1;
    int i, j, p, q, number, numb, r;
    cin >> num;
    if ((num & 1) == 0)
    {
        cout << "Even" << endl;
    }
    else
    {
        cout << "Odd" << endl;
    }

    // Power of two
    if ((num & (num - 1)) == 0)
    {
        cout << "Number is power of TWO" << endl;
    }
    else
    {
        cout << "Number is NOT power of TWO" << endl;
    }

    // Turn off a particular bit ->  num ,, i;
    cout << "Enter index to change the bit to zero " << endl;

    cin >> i;
    cout << (num & ~(1 << (i))) << endl;

    // finding value in decimal
    cout << "Enter index to find value correspoding to bit " << endl;
    cin >> j;
    cout << (num & (1 << (j)));
    cout << endl
         << "The first set bit in " << num << " is "
         << log2(num & -num) + 1 << endl;

    cout << "Enter the number to clear LSB" << endl;
    cin >> number;
    cout << "Enter index to clear all bits from LSB to ith bit" << endl;
    cin >> q;
    int mask = ~((1 << q + 1) - 1);
    number &= mask;
    cout << number << endl;

    cout << "Enter a number to clear MSB " << endl;
    cin >> numb;
    cout << "Enter index to clear all bits from MSB to ith bit" << endl;
    cin >> r;
    int msk = (1 << r) - 1;
    numb &= msk;
    cout << numb << endl;
    cout << "Enter Number to find total number of set bits in ";
    cin >> number1;
    cout << countSetBits(number1);
}