#include <bits/stdc++.h>
using namespace std;
class Person
{
public:
    int age;
    string name;
    Person(string name, int age)
    {
        this->name = name;
        this->age = age;
    }
};
class PersonCompare
{
public:
    bool operator()(Person A, Person B)
    {
        cout << "Hello"
             << " ";
        return A.age < B.age;
    }
};
int main()
{
    int n;
    cin >> n;
    priority_queue<Person, vector<Person>, PersonCompare> pq;
    for (int i = 0; i < n; i++)
    {
        string name;
        int age;
        cin >> name >> age;
        Person p(name, age);
        pq.push(p);
    }
    int k = 3;
    for (int i = 0; i < k; i++)
    {
        Person p = pq.top();
        cout << p.name << " " << p.age << endl;
        pq.pop();
    }
    return 0;
}