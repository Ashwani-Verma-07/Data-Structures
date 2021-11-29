#include<iostream>
using namespace std;
class Node{
    public :
    int data;
    Node *next;
    Node(int data){
        this->data=data;
        next=NULL;
    }

};
int input(){

    int data,key;
    cin>>data;
    int count=0;
    Node *head=NULL;
    Node *tail=NULL;
    while(data!=-1){
        Node *number=new Node(data);
        if(head==NULL){
            head=number;
            tail=number;
        }
        else{
                  tail->next=number;
                  tail=tail->next;
        }
        cin>>data;
        
       
    }
    cin>>key;

    Node *temp=head;
    while(temp!=NULL){
        
        if(count==key)
        cout<<temp->data<<" ";
        temp=temp->next;
        count++;
    }

  

    return 0;
}
int main(){
    int r=input();
}