#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node*next;

    Node(int data){              //our constructor
        this ->data=data;
        next=NULL;
    }
  
};

  Node *takeinput_better(){
    int data;
    cin>>data;
    Node *head=NULL;
    Node *tail=NULL;

    while(data!= -1   ){
        Node *newNode=new Node(data);        //dynamic allocation
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
    return head;
}

void print(Node *head){
         
    Node *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
 }

int main(){
    
Node *head=takeinput_better();
print(head);

}