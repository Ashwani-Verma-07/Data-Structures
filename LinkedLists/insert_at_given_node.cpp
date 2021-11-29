#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
    Node(int data){        //our constructor
this->data=data;
next=NULL;
    }
    int size;
    Node *next1;
  
};
Node *  input(){

    int data;
    cin>>data;
    Node *head=NULL;
    Node *tail=NULL;
    while(data!=-1){
        Node *address=new Node(data);
        if(head==NULL){
                head=address;
                tail=address;
        }
        else{
            tail->next=address;
            tail=tail->next;
        }
        cin>>data;
    }
}
void insertNode(Node *head,int i,int data){
    Node *address= new Node(data);
    int count=0;
    Node *temp=head;
    while(count<i-1){ 
        temp=temp->next;  
        count++;
    }
}

int main(){
 Node *ra= input();
    // int index;
    // cin>>index;
    // int s;
}