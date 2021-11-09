#include<iostream>
using namespace std;
void call(char a[]){
    if(a[0]=='\0'){
        return;
    }
    if(a[0]!='x'){
        call(a+1);
    }
    else{
        int i=1;
        for(;a[i]!='\0';i++){
            a[i-1]=a[i];
        }
        a[i-1]=a[i];
        call(a);
    }
       
}
int main(){
    char a[100];
    cin>>a;
    call(a);
    cout<<a;
    return 0;
}