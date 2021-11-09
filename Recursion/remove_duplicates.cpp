#include<iostream>
using namespace std;
void call(char a[]){
if(a[0]=='\0'){
    return;
}
/*int count=0;
if(a[0]!=a[1]){
    call(a+1);
}
else{
    char f=a[0];
    for(int i=0;a[i]==f;i++){
        count++;
    }
    int i=1;
    for(;a[i]!='\0';i++){
       if(a[i]!=f){
           a[i-count+1]=a[i];
       }
    }
    for(int i=1;a[i]!='\0';i++){
        a[]
    }
    call(a);
}
*/
if(a[0]==a[1]){
    int i=0;
    while(a[i]!='\0'){
        a[i]=a[i+1];
        i++;
    }
    call(a);
}
else{
call(a+1);
}






}
int main(){
    char a[100];
    cin>>a;
    call(a);
    cout<<a;
}