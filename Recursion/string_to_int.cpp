#include <iostream>
#include <cstring>
using namespace std;
int arr[][10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
int calling_int(char *chr, int ep)
{
    if (ep == 0)
    {
        return 0;
    }
    int digit = chr[ep - 1] - '0';
    int small_ans = calling_int(chr, ep - 1);
    return small_ans * 10 + digit;
}

int main()
{
    char chr[] = {"1235"};
    int n = strlen(chr);
    cout << calling_int(chr, n) << " " << endl;
}