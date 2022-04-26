#include <iostream>
#include <map>
using namespace std;
int main()
{
    // Multimap -> same keys present
    // map -> unique keys
    // key  -  value
    // b    -  boat
    // b    -  batman
    multimap<char, string> m;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        char ch;
        string s;
        cin >> ch >> s;
        m.insert(make_pair(ch, s));
    }
    auto it = m.begin();
    m.erase(it);

    auto it2 = m.lower_bound('b');
    auto it3 = m.upper_bound('d');
    for (auto it4 = it2; it4 != it3; it4++)
    {
        cout << it3->second << " " << it4->second << endl;
    }

    // Finding
    auto f = m.find('c');
    it(f->second == 'cat')
    {
        m.erase(f);
    }
    // Try to print entire row;
    for (auto p : m)
    {
        cout << p.first << " -> " << p.second << endl;
    }
}
// 7
// b batman
// a apple
// c cat
// a alu_bhukhara
// d mango
// b bat
// e hello