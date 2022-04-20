#include <iostream>
#include <list>
using namespace std;
int main()
{
    // list is doubly linkedlist
    // helpful in in insertion ,deletion, remove head or tail -> front-middle
    // push_back pop_back push_front pop_front insert erase(indx) remove(indx)
    string f;
    list<int> l;
    // initialize
    list<int> l1{1, 2, 3, 4, 5, 6};
    list<string> l2{"apple", "guava", "mango", "banana"};
    for (string a : l2)
    {
        cout << a << "-->";
    }
    cout << endl;
    l2.sort();

    l2.reverse();
    cout << l2.front() << endl;
    l2.pop_front();
    for (string a : l2)
    {
        cout << a << "-->";
    }
    l2.push_back("kiwi");

    cout << endl;
    for (string a : l2)
    {
        cout << a << "-->";
    }
    l2.pop_back();
    cout << endl;
    for (auto it = l2.begin(); it != l2.end(); it++)
    {
        cout << (*it) << "-->";
    }

    l2.push_back("orange");
    l2.push_back("lemon");
    cout << endl;
    for (string a : l2)
    {
        cout << a << "-->";
    }
    cout << endl
         << "Enter a fruit to remove : ";
    //  remove a fruit
    cin >> f;
    l2.remove(f);
    for (string a : l2)
    {
        cout << a << "-->";
    }

    // erase some element s in list
    auto it = l2.begin();
    it++;
    l2.erase(it);
    cout << endl;
    cout << "Erased string : " << endl;
    for (string a : l2)
    {
        cout << a << "-->";
    }

    // insert element
    it = l2.begin();
    it++;
    l2.insert(it, "FruitJuice");
    cout << endl;
    for (string a : l2)
    {
        cout << a << "-->";
    }
}
