#include<iostream>
using namespace std;

class student{
   public:
    int age;
    private:
    int roll_no;
    public:

    void display(){
        cout<<age<<"--"<<roll_no<<endl;
    }
    student(int a,int b){
        age=a;
        roll_no=b;
    }
};
int main(){

student s1(101,100010);
student s2(s1); //copy constructor
s1.display();
s2.display();
student *s3=new student(20,100050);
student s4(*s3);
student *s5=new student(s1);
s3->display();
s4.display();
s5->display();
}