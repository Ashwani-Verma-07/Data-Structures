#include <iostream>
using namespace std;
int matrix_call(int n)
{
    if (n < 1)
    {
        return 0;
    }
    if (n < 4)
    {
        return 1;
    }
    if (n == 4)
    {
        return 2;
    }

    return matrix_call(n - 1) + matrix_call(n - 4);
}
int main()
{
    int n;
    cin >> n;
    cout << matrix_call(n) << endl;
}