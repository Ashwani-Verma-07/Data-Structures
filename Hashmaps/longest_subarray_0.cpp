#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
// Longest Subarray with zero sum
// 0 -1 1 2 5 -5
// CS => 0 -1 0 2 7 2
int LongestSubarray(vector<int> &num, int n)
{
    unordered_map<int, int> map_;
    int pre = 0, len = 0;
    for (int i = 0; i < n; i++)
    {
        pre += num[i];
        if (pre == 0)
        {
            len = max(len, i + 1);
        }
        if (map_.find(pre) != map_.end())
        {
            len = max(len, i - map_[pre]);
        }
        else
        {
            map_[pre] = i;
        }
    }
    for (auto it : map_)
    {
        cout << it.first << " " << it.second << endl;
    }
    return len;
}
int main()
{
    int n;
    cin >> n;
    vector<int> num(n);
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }
    cout << LongestSubarray(num, n) << endl;
}