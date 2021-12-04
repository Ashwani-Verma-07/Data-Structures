#include<iostream>
using namespace std;

class student{
    public :
    int roll_no;
  
    int age;
    public :
void display(){
    cout<<age<<" -- "<< roll_no<<endl;
}
};
int main(){
    student s1;
    student *s2=new student;
    s1.age=24;
    (*s2).roll_no=1001;
}