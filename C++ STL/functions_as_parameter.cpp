#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
// defining a comparator function
bool compare(int a, int b)
{

    return a < b;
}
// void bubble_sort(vector<int> &a, int n, bool (&cmp)(int a, int b))
//{
//      for (int i = 1; i < n; i++)
//      {
//          for (int j = 0; j < n - i; j++)
//          {
//              if (cmp(a[j], a[j + 1]))
//              {
//                  swap(a[j + 1], a[j]);
//              }
//          }
//      }
//}

int main()
{
    int n;
    cout << "Enter NO. of elements" << endl;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    // bubble_sort(v, n, compare);
    sort(v.begin(), v.begin() + n, compare);
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
}