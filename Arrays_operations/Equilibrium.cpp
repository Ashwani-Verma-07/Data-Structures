#include <iostream>
using namespace std;
int main()
{

    int num, arr[1000], i = 0, sum = 0, sum1 = 0;
    cin >> num;
    for (int i = 0; i < num; i++)
    {
        cin >> arr[i];
    }
    // then equilibrium element is:
    for (int j = 0; j < num; j++)
    {
        sum += arr[j];
    }
    while (i < num)
    {
        int element = arr[i];

        sum -= element;

        if (sum == sum1)
        {
            cout << arr[i];
            break;
        }
        sum1 += element;
        i++;
    }
}