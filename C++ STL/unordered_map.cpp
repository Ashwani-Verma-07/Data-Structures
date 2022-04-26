#include <iostream>
#include <unordered_map>
#include <cstring>
using namespace std;

class Student
{
public:
    string firstname;
    string lastname;
    string rollno;
    Student(string first, string last, string roll)
    {
        firstname = first;
        lastname = last;
        rollno = roll;
    }
    bool operator==(const Student &s) const
    {
        return rollno == s.rollno ? true : false;
    }
};
class HashFn
{
public:
    size_t operator()(const Student &s) const
    {
        // Operator Overloading
        return s.firstname.length() + s.lastname.length();
    }
};
int main()
{
    unordered_map<Student, int, HashFn> student_map;
    Student s1("Ashwani", "Verma", "025");
    Student s2("Abhinav", "Yadav", "001");
    Student s3("Ashwani", "Yadav", "026");
    Student s4("Abhinav", "Verma", "002");

    // Add studetn makrs to hashmap;

    student_map[s1] = 100;
    student_map[s2] = 120;
    student_map[s3] = 140;
    student_map[s4] = 160;

    cout << student_map[s3] << endl;
    // iterate pver all students
    for (auto s : student_map)
    {
        cout << s.first.firstname << " " << s.first.lastname << s.second << endl;
    }
}