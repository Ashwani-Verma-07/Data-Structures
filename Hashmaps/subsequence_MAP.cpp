#include <bits/stdc++.h>
using namespace std;
int FindLongestSeq(int arr[], int n)
{
    unordered_map<int, int> map_;
    for (int i = 0; i < n; i++)
    {
        int no = arr[i];
        if (map_.count(no - 1) == 0 && map_.count(no + 1) == 0)
        {
            map_[no] = 1;
        }
        else if (map_.count(no - 1) && map_.count(no + 1))
        {
            int len1 = map_[no - 1];
            int len2 = map_[no + 1];

            int streak = len1 + 1 + len2;
            map_[no - len1] = streak;
            map_[no + len2] = streak;
        }
        else if (map_.count(no - 1) && !map_.count(no + 1))
        {
            int len = map_[no - 1];
            map_[no - len] = len + 1;
            map_[no] = len + 1;
        }
        else
        {
            int len = map_[no + 1];
            map_[no + len] = len + 1;
            map_[no] = len + 1;
        }
    }
    int largest = 0;
    for (auto it : map_)
    {
        largest = max(largest, it.second);
    }
    return largest;
}
int main()
{
    int n, arr[10000];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << FindLongestSeq(arr, n) << endl;
}
// Input:
// 15
// 14 5 1 2 6 3 7 8 9 13 15 11 12 13 17
// Output:
// 5
