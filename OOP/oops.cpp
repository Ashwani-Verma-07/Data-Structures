#include <iostream>
using namespace std;
class student{
    public :
    int roll_no;
    private :
    int age;
    public :
void display(){
    cout<<age<<" -- "<< roll_no<<endl;
}
int getAge(int age){
    return age;
}
void setAge(int a,int password){
    if(password !=123){
        return;
    }
    if(age<0){
        return;
    }
    age=a;
}
}; 
int main(){
    //create objects statically
    student s1;
    //s1.age=24;
    s1.roll_no=1001;
    s1.setAge(20,123);
    cout<<"s1 age is "<<s1.getAge(28)<<endl;
    cout<<"s1 roll no is "<<s1.roll_no<<endl;
    //create objects dynamically
    student *s2= new student;
   // (*s2).age=23;    //s2-> age=23;
    (*s2).roll_no=1002;
    s2->setAge(22,123);
    s2->roll_no=1003;
    cout<<endl<<endl;
    s1.display();  
    s2->display(); 
    cout<<endl<<endl; 
    //another way of declaring dynamic objects.
    cout<<"s2 age is "<<s2->getAge(42)<<endl;
    cout<<"s2 roll no is "<<s2->roll_no<<endl;
}