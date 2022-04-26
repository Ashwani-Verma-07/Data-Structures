#include <iostream>
#include <set>
#include <climits>
using namespace std;
void main_next()
{

    // lower_bound  >=  , upper_bound  >
    set<pair<int, int>> s;
    s.insert(make_pair(10, 1));
    s.insert(make_pair(20, 2));
    s.insert(make_pair(30, 3));
    s.insert(make_pair(40, 4));
    s.insert(make_pair(50, 5));
    s.insert(make_pair(60, 6));
    s.insert(make_pair(70, 7));

    // erase//insert
    s.erase(s.find(make_pair(50, 5)));
    s.insert(make_pair(20, 4));
    auto it = s.upper_bound(make_pair(20, 2));
    auto its = s.lower_bound(make_pair(60, 6));

    cout << "Upper_Bound"
         << " ";
    cout << it->first << " " << it->second << endl;
    cout << "Lower_Bound"
         << " ";
    cout << its->first << " " << its->second << endl;

    auto it1 = s.upper_bound(make_pair(40, INT_MAX));
    cout << it1->first << " " << it1->second << endl;

    for (auto p : s)
    {
        cout << p.first << " " << p.second << endl;
    }
}
int main()
{
    // SET
    //-> Stores Unique Elements  , default-> ordered
    //{1,2,3,4,1,2,1,2,3,2,1,5,6,1,2} ->{1,2,3,4,5,6};
    // Bst/RED Black Tree
    // O(log(n))
    // You can't update eleemnts i,e. insert,iterate,erase,check

    int arr[] = {10, 20, 30, 10, 11, 9, 8, 11};
    int n = sizeof(arr) / sizeof(int);
    set<int> s;
    for (int i = 0; i < n; i++)
    {
        s.insert(arr[i]);
    }
    s.erase(10);
    auto it = s.find(11);
    s.erase(it);
    // Print
    for (set<int>::iterator it = s.begin(); it != s.end(); it++)
    {
        cout << *(it) << " ";
    }
    cout << endl;
    main_next();
    return 0;
}
