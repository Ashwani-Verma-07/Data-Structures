#include<iostream>
using namespace std;
void call(char a[],char b,char c){
    if(a[0]=='\0'){
        return;
    }
    if(a[0]==b){
        a[0]=c;
        call(a+1,b,c);
    }
    else{
        call(a+1,b,c);
    }

}
int main(){
    char a[1000],b,c;
    cin>>a;
    
    cout<<"Enter character you want to replace"<<endl;
    cin>>b;
    cout<<"Enter character to insert in replaced position"<<endl;
    cin>>c;
    call(a,b,c);
    cout<<a;
}
