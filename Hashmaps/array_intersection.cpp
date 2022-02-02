#include <bits/stdc++.h>
using namespace std;
int main()
{
    int p, q, arr[1000], srr[1000];
    std::unordered_map<int, int> map, map_;

    cout << "Enter size of Array1 : ";
    cin >> p;
    cout << "Enter size of Array2 : ";
    cin >> q;
    cout << "Enter Elements " << endl;
    for (int i = 0; i < p; i++)
    {
        cin >> arr[i];
        map[arr[i]]++;
    }
    for (int i = 0; i < q; i++)
    {
        cin >> srr[i];
        map[srr[i]]++;
    }
    int num = 1;
    cout << "Common elements are : " << endl;
    for (auto pr : map)
    {
        if (num < pr.second)
        {
            cout << pr.first << " ";
        }
    }
}