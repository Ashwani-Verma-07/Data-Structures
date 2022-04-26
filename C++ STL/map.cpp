#include <iostream>
#include <map>
#include <string>
using namespace std;
int main()
{
    map<string, int> m;

    // Insert
    m.insert(make_pair("Mango", 100));
    pair<string, int> p;
    p.first = "Apple";
    p.second = 200;

    // Search
    string fruits;
    cin >> fruits;

    // Updating
    // m[fruits] += 22;
    auto it = m.find(fruits);
    if (it != m.end())
    {
        cout << "Price of " << fruits << " is " << m[fruits] << endl;
    }
    else
    {
        cout << "Fruit is not present" << endl;
    }

    // It stores unique key only once
    if (m.count(fruits))
    {
        cout << "Price of " << fruits << " is " << m[fruits] << endl;
    }
    else
    {
        cout << "NOT found" << endl;
    }

    // erase
    // m.erase(fruits);
    cout << "Iteration" << endl;
    m["Litchi"] = 300;
    m["Guava"] = 120;
    for (auto it = m.begin(); it != m.end(); it++)
    {
        cout << it->first << " " << it->second << endl;
    }

    // OR
    for (auto p : m)
    {
        cout << p.first << " " << p.second << endl;
    }
    // All these are Lexicographically sorted
}