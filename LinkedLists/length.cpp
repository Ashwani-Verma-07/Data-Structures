#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
    Node(int da){
        data=da;
        next=NULL;
    }
};
int input(){
    int data;
    cin>>data;
    Node *head=NULL;
    Node *tail=NULL;
    while (data!=-1)
    {
        Node *newNode=new Node(data);
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
    Node *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    return 0;
    
}
        
        
        int main(){
    int ne =input();

}