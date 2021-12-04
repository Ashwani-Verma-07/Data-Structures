#include <iostream>
#include <string>
using namespace std;
class Employee
{
public:
    Employee()
    {
        cout << "Constructor called" << endl;
    }
    ~Employee()
    {
        cout << "Destructor called" << endl;
    }
};
int main(void)
{
    Employee e1; //creating an object of Employee
    Employee e2; //creating an object of Employee
    return 0;
}
