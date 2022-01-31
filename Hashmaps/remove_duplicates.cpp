#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
vector<int> remove_duplicates(int a[], int size)
{
    vector<int> output;
    unordered_map<int, bool> seen;
    for (int i = 0; i < size; i++)
    {
        if (seen.count(a[i]) > 0)
        {
            continue;
        }
        seen[a[i]] = true; //O(1)
        output.push_back(a[i]);
    }
    return output;
}

int main()
{
    int n, arr[1000];
    cout << "Enter Size of Array : " << endl;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<int> output = remove_duplicates(arr, n);
    for (auto i : output)
    {
        cout << i << " ";
    }
    //return maximum times string;
    cout<<"Enter a String"<<endl;
    string str;
    cin >> str;

    unordered_map<char, int> map;
    for (int i = 0; i < str.size(); i++)
    {
        map[str[i]]++;
    }
    int maxCount = 0;
    char ch;
    for (pair<char, int> p : map)
    {
        if (maxCount < p.second)
        {
            maxCount = p.second;
            ch = p.first;
        }
    }
    cout << ch;
}

//1 1 2 2 5 5 6 8 4 1 5 5 0 0 0 7 4 6 -1
//aaabcdrfere
