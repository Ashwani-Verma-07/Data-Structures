#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter Number of blocks" << endl;
    cin >> n;
    int arr[n];
    cout << "Enter Land Area" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int k;
    cout << "Enter Land you want to buy" << endl;
    cin >> k;
    int i = 0, j = 0, sum = 0;

    while (j < n)
    {
        sum += arr[i];
        if (sum == k)
        {
            sum = 0;
            cout << "Portion is : ";
            cout << j << " " << i << endl;
            j++;
            i = j;

            continue;
        }
        if (sum > k)
        {
            sum = 0;
            j++;
            i = j;
            continue;
        }
        i++;
    }
}
// output:
//  Enter Number of blocks
//  10
//  Enter Land Area
//  0 1 5 2 89 6 3 4 5 4
//  Enter Land you want to buy
//  9
//  Portion is : 5 6
//  Portion is : 7 8
//  Portion is : 8 9
