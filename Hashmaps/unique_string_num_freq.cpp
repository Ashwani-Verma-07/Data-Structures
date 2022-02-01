#include <iostream>
#include <unordered_map>
#include <map>
using namespace std;
int main()
{
    unordered_map<string, int> um;
    cout << "Enter the no. of String" << endl;
    int n;
    cin >> n;
    cout << "Enter String" << endl;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        um[s] = um[s] + 1;
    }
    for (auto pr : um)
    {
        cout << pr.first << " " << pr.second << endl;
    }
    cout << "Enter NO." << endl;
    unordered_map<int, int> map;
    int k, arr[100];
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> arr[i];
        map[arr[i]]++;
    }
    for (auto pr : map)
    {
        cout << pr.first << " " << pr.second << endl;
    }
    cout << "Maximum ocurrance element is : " << endl;
    int num = 0;
    int s;
    for (auto pr : map)
    {
        if (num < pr.second)
        {
            num = pr.second;
            s = pr.first;
        }
    }
    cout << s << endl;
}
//if unordered_map:
// output:
// 8
// abc def abc ghi jkl jkl ghi abc
// jkl 2
// ghi 2
// abc 3
// def 1
// if map :
// 8
// abc def abc ghi jkl jkl ghi abc
// abc 3
// def 1
// ghi 2
// jkl 2