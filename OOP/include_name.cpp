#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class studentName
{
    char *name;
    int age;

public:
    studentName(int age, char *name) //constructor generated
    {
        this->age = age; //as parameter name and
        //shallow copy //if we don't create our constructor then by default shallow copy done.
        // this->name = name;
        //Deep copy
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name); //strcpy(destination,source)
    }
    //copy constructor
    studentName(studentName const &s)
    {
        this->age = s.age;
        //deep copy
        this->name = new char[strlen(s.name) + 1];
        strcpy(this->name, s.name);
    }

    void display()
    {
        cout << age << " " << name << endl;
    }
};
int main()
{
    char name[] = "abcd";

    studentName s1(10, name);
    s1.display();
    studentName s2(s1);
    //studentName s2(20, name); //s2(age,name 1st address)
    name[3] = 'e';

    cout << "s2 display " << endl;
    s2.display();
    cout << "s1 display " << endl;
    s2.display();
}