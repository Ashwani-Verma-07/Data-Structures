#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
int main()
{
    unordered_map<string, vector<string>> phone_book;
    phone_book["Rahul"].push_back("9874563210");
    phone_book["Ashwani"].push_back("9856321457");
    phone_book["Abhinav"].push_back("9856345781");
    phone_book["Arjun"].push_back("9845651232");
    phone_book["Arjun"].push_back("999999999");
    phone_book["Ashwani"].push_back("9205913827");
    phone_book["Abhinav"].push_back("0009133333");

    for (auto p : phone_book)
    {
        cout << "Name :" << p.first << " -> ";
        for (string s : p.second)
        {
            cout << s << ",";
        }
        cout << endl;
    }
    string name;
    cin >> name;
    if (phone_book.count(name) == 0)
    {
        cout << "absent" << endl;
    }
    else
    {
        for (string s : phone_book[name])
        {
            cout << s << endl;
        }
    }
}