#include <iostream>
using namespace std;
char chr[][10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
void call_for_string(int n)
{
    if (n == 0)
    {
        return;
    }
    call_for_string(n / 10);
    int digit = n % 10;
    cout << chr[digit];
}
int main()
{
    int n;
    cin >> n;
    call_for_string(n);
}