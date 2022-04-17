#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    pair<int, char> p;
    p.first = 10;
    p.second = 'A';
    cout << p.first << " " << p.second << endl;
    pair<int, char> p2(p);
    cout << p2.first << " " << p2.second << endl;
    pair<int, string> p3 = make_pair(20, "Ashwani");
    cout << p3.first << " " << p3.second << endl;
    int a, b;
    cin >> a >> b;
    pair<int, int> p4 = make_pair(a, b);

    // Array of pairs
    // vector of pairs
    pair<pair<int, int>, string> car;
    car.second = "Rolls-Royce";
    car.first.first = 700000;
    car.first.second = 20;
    cout << car.second << " is of $" << car.first.first << endl;
}