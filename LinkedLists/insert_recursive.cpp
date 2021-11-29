#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
    Node(int data){
       this->data=data;
       next=NULL;
    }
};
Node *recursive_cal(Node *head,int i,int key){
if(head==NULL){
    return head;
}
// Node *temp=head;
if(i==0){
    Node *temp=head;
    Node *newNode= new Node(key);
    newNode->next=temp->next;
 temp->next=newNode;
 
}
recursive_cal(head->next,i-1,key);
return head;
}
int main(){
     int data;
   cin>>data;
   Node *head=NULL;
   Node *tail=NULL;
   while(data!=-1){
       Node *newNode= new Node(data);
       Node *temp=head;
       if(head==NULL){
           head=newNode;
           tail=newNode;
       }
       else{
tail->next=newNode;
tail=tail->next;
       }
       cin>>data;
   }
   int i,key;
   cout<<"Enter Index to be enter the value"<<endl;
   cin>>i;
   cout<<"Enter the value to be inserted"<<endl;
   cin>>key;
   Node *star=recursive_cal(head,i-2,key);
   Node *temp=star;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}