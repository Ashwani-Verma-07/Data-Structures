#include <iostream>
#include <unordered_map>
#include <climits>
using namespace std;
string string_win(string a, string b)
{

    int FP[256] = {0};
    int FS[256] = {0};
    for (int i = 0; i < b.length(); i++)
    {
        FP[b[i]]++;
    }
    int count = 0, start = 0, start_index = -1;
    int min_so_far = INT_MAX, window_size;

    // Sliding Window algotrithm
    for (int i = 0; i < a.length(); i++)
    {
        char ch = a[i];
        FS[ch]++;
        // count how many characters have been matched till now (string and pattern)
        if (FP[ch] != 0 and FS[ch] <= FP[ch])
        {
            count += 1;
        }
        // another thing
        // if all chracters of the pattern are found in the current window then start contracting

        if (count == b.length())
        {
            // start contracting from the left to remove unwanted character
            while (FP[a[start]] == 0 or FS[a[start]] > FP[a[start]])
            {
                FS[a[start]]--;
                start++;
            }

            // note the window size
            int window_size = i - start + 1;
            if (window_size < min_so_far)
            {
                min_so_far = window_size;
                start_index = start;
            }
        }
    }
    return a.substr(start_index, min_so_far);
}
int main()
{
    string a, b;
    cout << "Enter large string" << endl;
    cin >> a;
    cout << "Enter small string" << endl;
    cin >> b;
    cout << string_win(a, b) << endl;
}