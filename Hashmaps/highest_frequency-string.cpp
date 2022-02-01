#include <bits/stdc++.h>
using namespace std;
int main()
{
    //For characters
    cout << "Enter a string : " << endl;
    string str;
    cin >> str;

    unordered_map<char, int> map_;
    for (int i = 0; i < str.size(); i++)
    {
        map_[str[i]]++;
    }
    int maxCount = 0;
    char ch;
    unordered_map<char, int>::iterator it;
    // for (pair<char, int> p : map_)
    // {
    //     if (maxCount < p.second)
    //     {
    //         maxCount = p.second;
    //         ch = p.first;
    //     }
    // }

    for (it = map_.begin(); it != map_.end(); it++)
    {
        if (maxCount < it->second) //(*it).second)
        {
            maxCount = it->second; //(*it).second
            ch = it->first;        //(*it).first
        }
    }

    cout << ch;

    //For integers
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        a.push_back(a[i]);
    }
    unordered_map<int, int> freq;
}