#include <iostream>
#include <vector>
using namespace std;
void sub(vector<int> &num, vector<int> &ds, int i, int n)
{
    if (i >= n)
    {
        for (auto it : ds)
        {
            cout << it << " ";
        }
        cout << endl;
        return;
    }
    ds.push_back(num[i]);
    sub(num, ds, i + 1, n);
    ds.pop_back();
    sub(num, ds, i + 1, n);
}
int main()
{
    vector<int> num{3, 1, 2};
    int n = num.size();
    vector<int> ds;
    sub(num, ds, 0, n);
}
