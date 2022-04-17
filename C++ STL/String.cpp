#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
bool compare(string a, string b)
{
    if (a.length() == b.length())
    {
        return a < b;
    }
    return a.length() < b.length();
}
int main()
{
    string s0;
    string s1("Hello World!");
    string s2 = "Hello to All!";
    string s3(s2);
    cout << s3;
    char a[] = {'a', 'b', 'c', '\0'};

    string s4(a);
    cout << endl
         << s4 << endl;
    if (s4.empty())
    {
        cout << "Khali ha bhai" << endl;
    }
    else
    {
        cout << "Khali ni ha bhai" << endl;
    }
    s1.append(" I Love C++");
    cout << s1 << endl;
    s1 += " only";
    cout << s1;
    cout << s1.length() << endl;
    s1.clear();
    s0 = "Apple";
    s1 = "Mango";
    // Checks Lexicographically
    cout << s1.compare(s0) << endl; // return an integer > 0 or < 0 or =0
    if (s1 > s0)
    {
        cout << "Mango is Lexicographically greater than apple" << endl;
    }
    string s6 = "Hello to all I wanna tell you that I like apple most";
    int index = s6.find("apple");
    cout << index << endl;

    // removing word
    cout << "Removing word " << endl;
    string word = "apple";
    int len = word.length();
    cout << s6 << endl;
    s6.erase(index, len + 1);
    cout << s6 << endl;

    for (int i = 0; i < s1.length(); i++)
    {
        cout << s1[i] << " ";
    }
    cout << endl;

    // Iterator
    for (auto it = s1.begin(); it != s1.end(); it++)
    {
        cout << (*it) << " ";
    }
    cout << endl;

    for (auto c : s1)
    {
        cout << c << " ";
    }

    //-----------------------------------------------------------------

    cout << endl
         << "Enter NO. of strings : ";
    int n;
    cin >> n;
    cin.get();
    string s[100];
    // lexicographically sorting

    for (int i = 0; i < n; i++)
    {
        getline(cin, s[i]);
    }
    sort(s, s + n, compare);
    for (int i = 0; i < n; i++)
    {
        cout << s[i] << endl;
    }

    //------------------------------------------------------------------
}
