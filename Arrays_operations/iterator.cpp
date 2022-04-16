#include <iostream>
#include <list>
using namespace std;
template <typename ForwardIterator, typename T>
//  template<class ForwardIterator, class T>
ForwardIterator search(ForwardIterator start, ForwardIterator end, T key)
{
    while (start != end)
    {
        if (*start == key)
        {
            return start;
        }
        start++;
    }
    return end;
}
int main()
{

    // int arr[] = {1, 2, 3, 4, 5, 6};
    // int n = sizeof(arr) / sizeof(int);
    // cout << search(arr, n, 5);
    list<int> l;
    int a, key, n;
    cout << "Enter NO. of elements ";
    cin >> n;
    cout << "Enter values :";
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        l.push_back(a);
    }
    cout << "Enter key to find" << endl;
    cin >> key;
    auto it = search(l.begin(), l.end(), key);
    if (it == l.end())
    {
        cout << "Elemnt not find" << endl;
    }
    else
    {
        cout << "Eement " << *it << " Found" << endl;
    }
}