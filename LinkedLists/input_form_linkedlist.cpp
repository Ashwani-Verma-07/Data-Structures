#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node*next;

    Node(int data){              //constructor
        this ->data=data;
        next=NULL;
    }
  
};
    
    Node *takeinput(){
    int data;
    cin>>data;
    Node *head=NULL;
    int count=0;

    while(data!= -1){
        Node *newNode=new Node(data);
     if(head==NULL){
         head=newNode;
     }
     else{
        
         Node *temp=head;
         while(temp->next!=NULL){
             temp=temp->next;
         }
         temp->next=newNode;
     }
        cin>>data;
    }
    Node *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    
return head;
}


int main(){
    
Node *head=takeinput();

}