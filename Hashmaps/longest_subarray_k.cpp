#include <iostream>
#include <unordered_map>
using namespace std;
int LongestSubarray(int arr[], int n, int k)
{
    unordered_map<int, int> map_;
    int pre = 0;
    int len = 0;
    for (int i = 0; i < n; i++)
    {
        pre += arr[i];
        if (pre == k)
        {
            len = max(len, i + 1);
        }
        if (map_.find(pre - k) != map_.end())
        {
            len = max(len, i - map_[pre - k]);
        }
        else
        {
            map_[pre] = i;
        }
    }
    return len;
}
int main()
{
    int n, arr[1000], k;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Enter number to find "
         << "\n";
    cin >> k;
    cout << "Longest Subarray is : " << LongestSubarray(arr, n, k) << endl;
}

// Total Number of Subarray of sum equals to k
// unordered_map<int,int> mp;
//         mp[0] = 1; // Because getting zero sum is always possible.
//         int sum = 0;
//         int ans = 0;
//         for(int i = 0;i<nums.size();i++)
//         {
//             sum = sum + nums[i];
//             int req =  sum - k;
//             if(mp.find(req)!=mp.end())
//             {
//                 ans+=mp[req];  // use the number of times the required sum has already occurred
//             }

//             mp[sum]+=1;
//         }

//         return(ans);