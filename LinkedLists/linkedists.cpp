#include<iostream>
using namespace std;
class Node {
    public:
    int data;
    Node*next;

    Node(int d){
        data=d;
        next=NULL;
    }
    void display(){
        cout<<"Data is: "<<data<<"--"<<"Address is: "<<next<<endl;
    }
};
int main(){
    //statically
//     Node n1(1);
//     Node *head=&n1;
//     Node n2(2);
//     n1.next=&n2;
//     cout<<head<<endl;
//    n1.display();
   
//    n2.display();
//    cout<<&n2<<endl;
    //Dynamically
    Node *n3=new Node(10);
     Node *n4=new Node(20);
     Node *head=n3;
     n3->next=n4;
     cout<<head<<endl;
     n3->display();
     n4->display();

}