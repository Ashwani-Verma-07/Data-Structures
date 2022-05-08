#include <iostream>
#include <unordered_set>
using namespace std;
bool checkSum(int arr[], int n)
{
    unordered_set<int> set_;
    int pre = 0;
    for (int i = 0; i < n; i++)
    {
        pre += arr[i];

        // check if th sum was already present in the set
        if (pre == 0 or set_.find(pre) != set_.end())
        {
            return true;
        }
        set_.insert(pre);
    }
    return false;
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    if (checkSum(arr, n))
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}