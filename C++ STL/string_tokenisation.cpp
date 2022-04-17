#include <bits/stdc++.h>
using namespace std;

// char *strtok(char *s,char *delimiters)
// return a token on each subsequent call
// on the first call function should be passed with string argument for 's'
// on subsequent calls we should pass the string argument as null

char *mystrtok(char *str, char delim)
{
    // string and char can act as a delimiter.
    static char *input = NULL;
    if (str != NULL)
    {
        // we are making first call
        input = str;
    }
    // check here -base case after the final token has been returned
    if (input == NULL)
    {
        return NULL;
    }
    // start extracting tokens and store them in an array
    char *output = new char[strlen(input) + 1];
    int i = 0;
    for (; input[i] != '\0'; i++)
    {
        if (input[i] != delim)
        {
            output[i] = input[i];
        }
        else
        {
            output[i] = '\0';
            input = input + i + 1;
            return output;
        }
    }
    // corner case
    output[i] = '\0';
    input = NULL;
    return output;
}
int main()
{
    char s[100] = "Today is a rainy day but Tommorow is shiny day"; // delimiter is space;
    //  tokenisation done by computer.
    //  char *ptr = strtok(s, " ");     // here delimiter is space -> " "
    //  cout << ptr << endl;

    // while (ptr != NULL)
    // {
    //     ptr = strtok(NULL, " ");
    //     cout << ptr << endl;
    // }

    // Our own tokenisation function.
    char *ptr = mystrtok(s, ' ');

    cout << ptr << endl;

    while (ptr != NULL)
    {
        ptr = mystrtok(NULL, ' ');
        cout << ptr << endl;
    }
    return 0;
}
//  Output:
//  Today
//  is
//  a
//  rainy
//  day
//  but
//  Tommorow
//  is
//  shiny
//  day