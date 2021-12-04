#include <iostream>
using namespace std;
class student{
    public :
    int roll_no;
    private :
    int age;
    public :
void display(){
    cout<<"roll no is:" <<roll_no<<endl;
    cout<<"age is:"<<age<<endl;
}
//our constructor
//similar to this inbuilt constructor is generated 
//if we declare this constructor then inbuilt constructor lost its signficance
student(){
    cout<<"constructor called"<<endl;
}
//Parametrized constructor
student(int roll_no){
    cout<<"Parametrized constructor"<<endl;
    if(roll_no<0){
        return;
    }

  this->  roll_no=roll_no; //if roll_no=roll-no is done then closest scope works.
}
student(int num,int r){
    cout<<"This keyword is :"<<this<<endl;   //holds address of current object
    cout<<"contructor called of 2 arguments"<<endl;
    age=num;
    roll_no=r;
}

}; 
int main(){
    student s1(10,24);
    cout<<"s1 address is :"<<&s1<<endl;
    s1.display();
    cout<<endl;
    student *s2=new student(20,51);
    cout<<"s2 address is :"<<&s2<<endl;
    s2->display();
    cout<<endl;
    student s3(28,74);
    cout<<"s3 address is :"<<&s3<<endl;
    s3.display();
    cout<<endl;

    // student s1;
    //  s1.roll_no=24;
    // s1.display();
  //  student s2; //interpret as s2.student();
   // student *s3 = new student;
    student s4(20); //interpret as s4.student(20);
    s4.display();
    student s5;
    
    // cout<<endl;
    // student *s5=new student(10001);
    // s5->display();
    // cout<<endl;
    // student s6(10,24);  //interpret as s6.student(10,24);
    // s6.display();
}