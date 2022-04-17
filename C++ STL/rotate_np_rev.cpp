#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    int arr[] = {10, 20, 30, 40, 50, 60, 70};
    int n = sizeof(arr) / sizeof(int);
    rotate(arr, arr + 2, arr + n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    // Apply same on the vector
    vector<int> v{1, 2, 3};
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    rotate(v.begin(), v.begin() + 2, v.end());
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl
         << "Next permutation is : ";
    // Next_permutation
    next_permutation(v.begin(), v.end());
    for (int x : v)
    {
        cout << x << " ";
    }
    cout << endl
         << "Next permutation is : ";
    next_permutation(v.begin(), v.end());
    for (int x : v)
    {
        cout << x << " ";
    }

    // Swaping
    int a = 10;
    int b = 20;
    swap(a, b);
    cout << endl
         << "Swapping : " << a << " " << b << endl;
    int srr[] = {1, 2, 3, 4, 5, 6, 7};
    reverse(srr, srr + 2); // complete reverse(srr,srr+n);
    cout << "Reverse : ";
    for (int i = 0; i < 7; i++)
    {
        cout << srr[i] << " ";
    }
    cout << endl;
    next_permutation(srr, srr + n);
    for (int i = 0; i < 7; i++)
    {
        cout << srr[i] << " ";
    }
}