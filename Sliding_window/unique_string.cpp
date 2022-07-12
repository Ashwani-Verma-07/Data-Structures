#include <iostream>
#include <unordered_map>
using namespace std;
string unique_string(string s)
{
    int i = 0, j = 0;
    unordered_map<char, int> map_;
    int window_len = 0;
    int max_window = 0;
    int start_window = -1;
    while (j < s.length())
    {
        char ch = s[j];
        // if it is inside hasmap & its index>=start of the current window
        if (map_.count(ch) != 0 and map_[ch] >= i)
        {
            i = map_[ch] + 1;
            window_len = j - i; // updated remaining window len excluding current char
        }
        map_[ch] = j;
        window_len++;
        j++;
        if (window_len > max_window)
        {
            max_window = window_len;
            start_window = i;
        }
    }
    return s.substr(start_window, max_window);
}
int main()
{
    string s;
    cin >> s;
    cout << unique_string(s) << endl;
    return 0;
}