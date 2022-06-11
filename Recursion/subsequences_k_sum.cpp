#include <iostream>
#include <vector>
using namespace std;
void printS_k(int i, vector<int> &ds, int s, int sum, int arr[], int n)
{
    if (i == n)
    {
        if (s == sum)
        {
            for (auto it : ds)
                cout << it << " ";
            cout << endl;
        }
        return;
    }
    ds.push_back(arr[i]);
    s += arr[i];
    printS_k(i + 1, ds, s, sum, arr, n);
    s -= arr[i];
    ds.pop_back();
    // not pick
    printS_k(i + 1, ds, s, sum, arr, n);
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr) / sizeof(int);
    vector<int> ds;
    int sum = 5;
    printS_k(0, ds, 0, sum, arr, n);
}