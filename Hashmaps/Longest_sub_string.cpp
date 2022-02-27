#include <iostream>
#include <unordered_map>
using namespace std;
int lengthOfLongestSubstring(string s)
{
    unordered_map<char, int> mp;
    int mx = 0, ln = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (mp[s[i]] > 0 && ln >= i - mp[s[i]] + 1)
        {
            ln = i - mp[s[i]] + 1;
            mp[s[i]] = i + 1;
        }
        else
        {

            mp[s[i]] = i + 1;
            ++ln;
        }
        mx = max(mx, ln);
    }
    return mx;
}
int main()
{
    cout << "Enter String : " << endl;
    string s;
    cin >> s;
    int len = lengthOfLongestSubstring(s);
    cout << "MAX Length is: " << len;
}