#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    // linear search
    int arr[] = {1, 10, 11, 40, 40, 40, 70, 80, 90, 100, 110, 120};
    int n = sizeof(arr) / sizeof(int);
    int key = 40;
    auto it = find(arr, arr + n, key);
    cout << it << endl;
    int index = it - arr;
    if (index == n)
    {
        cout << "Element NOT present" << endl;
    }
    else
    {
        cout << "Index of finded element is : " << index << endl;
    }
    // binary_search
    key = 49;
    bool present = binary_search(arr, arr + n, key);
    if (present)
    {
        cout << " Present" << endl;
    }
    else
    {
        cout << "Absent" << endl;
    }

    // get index of the element;
    // lower_bound(s,e,key) amd upper_bound(s,e,key)
    // array must be sorted.
    auto lb = lower_bound(arr, arr + n, 40);
    cout << "Lower Bound Index of 40 is : " << (lb - arr) << endl;

    // upper_bound it gives just bigger index
    auto ub = upper_bound(arr, arr + n, 40);
    cout << "Upper Bound Index of 40 is : " << (ub - arr) - 1 << endl;

    // hence finding occurance in O(log(n))
    cout << "Occurances freq of 40 is : " << (ub - lb) << endl;
}