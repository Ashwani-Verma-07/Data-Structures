#include <iostream>
#include <unordered_set>
using namespace std;
int FindLongestSeq(int arr[], int n)
{
    unordered_set<int> s;
    for (int i = 0; i < n; i++)
    {
        s.insert(arr[i]);
    }
    // Iterate over all elements
    // Target those from which a streak can start
    int max_streak = 0;
    for (int i = 0; i < n; i++)
    {
        if (s.find(arr[i] - 1) == s.end())
        {
            // a[i] is starting point of streak
            // traverse the entire range that is contained in that streak

            int next_no = arr[i] + 1;
            int streak_len = 1;
            while (s.find(next_no) != s.end())
            {
                next_no += 1;
                streak_len += 1;
            }
            max_streak = max(streak_len, max_streak);
        }
    }
    return max_streak;
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