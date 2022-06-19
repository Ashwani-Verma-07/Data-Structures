#include <iostream>
#include <cstring>
using namespace std;

char keypad[][10] = {"", "", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"};
void generate_names(char *in, char *out, int i, int j)
{
    // base case;
    if (in[i] == '\0')
    {
        out[j] = '\0';
        cout << out << endl;
        return;
    }
    // rec case;
    int digit = in[i] - '0';
    if (digit == 1 || digit == 0)
    {
        generate_names(in, out, i + 1, j);
    }
    for (int k = 0; keypad[digit][k] != '\0'; k++)
    {
        out[j] = keypad[digit][k];

        // fill the remaining part
        generate_names(in, out, i + 1, j + 1);
    }
    return;
}
// int main()
// {
//     string input;
//     string output;
//     cin >> input;
//     call(input, output);
// }
int main()
{
    char input[1000];
    cin >> input;
    char out[1000];
    generate_names(input, out, 0, 0);
}
// Input : 123
// Output :
// AD
// AE
// AF
// BD
// BE
// BF
// CD
// CE
// CF