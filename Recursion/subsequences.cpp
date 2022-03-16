#include <iostream>
#include <cstring>
using namespace std;
void sequences(string in, char *out, int i, int j)
{
    if (in[i] == '\0')
    {
        out[j] = '\0';
        cout << out << endl;
        return;
    }
    // including elements in output array;
    out[j] = in[i];
    sequences(in, out, i + 1, j + 1);
    // excluding elements in output array;
    sequences(in, out, i + 1, j);
}
int main()
{
    cout << "Enter set to find power set " << endl;
    string input;
    cin >> input;
    char output[1000];
    cout << endl;
    sequences(input, output, 0, 0);
}