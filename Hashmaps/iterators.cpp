#include <bits/stdc++.h>
using namespace std;
int main()
{
    unordered_map<string, int> ourmap;
    ourmap["abc"] = 1;
    ourmap["abc1"] = 2;
    ourmap["abc2"] = 3;
    ourmap["abc3"] = 4;
    ourmap["abc4"] = 5;
    unordered_map<string, int>::iterator it = ourmap.begin();
    while (it != ourmap.end())
    {
        cout << "key : " << it->first << " Value " << it->second << endl;
        it++;
    }
    for (it = ourmap.begin(); it != ourmap.end(); it++)
    {
        cout << it->first << " value " << it->second << endl;
    }
    //find ->this gives a iterator named it2 : we can access this elemtent and after this element also.

    unordered_map<string, int>::iterator it2 = ourmap.find("abc");
    //erase

    //ourmap.erase(it2, it2 + 2);
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    vector<int>::iterator it1 = v.begin();
    while (it1 != v.end())
    {
        cout << *it1 << endl;
        it1++;
    }
    return 0;
}