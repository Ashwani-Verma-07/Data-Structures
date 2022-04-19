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
    temp();
}

void temp()
{
    // n=5 ->   00000101
    // i=1 ->   00000010  ,,, if i=0 ->    00000001
    // taking and then 00000000 -> NOT SET      ,,, SET
    int n, i;
    cin >> n;
    cout << "Enter position to check set or not_set" << endl;
    cin >> i;
    if ((n & (1 << i)) == 0)
    {
        cout << "NOT SET" << endl;
    }
    else
    {
        cout << "SET" << endl;
    }
    //     You are given two integers N and i. You need to make ith bit of binary representation of N to 1 and return the updated N.
    //     Counting of bits start from 0 from right to left.
    int num, p;
    cin >> num;

    cin >> p;
    int x = num | (1 << p);
    cout << x << endl;

    //     You are given two integers N and i. You need to make ith bit of binary representation of N to 0 and return the updated N.
    //     Counting of bits start from 0 from right to left.
    int y, q;
    cin >> y;
    cin >> q;
    int d = (y ^ (1 << q));
    cout << d << endl;
}
