#include<iostream>
using namespace std;
class Node {
    public:
    int data;
    Node*next;

    Node(int data){
        this->data=data;
        next=NULL;
    }
};
void print(Node *head){
    Node *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;

    }
    temp=head;
      while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;

    }
}
int main(){
Node n1(1);    //Statically
Node *head =&n1;
Node n2(2);
//Dynamically
// Node *n3=new Node(10);
// Node *n4=new Node(20);
// Node *head=n3;
// n3->next=n4;
// //cout<<n3.data<<" "<<n4.data<<endl;
Node n3(3);
Node n4(4);
Node n5(5);
n1.next=&n2;
n2.next=&n3;
n3.next=&n4;
n4.next=&n5;
print(head);
}